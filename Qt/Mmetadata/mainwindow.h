#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QIcon>
#include <QMainWindow>
#include <QDialog.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>
#include <QTreeWidget>
#include "qxdataconnection.h"
#include "dialog.h"
#include "dfProcess.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    void on_pushButton_clicked(); /*   >   */
    void on_pushButton_3_clicked(); /*   <   */
    void connect_to_db(bool checked);
    void on_action_unload_triggered();
    void on_action_load_triggered();
    void action_refresh_triggered();
    void action_search_triggered();

private:
    QString correct_ending_of_word(int,const QString &);
    void prepare_List_id_and_Name_list (QTreeWidgetItemIterator&, QString &, QString &);
    bool prepare_left_treeview();
    void clear_right_treeview();
    void load_settings();
//    void save_settings();
    QSettings * settings;
    QDF* df;
    Ui::MainWindow * window;
    Dialog * connect_dialog;
    QSqlDatabase db;
    QString load_sscen_GUID;
    QString unload_scen_GUID;
    QString proj_ABBR;
    QString saving_file_name;
    QString loading_file_name;
    QString list_id;
    QString driver; // QOSI/QPSQL
    QString dbType; // PostgreSQL/Oracle
    QString server; // md/green
    QString host;// 192.168....
    QString user;   // maket_msdu_2015_1
    QString password;// maket
};

class MyQTreeWidgetItem : public QTreeWidgetItem // Класс предназначен исключительно для переопределения оператора"<",
{                                                // который дает возможность сортировки по дате-времени
    inline bool operator<(const QTreeWidgetItem &other) const
    {
       int column = treeWidget()->sortColumn();
    // можно проверить, что находится в data(column, Qt::UserRole) и вызвать свой оператор сравнения для этих данных,
    // например вот так по-нашему, по-быдлокодэрски:
        if(!data(column, Qt::UserRole).isNull())
          if(!other.data(column, Qt::UserRole).isNull())
                 return data(column,Qt::UserRole).toDateTime() < other.data(column,Qt::UserRole).toDateTime();
        const QVariant v1 = data(column, Qt::DisplayRole);
        const QVariant v2 = other.data(column, Qt::DisplayRole);
        return v1.toString()<v2.toString();
    }
public:
    inline MyQTreeWidgetItem(QTreeWidget *view)
        :QTreeWidgetItem(view)
    {}
};

//class MyQTreeWidget : public QTreeWidget
//{
//    Q_OBJECT
//    QString list_id;
//}

#endif // MAINWINDOW_H
