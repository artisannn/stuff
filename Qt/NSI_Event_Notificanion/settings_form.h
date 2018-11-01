#ifndef SETTINGS_FORM_H
#define SETTINGS_FORM_H
#include <QDialog>
#include "notification_modes.h"
#include <QTime>



namespace Ui {
class Settings_Form;
}
class Settings_Form : public QDialog
{
    Q_OBJECT

public:
    explicit Settings_Form(QTime interval, Notifications_mode, QWidget *parent = 0);
    Notifications_mode get_notification_mode();
    QTime get_notifications_interval();
    ~Settings_Form();
private:
    Ui::Settings_Form *ui;
};

#endif // SETTINGS_FORM_H
