#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    window(new Ui::MainWindow)
{
    settings = new QSettings ("settings.ini", QSettings::IniFormat, this);
//    save_settings();
    load_settings();
    qDebug()<<"ini params :";
    qDebug()<<"unload_scen_GUID :" << unload_scen_GUID;
    qDebug()<<"load_sscen_GUID :" << load_sscen_GUID;
    qDebug()<<"proj_ABBR :" << proj_ABBR;
    window->setupUi(this);
        connect(window->action_connect,SIGNAL(triggered(bool)),this,SLOT(connect_to_db(bool)));
        connect(window->action_exit,SIGNAL(triggered(bool)),this,SLOT(close()));
        connect(window->action_refresh,SIGNAL(triggered()),this,SLOT(action_refresh_triggered()));
        connect(window->action_search,SIGNAL(triggered()),this,SLOT(action_search_triggered()));
    window->menuBar->actions().at(0)->setStatusTip("Не подключено");
    window->action_connect->setStatusTip("Не подключено");
    window->action_refresh->setStatusTip("Обновляет отображение списка документов, лежащих в базе");
    window->action_exit->setStatusTip("Закрывает приложение");
    window->action_load->setEnabled(false);
    window->action_unload->setEnabled(false);
    window->action_refresh->setEnabled(false);
    window->action_search->setEnabled(false);
    window->treeWidget->setHeaderLabel("");
    window->treeWidget_2->setHeaderLabel("");
}

void MainWindow::connect_to_db(bool checked)
{
    if (checked)
    {
        window->plainTextEdit->appendPlainText("ini params :");
        window->plainTextEdit->appendPlainText("unload_scen_GUID : " + unload_scen_GUID);
        window->plainTextEdit->appendPlainText("load_sscen_GUID : " + load_sscen_GUID);
        window->plainTextEdit->appendPlainText("proj_ABBR : " + proj_ABBR);
        connect_dialog = new Dialog(this);
        connect_dialog->exec();
        if (connect_dialog->state == Dialog::Ok)
        {
            window->plainTextEdit->appendPlainText("ОК. Подключаемся.");
            dbType = connect_dialog->get_server_type();
            if (dbType == "PostgreSQL")
            {
                driver = "QPSQL";
                db = QSqlDatabase::addDatabase(driver);
            }
            else if (dbType == "Oracle")
            {
                driver = "QOCI";
                db = QSqlDatabase::addDatabase(driver);
            }
            /* else Тут нужно реализовать отправку ссобщения в статус бар о том что с соединением что-то не так */
            db.setHostName(host = connect_dialog->get_host_name());
            db.setDatabaseName(server = connect_dialog->get_server_name());
            db.setUserName(user = connect_dialog->get_user_name());
            db.setPassword(password = connect_dialog->get_password());
            bool ok = db.open();
            if(ok)
            {
                window->plainTextEdit->appendPlainText("connected!");
                qDebug()<<"connected!";
                window->action_connect->setChecked(true);
                window->menuBar->actions().at(0)->setStatusTip("Подключено к "+dbType);
                window->action_connect->setStatusTip("Подключено к "+dbType);
                window->action_connect->setText("Разъединить");
                prepare_left_treeview();
                window->action_load->setEnabled(true);
                window->action_unload->setEnabled(true);
                window->action_refresh->setEnabled(true);
                window->action_search->setEnabled(true);
                window->plainTextEdit->appendPlainText("dbType : "+dbType);
                window->plainTextEdit->appendPlainText("driver : "+driver);
                window->plainTextEdit->appendPlainText("user : "+user);
                window->plainTextEdit->appendPlainText("db : "+server);
                QString connect_params(QString ("db: \"%1\", server: \"%2\", user: \"%3\"").arg(dbType).arg(server).arg(user));
                this->setWindowTitle("MetaData " +connect_params);
                window->action_connect->setStatusTip("Подключено к " + connect_params);
            }
            else
            {
                window->plainTextEdit->appendPlainText("not connected!");
                qDebug()<<"not connected";
                window->menuBar->actions().at(0)->setStatusTip(db.lastError().text());
                window->action_connect->setStatusTip(db.lastError().text());
                window->action_connect->setChecked(false);
                QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
            }
            if (connect_dialog->saving_connection_params_is_allowed())
            {
                connect_dialog->save_settings();
            }
        }
        else
            window->action_connect->setChecked(false);
        delete connect_dialog;
    }
    if (!checked)
    {
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
        window->plainTextEdit->appendPlainText("connection was closed");
        qDebug()<<"connection was closed";
        window->menuBar->actions().at(0)->setStatusTip("Не подключено");
        window->action_connect->setStatusTip("Не подключено");
        window->action_connect->setText("Подключить к БД");
        window->treeWidget->clear();
        window->treeWidget_2->clear();
        window->action_load->setEnabled(false);
        window->action_unload->setEnabled(false);
        window->action_refresh->setEnabled(false);
        window->action_search->setEnabled(false);
    }
}

