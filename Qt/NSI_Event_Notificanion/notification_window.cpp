#include "notification_window.h"
#include "ui_Notification_window.h"

No_ntfns_label::No_ntfns_label(const QString text, QWidget* parent) :
    QLabel(text,parent)
{
    this->setStyleSheet(QString("font-size: 42px;color: grey"));
    this->setAlignment(Qt::AlignCenter);
}

void No_ntfns_label::free_instance()
{
    delete this;
}

bool No_ntfns_label::is_exist()
{
    return _instance;
}

No_ntfns_label* No_ntfns_label::_instance = nullptr;

No_ntfns_label *No_ntfns_label::instance()
{
    if (!_instance)
        _instance = new No_ntfns_label(QString("Для Вас нет новых оповещений"));
    return _instance;
}

No_ntfns_label::~No_ntfns_label()
{
    _instance = nullptr;
}




Notification_window::Notification_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Notification_window),
    hide_flag(true),
    monitor_stop_flag(false),
    show_closing_message(true)
{
    ui->setupUi(this);
    settings = new QSettings ("NSI_Event_Notifications_settings.ini", QSettings::IniFormat, this);
    load_settings();
    ui->gridLayout_2->setAlignment(ui->verticalLayout,Qt::AlignTop);
    prepare_tray_icon();
}// В конструкторе не запускается больинство служб или функци (такие как init() или connect_to_db()). Они запускаются снаружи, отдельно, из функции main()

/* Если приложение запускается самостоятельно, без VisiData, то запускать его нужно с передачей параметров коннекта.
 * QOCI 192.168.16.44 green maket_msdu_2015_1 maket - аргументы коммандной строки(пример)*/
bool Notification_window::connect_to_db(const char *Driver, const char *HostName, const char *DatabaseName,
                                        const char *UserName, const char *Password)
{
    db = QSqlDatabase::addDatabase(Driver);/*"QOCI"*/
    if(!db.isValid())
    {
        QMessageBox::warning(this,"NSI_Event_Notificanion",
        "<h4>Введен некорректный драйвер!</h4>\nДрайвер:\n\""
                             +QString(Driver)+
                             "\"\nТакого соединения не существует.\n"
                             +"Это приложение можно запускать только с передачей параметров соединения, либо через прилжение M VisiData");
        return false;
    }
    db.setHostName(HostName);/*"192.168.16.44"*/
    db.setDatabaseName(DatabaseName);/*"green"*/
    db.setUserName(UserName);/*"maket_msdu_2015_1"*/
    db.setPassword(Password);   /*"maket"*/
    if(!db.open())
    {
        QMessageBox::warning(this,"NSI_Event_Notificanion",
        "<h4>Не удалось подключиться к базе данных!</h4>\nКод ошибки:\n"
                             +db.lastError().databaseText());
        return false;
    }
    else
    {
        load_settings();
        return true;
    }
}

void Notification_window::init()
{
    QSqlQuery Select_query(db);
    Select_query.prepare("select mausr_user_id, mausr_description from ma_user where mausr_name = :mausr_name/*'maket_msdu_2015_1'*/");
    Select_query.bindValue(":mausr_name",db.userName());
    if (Select_query.exec() && Select_query.next())
    {
        user_id = Select_query.value("mausr_user_id").toInt();
        user_name = Select_query.value("mausr_description").toString();
    }
    else
        QMessageBox::warning(this,"Не удалось выгрузить данные пользователя из базы данных", Select_query.lastError().text());

    fill_the_main_window();
    make_total_ntfs_string();

    if (notifications.empty())
    {
        ui->verticalLayout->addWidget(No_ntfns_label::instance());
        trayIcon->setIcon(QIcon(":/icons/alert_lamp_off.ico"));
        ui->gridLayout_2->setAlignment(ui->verticalLayout,Qt::AlignCenter);
    }
    else
    {
        trayIcon->setIcon(QIcon(":/icons/alert_lamp_on.ico"));
        this->setWindowTitle(application_name + ": " + user_name +", у Вас "+total_ntfs_string);
    }
    trayIcon->show();// Повесили иконку на системный трей

    prepare_the_monitor();      /*   комментируем - два  */
    tell_user_obout_total_ntfs();
}

