#ifndef NOTIFICATION_WINDOW_H
#define NOTIFICATION_WINDOW_H
#include <QWidget>
#include <QDebug>
#include <QStyle>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QCloseEvent>
#include <QHideEvent>
#include <QVBoxLayout>
#include <QThread>
#include <QSettings>
#include <QWaitCondition>
#include <QMutex>
#include <QTime>
#include <QMessageBox>
#include "notification_box.h"
#include "qxdataconnection.h"
#include "settings_form.h"
#include "notification_modes.h"


namespace Ui {
class Notification_window;
}


class Notification_window : public QWidget
{
    Q_OBJECT

public:
    friend class New_ntfns_monitor;
    explicit Notification_window(QWidget *parent = 0);
    void add_item(Notification_Box *wgt, bool show_balloon_msg = false);
    void destroy_item(Notification_Box *wgt);//потом поменять местами с remove_item
    ~Notification_window();
    bool connect_to_db(const char* Driver, const char* HostName, const char* DatabaseName,
                       const char* UserName, const char* Password);
    void init();
private:
    QMutex mutex;
    QWaitCondition item_added_condition;
    QWaitCondition go_further_condition;
    QSettings * settings;
    Notifications_mode state;
    Q_ENUM(Notifications_mode)
    QTime notifications_interval;
    QMap<long long,Notification_Box*> notifications;
    QSqlDatabase db;
    QString total_ntfs_string;
    Notification_Box * current_ntbx; // потом удалить!!!!
    Ui::Notification_window *ui;
    QSystemTrayIcon* trayIcon;
    QMenu* menu;
    QAction* refresh_now;
    QAction* expand_window;
    QAction* quit;
    QAction* open_settings;
    Settings_Form* settingsForm;
    QThread* thread;
    New_ntfns_monitor * monitor;
    QString user_name;
    QString application_name;
    int user_id;
    QLabel* No_ntfns;
    bool hide_flag;
    bool monitor_stop_flag;
    bool show_closing_message;
    void load_settings();
    void save_settings();
    void make_total_ntfs_string();
    void prepare_tray_icon();
    void fill_the_main_window();
    void prepare_the_monitor();
    void tell_user_obout_total_ntfs();
    QString correct_ending_of_word(int number, const char* word,
                                   const char* ending_for_single,
                                   const char* ending_for_two,const char* ending_for_five);
protected:
    void closeEvent(QCloseEvent * event);
    void changeEvent(QEvent *event);
public slots:
    void add_ntbx_by_btn_click();//add_new_ntbx потом удалить!!!!
    void open_settings_form();

private slots:
    void refresh_ntfs_list();
    void hide_me();
    void show_me();
    void close_this_app();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void remove_item(Notification_Box *);
    void add_item(long long new_item_id);
    void open_event_doc_form(Notification_Box *ntbx);
};

// Фоновая надпись, выводящаяся когда оповещения заканчиваются. Синглтон
class No_ntfns_label : public QLabel
{
    No_ntfns_label(const QString text, QWidget *parent = nullptr);
    static No_ntfns_label * _instance;
    ~No_ntfns_label();
public:
    void free_instance();
    static bool is_exist();
    static No_ntfns_label* instance();
    void add_no_ntfns_label();
    void delete_no_ntfns_label();
};

// Класс отслеживает появление новых оповещений в базе
class New_ntfns_monitor : public QObject
{
    Q_OBJECT
public:
    New_ntfns_monitor(QSqlDatabase monitoring_db,Notification_window*);
    ~New_ntfns_monitor();
private:
    QSqlDatabase _db;
    Notification_window * _window;
public slots:
    void process();
signals:
    void new_notification (long long);
};


#endif // NOTIFICATION_WINDOW_H