void MainWindow::on_pushButton_clicked() /*   >   */
{
    QTreeWidgetItemIterator it(window->treeWidget,QTreeWidgetItemIterator::Checked);
    if (*(it))
    {    QStringList lst;
        lst<<""<<"Документ"<<"Дата создания"<<"Дата изменения"<<"ID Документа";
        window->treeWidget_2->setHeaderLabels(lst);
        window->treeWidget_2->setColumnWidth(0,40);
        QList<QTreeWidgetItem*> selectedItems;
        while (*(it))
        {
            MyQTreeWidgetItem * titem=new MyQTreeWidgetItem(window->treeWidget_2);
            titem->setFlags(titem->flags()|Qt::ItemIsUserCheckable);
            titem->setCheckState(0,Qt::Unchecked);
            titem->setText(1,(*it)->text(1));
            titem->setText(2,(*it)->text(2));
            titem->setData(2,Qt::UserRole,(*it)->data(2,Qt::UserRole).toDateTime());// Для сортировки по дате-времени
            titem->setText(3,(*it)->text(3));
            titem->setData(3,Qt::UserRole,(*it)->data(3,Qt::UserRole).toDateTime());// Для сортировки по дате-времени
            titem->setText(4,(*it)->text(4));
            selectedItems.append(*it);
            ++it;
        }
        foreach ( QTreeWidgetItem * item, selectedItems )
            delete item;
    }
}

void MainWindow::on_pushButton_3_clicked() /*   <   */
{
    QTreeWidgetItemIterator it(window->treeWidget_2,QTreeWidgetItemIterator::Checked);
    if (*(it))
    {
        QStringList lst;
        lst<<""<<"Документ"<<"Дата создания"<<"Дата изменения"<<"GUID";
        window->treeWidget->setHeaderLabels(lst);
        QList<QTreeWidgetItem*> selectedItems;
        while (*(it))
        {
            QTreeWidgetItem * titem=new QTreeWidgetItem(window->treeWidget);
            titem->setFlags(titem->flags()|Qt::ItemIsUserCheckable);
            titem->setCheckState(0,Qt::Unchecked);

            titem->setText(1,(*it)->text(1));
            titem->setText(2,(*it)->text(2));
            titem->setText(3,(*it)->text(3));
            titem->setText(4,(*it)->text(4));
            selectedItems.append(*it);
            ++it;
        }
        foreach ( QTreeWidgetItem * item, selectedItems )
            delete item;
    }
}