void Notification_window::prepare_tray_icon()
{
    trayIcon = new QSystemTrayIcon(this);
    menu = new QMenu(this);
    refresh_now = new QAction(tr("Обновить список событий"),this);
    expand_window = new QAction(tr("Развернуть окно"),this);
    quit = new QAction(tr("Выход"),this);
    open_settings = new QAction(tr("Настройки"),this);
    refresh_now->setShortcut(QKeySequence("F5"));
    this->addAction(refresh_now);
    connect(refresh_now,SIGNAL(triggered()),this,SLOT(refresh_ntfs_list()));
    connect(expand_window,SIGNAL(triggered()),this,SLOT(show_me()));
    connect(quit,SIGNAL(triggered()),this,SLOT(close_this_app()));
    connect(open_settings,SIGNAL(triggered()),this,SLOT(open_settings_form()));
    menu->addAction(refresh_now);
    menu->addAction(expand_window);
    menu->addAction(open_settings);
    menu->addAction(quit);
    trayIcon->setContextMenu(menu);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void Notification_window::fill_the_main_window()
{
    bool success =false;
    QSqlQuery Select_query(db);
    Select_query.prepare("select distinct e.eve_id, eu.evu_id, to_char(e.eve_date,'dd.mm.yyyy HH24:MI:SS') as evedate,e.eve_num, g.ngge_name as event_name, e.detail_info info, eu.mausr_user_id, e.eve_date,evu_confirm from event e, event_user eu, nsi_g_general g where e.eve_id = eu.eve_id and e.eve_type_id = g.ngge_id and eu.evu_confirm = '0' and eu.mausr_user_id = :mausr_user_id/*22005*/ ORDER BY e.eve_num");
    Select_query.bindValue(":mausr_user_id", user_id);
    Select_query.setForwardOnly(true);
    if (Select_query.exec())
    {
        while(Select_query.next()/* && 0 раскомментировать - четыре */)
        {
            this->add_item(current_ntbx = new Notification_Box(Select_query.value("EVE_NUM").toString(),
                                           Select_query.value("EVENT_NAME").toString(),
                                           Select_query.value("EVEDATE").toString(),
                                           Select_query.value("INFO").toString(),
                                           Select_query.value("EVU_ID").toLongLong()),
                                           this);
            success =true;
        }
        if (!success)
        {
            qDebug()<<"Не удалось обратиться к результату SQL запроса :" <<Select_query.lastError().text();
        }
    }
    else
        QMessageBox::warning(this,"Ошибка при выполнении запроса", Select_query.lastError().text());
}

void Notification_window::prepare_the_monitor()
{
    thread = new QThread();
    monitor = new New_ntfns_monitor(db,this);
    monitor->moveToThread(thread);
    connect(thread,SIGNAL(started()),monitor,SLOT(process()));
    thread->start();
    connect(monitor,SIGNAL(new_notification(long long)),this,SLOT(add_item(long long)));
}

void Notification_window::tell_user_obout_total_ntfs()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    if (!notifications.empty())
    {
        trayIcon->showMessage(application_name,
                              "У Вас "+total_ntfs_string,
                              icon,
                              2000);
    }
    else
        trayIcon->showMessage(application_name,
                              "У Вас нет новых оповещений",
                              icon,
                              2000);
}

void Notification_window::add_item(Notification_Box *wgt, bool show_balloon_msg)
{
    if (No_ntfns_label::is_exist())
    {
        trayIcon->setIcon(QIcon("icons/alert_lamp_on.ico"));
        No_ntfns_label * Singleton = No_ntfns_label::instance();
        Singleton->free_instance();
        ui->gridLayout_2->setAlignment(ui->verticalLayout,Qt::AlignTop);
    }
    ui->verticalLayout->addWidget(wgt);
    notifications.insert(wgt->get_event_user_id(),wgt);
    connect(wgt,SIGNAL(i_was_pressed(Notification_Box *)),this,SLOT(remove_item(Notification_Box *)));
    connect(wgt,SIGNAL(my_link_clicked(Notification_Box*)),this,SLOT(open_event_doc_form(Notification_Box*)));
    if (show_balloon_msg)
    {
        if(state == Notifications_mode::Expand_window)
        {
            show_me();
        }
        if(state == Notifications_mode::Baloon_msg)
        {
            QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
            trayIcon->showMessage("Для Вас новое оповещение","Событие №"+wgt->get_event_num()+"\n"+wgt->get_event_name()+":"+"\n"+wgt->get_event_info(),icon,2000);
        }
    }
    make_total_ntfs_string();
    this->setWindowTitle(application_name + ": " + user_name +", у Вас "+total_ntfs_string);
    item_added_condition.wakeAll();
}

void Notification_window::destroy_item(Notification_Box *wgt) //Физически удаляем виджет из окна
{
    notifications.take(wgt->get_event_user_id());
    if(notifications.empty())
    {
        trayIcon->setIcon(QIcon("icons/alert_lamp_off.ico"));
        No_ntfns_label * Singleton = No_ntfns_label::instance();
        ui->verticalLayout->addWidget(Singleton);
        ui->gridLayout_2->setAlignment(ui->verticalLayout,Qt::AlignCenter);
    }
    make_total_ntfs_string();
    this->setWindowTitle(application_name + ": " + user_name +", у Вас "+total_ntfs_string);
}

