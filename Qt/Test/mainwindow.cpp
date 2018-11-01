#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QMutex * mutex, const char *name, int sleep_interval, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    count(0),
    My_name(name),
    interval(sleep_interval)
{
    _mutex = mutex;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainMethod()
{
    while(1)
    {
//        _mutex->lock();
        qDebug()<<My_name<<" :"<<count;
        count++;
//        _mutex->unlock();
        QThread::msleep(interval);
    }
}