void MainWindow::on_action_unload_triggered() // Этот слот соединен с Action "action_unload", т.к. соединял через дизайнер, то непосредственного коннекта в коде нет и где он понятия не имею (неисключено что где-то в недрах mainwindow.ui)
{
    QTreeWidgetItemIterator it(window->treeWidget_2);
    if (*(it))
    {
        QMap<QString,QString> dfParams;
        saving_file_name = QFileDialog::getSaveFileName(this,"Выберите файл, куда будем сохранять","C:\\df","*.xml");
        if (saving_file_name.isNull())
        {
            return;
        }
        else
        {
            dfParams.insert("file_name",saving_file_name);
        }
        list_id.clear();
        QString name_list;
        prepare_List_id_and_Name_list(it,list_id,name_list);
        dfParams.insert("list_id",list_id);
        dfParams.insert("password",password);
        dfParams.insert("driver",driver);
        dfParams.insert("user",user);
        dfParams.insert("db",server);
        dfParams.insert("host",host);
        qDebug()<<"password :"<<password;
        qDebug()<<"driver :"<<driver;
        qDebug()<<"user :"<<user;
        qDebug()<<"db :"<<server;
        qDebug()<<"list_id :"<<list_id;
        qDebug()<<"name_list :"+name_list;
        qDebug()<<"Запускаем Dfusion...";
        window->plainTextEdit->appendPlainText("Запускаем Dfusion...");
        df = new QDF (proj_ABBR);
        if (!df)
        {
            window->plainTextEdit->appendPlainText("Ошибка при создании объекта QDF!");
            qDebug()<<"Ошибка при создании объекта QDF!";
            QMessageBox::warning(0,tr("Ошибка"),QString(tr("Ошибка при создании объекта QDF! Проект :\"")+df->projectAbbr+"\".\n\r"));
            return;
        }
        if (df->startScenario(unload_scen_GUID,dfParams))
        {
            if(df->state == QDF::dfSuccess)
            {
                window->plainTextEdit->appendPlainText("Сценарий выполнился успешно: " + df->info);
                qDebug()<<"Сценарий выполнился успешно";
                QString success_message("<h4>Выгрузка прошла успешно!</h4>  Было успешно выгружено "
                                        + QString::number(window->treeWidget_2->topLevelItemCount())
                                        +" "
                                        + correct_ending_of_word(window->treeWidget_2->topLevelItemCount(),"документ")
                                        +" :"
                                        + name_list );
                clear_right_treeview();
                QMessageBox::information(this,"Info", success_message);
            }
            if(df->state == QDF::dfError)
            {
                window->plainTextEdit->appendPlainText(df->error);
                qDebug()<<"Сценарий НЕ выполнился успешно";
                QMessageBox::warning(0,tr("Ошибка"),QString(tr("Произошла ошибка при выполнении сценария! Проект :\"")+df->projectAbbr+"\".\n\r"+df->error));
            }
        }
        else
        {
            window->plainTextEdit->appendPlainText("Сценарий не запустился: "+df->error);
            qDebug()<<"Сценарий НЕ запустился";
            QMessageBox::warning(0,tr("Ошибка"),QString(tr("Сценарий не запустился! Проект :\"")+df->projectAbbr+"\".\n\r"+df->error));
        }
        delete df;
    }
    else
        QMessageBox::information(this,"Ничего не выбрано",
                      "<h4>Вы ничего не выбрали.</h4>  Выберите элементы из формы слева, которые нужно выгрузить на диск, <br/>затем нажмите на кнопку \">\". Потом можно будет выгружать.");
}

