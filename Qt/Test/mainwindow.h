#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QDebug>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QMutex *mutex, const char * name, int sleep_interval, QWidget *parent = 0);
    ~MainWindow();
private:
    const int interval;
    const QString My_name;
    int count;
    QMutex* _mutex;
    Ui::MainWindow *ui;
public slots:
    void mainMethod();
};

#endif // MAINWINDOW_H
