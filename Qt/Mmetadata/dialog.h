#ifndef DIALOG_H
#define DIALOG_H
#include "ui_dialog.h"
#include <QDialog>
#include <QSettings>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    enum states {Ok,Cancel};
    states state=Cancel;
    explicit Dialog(QWidget *parent = 0);
    QString get_server_type();
    QString get_server_name();
    QString get_host_name();
    QString get_user_name();
    QString get_password();
    void save_settings();
    bool saving_connection_params_is_allowed ();
    ~Dialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void load_settings();
    void oracle_is_checked(int);
private:
    QSettings * settings;
    Ui::Dialog *dialog;
};

#endif // DIALOG_H