void MainWindow::on_action_load_triggered()
{
    loading_file_name = QFileDialog::getOpenFileName(this,tr("Выберите файл, откуда будем качать"),tr("C:\\df"),tr("*.xml"));
    if (loading_file_name.isNull())
    {
        qDebug()<<"Нажали на Cancel";
        return;
    }
    QMap<QString,QString> dfParams;
    if (loading_file_name.isEmpty())
    {
        QMessageBox::information(nullptr,"Не указан путь загружаемого файла",
                      "<h4>Укажите путь загружаемого файла!</h4>");
        return;
    }
    dfParams.insert("file_name",loading_file_name);
    dfParams.insert("password",password);
    dfParams.insert("driver",driver);
    dfParams.insert("user",user);
    dfParams.insert("db",server);
    dfParams.insert("host",host);
    window->plainTextEdit->appendPlainText("file_name"+loading_file_name);
    qDebug()<<"password :"<<password;
    qDebug()<<"driver :"<<driver;
    qDebug()<<"user :"<<user;
    qDebug()<<"db :"<<server;
    qDebug()<<"Запускаем Dfusion...";
    window->plainTextEdit->appendPlainText("Запускаем Dfusion...");
    df = new QDF (proj_ABBR);
    if (!df)
    {
        window->plainTextEdit->appendPlainText("Ошибка при создании объекта QDF!");
        qDebug()<<"Ошибка при создании объекта QDF!";
        QMessageBox::warning(0,tr("Ошибка"),QString(tr("Ошибка при создании объекта QDF! Проект :\"")+df->projectAbbr+"\".\n\r"));
        return;
    }
    else
        if (df->startScenario(load_sscen_GUID,dfParams))
        {
            if(df->state == QDF::dfSuccess)
            {
                window->plainTextEdit->appendPlainText(df->info);
                qDebug()<<"Сценарий выполнился успешно";
            }
            if(df->state == QDF::dfError)
            {
                window->plainTextEdit->appendPlainText(df->error);
                qDebug()<<"Сценарий НЕ выполнился успешно";
                QMessageBox::warning(0,tr("Ошибка"),QString(tr("Произошла ошибка при выполнении сценария! Проект :\"")+df->projectAbbr+"\".\n\r"+df->error));
            }
        }
        else
        {
            window->plainTextEdit->appendPlainText("Сценарий не запустился: "+df->error);
            qDebug()<<"Сценарий НЕ запустился";
            QMessageBox::warning(0,tr("Ошибка"),QString(tr("Сценарий не запустился! Проект :\"")+df->projectAbbr+"\".\n\r"+df->error));
        }
    delete df;
}

void MainWindow::action_refresh_triggered()
{
    prepare_left_treeview();
//    window->treeWidget_2->clear();
    window->plainTextEdit->appendPlainText("Список документов обновлен");
}

void MainWindow::action_search_triggered()
{
    bool ok;
    QString search_string = QInputDialog::getText(this,
                                                      "Поиск по документам",
                                                      "Что ищем?",
                                                      QLineEdit::Normal,
                                                      "",
                                                      &ok);
    if (ok)
    {
        QList<QTreeWidgetItem*> result = window->treeWidget->findItems(search_string,Qt::MatchContains,1);
        QString result_message("Найдено "
                                + QString::number(result.length())
                                +" "
                                + correct_ending_of_word(result.length(),"документ"));
        window->plainTextEdit->appendPlainText(result_message);
        qDebug()<<"found items : " << result;


        for (int i = 0; i< window->treeWidget->topLevelItemCount(); i++)
        {
            QTreeWidgetItem* tree_item = window->treeWidget->topLevelItem(i);
                for(int j = 0; j< result.length(); j++)
                {
                    if(tree_item==result.at(j))
                    {
                        qDebug()<<tree_item->data(1,Qt::DisplayRole).toString()<<"="<<result.at(j)->data(1,Qt::DisplayRole).toString();
                        window->treeWidget->topLevelItem(i)->setHidden(false);
                        break;
                    }
                    else
                    {
                        window->treeWidget->topLevelItem(i)->setHidden(true);
                    }
                }
         }
    }
    else return;
}

QString MainWindow::correct_ending_of_word(int number, const QString & word) /* Возвращает слово с правильным окончанием*/
{
    if (number%100>4 && number%100<20)
        return word+"ов";
    if (number%10>1 && number%10<5)
        return word+"а";
    if (number%10==1)
        return word+"";
    return word+"ов";
}

void MainWindow::prepare_List_id_and_Name_list(QTreeWidgetItemIterator &it, QString & list_id, QString & list_name_doc)
{
    for( ; *(it); ++it )
    {
        if (list_id.isEmpty())
        {
            list_id.append((*it)->text(4));
            list_name_doc.append( QString("<pre>•     %1<br/>").arg((*it)->text(1)));
            continue;
        }
        list_id.append(",");
        list_id.append((*it)->text(4));
        list_name_doc.append(QString("•     %1<br/>").arg((*it)->text(1)));
    }
    list_name_doc.append("</pre>");
}

