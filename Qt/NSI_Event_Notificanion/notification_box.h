#ifndef NOTIFICATION_BOX_H
#define NOTIFICATION_BOX_H
#include <QDebug>
#include <QWidget>
#include <QString>
#include "qxdataconnection.h"

namespace Ui {
class Notification_Box;
}

class Notification_Box : public QWidget
{
    Q_OBJECT
public:
    explicit Notification_Box(QString& event_num =QString(), QString& event_name =QString(),
                              QString& event_date =QString(), QString& event_info = QString(),
                              long long event_user_id = 0, QWidget *parent = nullptr);
    ~Notification_Box();
    long long get_event_user_id();
    QString get_event_num();
    QString get_event_name();
    QString get_event_date();
    QString get_event_info();
private:
    long long _event_user_id;
    QString _event_num;
    QString _event_name;
    QString _event_date;
    QString _event_info;
    Ui::Notification_Box *ui;
private slots:
    void OKbtn_clicked();
    void link_clicked();
signals:
    void i_was_pressed(Notification_Box*);
    void my_link_clicked(Notification_Box*);
};

#endif // NOTIFICATION_BOX_H
