#include "notification_box.h"
#include "ui_notification_box.h"

Notification_Box::Notification_Box(QString& event_num, QString& event_name, QString& event_date,
                                   QString& event_info, long long event_user_id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Notification_Box)
{
    _event_num = event_num;
    _event_name = event_name;
    _event_date = event_date;
    _event_info = event_info;
    _event_user_id = event_user_id;
    ui->setupUi(this);
    ui->label->setText(tr("Событие №")+event_num+"                                "
                          +tr("Дата: ")+event_date);
    ui->label_2->setText(event_name.prepend("<h4>").append("</h4>"));
    ui->label_3->setText(tr("<p style=\"line-height:25px\">Детальная информация:<br/><a href='#123'>")+event_info+"</a></p>");
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(OKbtn_clicked()));
    connect(ui->label_3,SIGNAL(linkActivated(QString)),this,SLOT(link_clicked()));
}

Notification_Box::~Notification_Box()
{
    delete ui;
}

long long Notification_Box::get_event_user_id()
{
    return _event_user_id;
}

QString Notification_Box::get_event_num()
{
    return _event_num;
}

QString Notification_Box::get_event_name()
{
    return _event_name;
}

QString Notification_Box::get_event_date()
{
    return _event_date;
}

QString Notification_Box::get_event_info()
{
    return _event_info;
}

void Notification_Box::OKbtn_clicked()
{
    emit i_was_pressed(this);
    delete this; // Умри достойно, самурай
}

void Notification_Box::link_clicked()
{
    emit my_link_clicked(this);
}