void Notification_window::load_settings()
{
    if(db.isOpen()) // Грузим насторйки для каждого пользователя индивидуально(если подключились к базе)
    {
        settings->beginGroup(db.userName());
            application_name = settings->value("CAPTION").toString();
            notifications_interval = settings->value("notifications_interval").toTime();
            if (notifications_interval==QTime(0,0,0)) // Делаем невозможным установку интервала равной 00:00:00. Минимум 00:00:10
            {
                notifications_interval.setHMS(0,0,10);
                qDebug()<<"Задан нулевой интервал оповещения";
                qDebug()<<"interval: "<<notifications_interval;
            }
            state = settings->value("notifications_mode").value<Notifications_mode>();
        settings->endGroup();
    }
    else // Если не подключились, то грузим общие настройки на всех
    {
        notifications_interval = settings->value("notifications_interval").toTime();
        state = settings->value("notifications_mode").value<Notifications_mode>();
    }
}

void Notification_window::save_settings()
{
    if(db.isOpen())
    {
        settings->beginGroup(db.userName());
            settings->setValue("CAPTION","Информационная панель АСДУ ЕСГ");
            settings->setValue("notifications_interval",notifications_interval);
            settings->setValue("notifications_mode",state);
        settings->endGroup();
    }
    else
    {
        settings->setValue("notifications_interval",notifications_interval);
        settings->setValue("notifications_mode",state);
    }
}

void Notification_window::make_total_ntfs_string()
{
    total_ntfs_string = QString::number(notifications.count())+
               correct_ending_of_word(notifications.count()," нов","ое","ых","ых")+
               correct_ending_of_word(notifications.count()," событи","е","я","й");
}

void Notification_window::remove_item(Notification_Box * ntbx) // Помечаем прочитанным в базе и удаляем виджет
{
    QSqlQuery q(db);
    q.prepare("UPDATE event_user SET evu_confirm = '1', evu_confirm_date = :current_date WHERE evu_id = :event_user_id");
    q.bindValue(":current_date",QDateTime::currentDateTime());
    q.bindValue(":event_user_id",ntbx->get_event_user_id());
    if(db.transaction())
    {
        if (q.exec())
        {
            q.finish();
            if(!db.commit())
            {
                QMessageBox::warning(this,"Транзакция не была успешно закоммичена!",
                                          "Не удалось отметить событие: №"+ntbx->get_event_num()+
                                          " как прочитанное в связи с неудачным завершением транзакции."
                                          +db.lastError().databaseText());
                if(!db.rollback())
                {
                    QMessageBox::warning(this,"Неудачный откат транзакции!",db.lastError().databaseText());
                }
            }
        }
        else
        {
            QMessageBox::warning(this,"Событие не отмечено как прочитанное","Не удалось отметить событие: №"+ntbx->get_event_num()+
                         " как прочитанное в связи с неудачным завершением транзакции./n"+q.lastError().databaseText());
            if(!db.rollback())
            {
                QMessageBox::warning(this,"Неудачный откат транзакции!",db.lastError().databaseText());
            }
        }
    }
    else
        QMessageBox::warning(this,"Танзакция не была успешно открыта!",db.lastError().databaseText());
    this->destroy_item(ntbx);
}

void Notification_window::add_item(long long new_item_id)// Перегруженный метод добавляющий виджет оповещения по его ID
{
    QSqlQuery Select_query(db);

    Select_query.prepare("select distinct eu.evu_id, to_char(e.eve_date,'dd.mm.yyyy HH24:MI:SS') as evedate, e.eve_num,g.ngge_name as event_name, e.detail_info info from event e, event_user eu, nsi_g_general g where e.eve_id = eu.eve_id and e.eve_type_id = g.ngge_id and eu.evu_id = :event_user_id");
    Select_query.bindValue(":event_user_id",new_item_id);
    Select_query.setForwardOnly(true);
    if (Select_query.exec())
    {
        Select_query.next();
        add_item(new Notification_Box(Select_query.value("EVE_NUM").toString(),
                                      Select_query.value("EVENT_NAME").toString(),
                                      Select_query.value("EVEDATE").toString(),
                                      Select_query.value("INFO").toString(),
                                      Select_query.value("EVU_ID").toLongLong(),
                                      this),
                                  true);
    }
}

void Notification_window::add_ntbx_by_btn_click() // Слот для добавления виджета по кнопке, временный. Потом удалить!
{
    qDebug()<<"add_ntbx_by_btn_click";
    static long long id=0;
    Notification_Box * Nnboxxxx = new Notification_Box (QString::number(id),QString("Nnbox"),QString("datadtatdtatda"),QString("infoinfoinfo"),id);
    id++;
    this->add_item(Nnboxxxx,true);
}

