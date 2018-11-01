#include "dialog.h"
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    dialog(new Ui::Dialog)
{
    dialog->setupUi(this);
    settings = new QSettings (this);
    connect(dialog->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(load_settings()));
    connect(dialog->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(oracle_is_checked(int)));
    load_settings();
}
QString Dialog::get_server_type()
{
    return dialog->comboBox->currentText();
}
QString Dialog::get_server_name()
{
    return dialog->lineEdit->text();
}
QString Dialog::get_host_name()
{
    return dialog->lineEdit_2->text();
}
QString Dialog::get_user_name()
{
    return dialog->lineEdit_3->text();
}
QString Dialog::get_password()
{
    return dialog->lineEdit_4->text();
}

void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if (dialog->buttonBox->standardButton(button)== QDialogButtonBox::Cancel)
    {
        Dialog::state = Cancel;
    }
    if (dialog->buttonBox->standardButton(button)== QDialogButtonBox::Ok)
    {
       Dialog::state = Ok;
        qDebug()<< "ОК. Подключаемся.";
    }
}

void Dialog::save_settings()
{
    settings->beginGroup(dialog->comboBox->currentText());
        settings->beginGroup("connect_params");
            settings->setValue("server_name",dialog->lineEdit->text());
            settings->setValue("host_name",dialog->lineEdit_2->text());
            settings->setValue("user_name",dialog->lineEdit_3->text());
            settings->setValue("password",dialog->lineEdit_4->text());
        settings->endGroup();
    settings->endGroup();
    qDebug()<<"save_settings()";
}

void Dialog::load_settings()
{
    settings->beginGroup(dialog->comboBox->currentText());
        settings->beginGroup("connect_params");
            dialog->lineEdit->setText(settings->value("server_name").toString());
            dialog->lineEdit_2->setText(settings->value("host_name").toString());
            dialog->lineEdit_3->setText(settings->value("user_name").toString());
            dialog->lineEdit_4->setText(settings->value("password").toString());
        settings->endGroup();
    settings->endGroup();
    qDebug()<<"load_settings()";
}

void Dialog::oracle_is_checked(int i)
{
    if (i==1)
    {
        dialog->lineEdit_2->setDisabled(true);
    }
    else
        dialog->lineEdit_2->setDisabled(false);
}

bool Dialog::saving_connection_params_is_allowed()
{
    if (dialog->checkBox->isChecked())
        return true;
    else
        return false;
}

Dialog::~Dialog()
{
    qDebug()<<"~Dialog()";
    if (dialog->checkBox->isChecked())
    {
        save_settings();
    }
    delete dialog;
}
