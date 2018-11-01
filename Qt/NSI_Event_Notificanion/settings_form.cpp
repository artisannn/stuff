#include "settings_form.h"
#include "ui_settings_form.h"

Settings_Form::Settings_Form(QTime interval, Notifications_mode mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings_Form)
{
    ui->setupUi(this);
    ui->spinBox->setValue(interval.minute());
    ui->spinBox_2->setValue(interval.second());
    if (mode==Notifications_mode::Expand_window )
    {
        ui->rb_window_mode->setChecked(true);
    }
    if (mode==Notifications_mode::Baloon_msg)
    {
        ui->rb_baloon_msg->setChecked(true);
    }
    if (mode==Notifications_mode::Paint_icon)
    {
        ui->rb_paint_icon->setChecked(true);
    }
}


Notifications_mode Settings_Form::get_notification_mode()
{
    if(ui->rb_window_mode->isChecked())
        return Notifications_mode::Expand_window;
    if(ui->rb_baloon_msg->isChecked())
        return Notifications_mode::Baloon_msg;
    if(ui->rb_paint_icon->isChecked())
        return Notifications_mode::Paint_icon;
}

QTime Settings_Form::get_notifications_interval()
{
    return QTime(0,ui->spinBox->value(),ui->spinBox_2->value());
}

Settings_Form::~Settings_Form()
{
    delete ui;
}