void Notification_window::open_event_doc_form(Notification_Box *ntbx) // Слот, который обрабатывает нажатие на гиперссылку, пока в виде заглушки.
{
    QMessageBox::information(this,ntbx->get_event_name(),ntbx->get_event_info());
}

    void Notification_window::close_this_app()
    {
        hide_me();
        monitor_stop_flag = true;
        go_further_condition.wakeAll();
        thread->exit(0); /*   комментируем  - */
        thread->wait();  /*       раз         */
        trayIcon->hide();
        delete trayIcon;
        delete thread;
        QCoreApplication::quit();
    }

    void Notification_window::iconActivated(QSystemTrayIcon::ActivationReason reason)
    {
        if (reason == QSystemTrayIcon::ActivationReason::Trigger)
        {
            if(hide_flag)
            {
                show_me();
            }
            else
            {
                hide_me();
            }
        }
    }

    void Notification_window::open_settings_form()
    {
        settingsForm = new Settings_Form(notifications_interval,state,this);
        if(settingsForm->exec() == QDialog::Accepted)
        {
            notifications_interval = settingsForm->get_notifications_interval();
            state = settingsForm->get_notification_mode();
        }
        delete settingsForm;
    }

    void Notification_window::refresh_ntfs_list()
    {
        go_further_condition.wakeAll();
    }

    void Notification_window::hide_me()
    {
        this->hide();
        hide_flag = true;
    }

    void Notification_window::show_me()
    {
        this->show();
        if(this->isMinimized())
        {
            this->showNormal();
        }
        this->raise();
        this->activateWindow();
        hide_flag = false;
    }

    void Notification_window::closeEvent(QCloseEvent *event)
    {
        if(!this->isHidden())
        {
            event->ignore();
            this->hide();
            hide_flag = true;

            QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
            if(show_closing_message)
            {
                trayIcon->showMessage(application_name,
                                      trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                             "развернуть окно приложения, щелкните по иконке приложения в трее. "
                                             "Завершить работу приложения можно по правой кнопке"),
                                      icon,
                                      2000);
                show_closing_message = false;
            }
        }
    }

    void Notification_window::changeEvent(QEvent *event)
    {
        QWidget::changeEvent(event);
        if (event -> type() == QEvent::WindowStateChange)
        {
            if (isMinimized())
            {
                this -> hide();
                hide_flag = true;
            }
        }
    }

    QString Notification_window::correct_ending_of_word(int number, const char* word,
                                                         const char* ending_for_single,
                                                         const char* ending_for_two,const char* ending_for_five) /* Возвращает слово с правильным окончанием*/
    {
        if (number%100>4 && number%100<20)
            return QString (word)+ending_for_five;
        if (number%10>1 && number%10<5)
            return QString (word)+ending_for_two;
        if (number%10==1)
            return QString (word)+ending_for_single;
        return QString (word)+ending_for_five;
    }

    Notification_window::~Notification_window()
    {
        save_settings();
        delete ui;
    }









void New_ntfns_monitor::process()
{
    QSqlQuery _query(_db);
    _query.prepare("select distinct eu.evu_id from event e, event_user eu, nsi_g_general g where e.eve_id = eu.eve_id and e.eve_type_id = g.ngge_id and eu.evu_confirm = '0' and eu.mausr_user_id = :mausr_user_id/*22005*/  ");
    _query.setForwardOnly(true);
    long long _event_user_id;
    while(!_window->monitor_stop_flag)
    {
        if (_query.exec())
        {
//            int i = 0;
            while(_query.next())
            {
                _event_user_id = _query.value("EVU_ID").toLongLong();
                if(!_window->notifications.contains(_event_user_id))
                {
                    _window->mutex.lock();
                    emit new_notification(_event_user_id);
                    _window->item_added_condition.wait(&this->_window->mutex);
                    _window->mutex.unlock();
                    QThread::msleep(500);
                }
//                i++;
            }
        }
        unsigned long sleeping_time(_window->notifications_interval.minute()*60000+_window->notifications_interval.second()*1000);
        qDebug()<<"Минуты : "<<_window->notifications_interval.minute()<<", секунды"<<_window->notifications_interval.second();
        qDebug()<<"Засыпаем на "<<_window->notifications_interval.minute()*60000+_window->notifications_interval.second()*1000<<" миллисекунд";
        _window->mutex.lock();
        _window->go_further_condition.wait(&this->_window->mutex,sleeping_time);
        _window->mutex.unlock();
    }
}

New_ntfns_monitor::New_ntfns_monitor(QSqlDatabase monitoring_db, Notification_window * window)
{
    _db = monitoring_db;
    _window = window;
}

New_ntfns_monitor::~New_ntfns_monitor()
{
}