bool MainWindow::prepare_left_treeview()
{
    QStringList lst;
    lst<<""<<"Документ"<<"Дата создания"<<"Дата изменения"<<"ID Документа";
    QSqlQuery q(db);
    q.prepare("select mddoc_doc_id,mddoc_doc_name,mddoc_create_date,mddoc_modify_date,mddoc_guid"
           " from md_doc");
    window->treeWidget->clear();
    window->treeWidget->setHeaderLabels(lst);
    window->treeWidget->setColumnWidth(0,40);
    window->treeWidget->setSortingEnabled(true);
    q.setForwardOnly(true);
    if (q.exec())
    {
        if (q.first())
        {
            do{
              MyQTreeWidgetItem * titem = new MyQTreeWidgetItem(window->treeWidget);
              qDebug()<<q.value("mddoc_doc_name").toString();
              titem->setFlags(titem->flags()|Qt::ItemIsUserCheckable);
              titem->setCheckState(0,Qt::Unchecked);
              titem->setText(1,q.value("mddoc_doc_name").toString());
              titem->setText(2,q.value("mddoc_create_date").toDateTime().toString("dd.MM.yyyy hh:mm:ss"));
              titem->setData(2,Qt::UserRole,q.value("mddoc_create_date").toDateTime());// Для сортировки по дате-времени
              titem->setText(3,q.value("mddoc_modify_date").toDateTime().toString("dd.MM.yyyy hh:mm:ss"));
              titem->setData(3,Qt::UserRole,q.value("mddoc_modify_date").toDateTime());// Для сортировки по дате-времени
              titem->setText(4,q.value("mddoc_doc_id").toString());
             }while (q.next());
            qDebug()<<"number of items in treeWidget : " << window->treeWidget->topLevelItemCount();
            return true;
        }
        else
        {
            window->plainTextEdit->appendPlainText("Не удалось обратиться к результату запроса SQL к MD_DOC : " + q.lastError().text());
            qDebug()<<"Не удалось обратиться к результату запроса SQL к MD_DOC" <<q.lastError().text();
            return false;
        }
    }
    else
    {
        window->plainTextEdit->appendPlainText("Ошибка при выполнении запроса SQL к MD_DOC : " + q.lastError().text());
        qDebug()<<"Ошибка при выполнении запроса SQL к MD_DOC" <<q.lastError().text();
        return false;
    }
}

void MainWindow::clear_right_treeview() /* Очищает правое поддерево, добавляя его элементы в правое. Восстанавливает первоначальный вид, в общем*/
{
    qDebug()<<"selected items : " ;
    for (int i = 0; i< window->treeWidget_2->topLevelItemCount(); i++)
    {
        window->treeWidget_2->topLevelItem(i)->setCheckState(0,Qt::CheckState::Checked);
        qDebug()<< window->treeWidget_2->topLevelItem(i)->text(1);
    }
    on_pushButton_3_clicked();
}

void MainWindow::load_settings()
{
    proj_ABBR = settings->value("project_abbreviation").toString();
    load_sscen_GUID = settings->value("load_scenario_GUID").toString();
    unload_scen_GUID = settings->value("unload_scenario_GUID").toString();
    qDebug()<<"load_settings()";
}

MainWindow::~MainWindow()
{
    delete window;
}

//void MainWindow::save_settings()
//{
//    settings->setValue("project_abbreviation","Z");
//    settings->setValue("unload_scenario_GUID","{A34F33AA-3AE2-42F1-BAEB-AB6896D780C0}");
//    settings->setValue("load_super_scenario_GUID","{1C86BC3F-C206-46A9-B6C3-CC91C5C3439D}");
//    qDebug()<<"save_settings()";
//}



