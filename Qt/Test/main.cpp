#include "mainwindow.h"
#include "threadobject.h"
#include <QApplication>
#include <QThread>
#include <forward_list>

bool do_something()
{
    qDebug()<<"I'm do_somethign method, but i do nothing.";
    return false;
}

int angle_between_hands(const int hours,const int minutes)
{
    if (hours>24 || minutes>60)
    {
        qDebug()<<"Minutes shouldn't exceed 60 and hours shouldn't exceed 24. Please, enter correct values";
        return -1;
    }
    const int circle = 360;
    const int degrees_in_hours = circle/12 * (hours%12);
    const int degrees_in_minutes = circle/60 * minutes;
    const int difference = abs(degrees_in_hours  - degrees_in_minutes);
    if (difference < circle/2)
        return difference;
    else
        return circle-difference;
}
template <typename T>
std::forward_list <T> reverse_copy_list(const std::forward_list<T>& in)
{
    auto out = in;
    out.reverse();
    return out;
}

int main(int argc, char *argv[])
{
    int resource = 1000;
    QApplication a(argc, argv);
    QMutex* mutex = new QMutex();
    ThreadObject He(resource,mutex,Gender::male,2000);
    ThreadObject She(resource,mutex,Gender::female,1);

    QThread * thread_1 = new QThread ();
    QThread * thread_2 = new QThread ();

    He.moveToThread(thread_1);
    She.moveToThread(thread_2);

    QObject::connect(thread_1,SIGNAL(started()),&He,SLOT(mainMethod()));
    QObject::connect(thread_2,SIGNAL(started()),&She,SLOT(mainMethod()));

    thread_1->start();
    thread_2->start();
//    QString str("Hello!");
//    for(int i=0; i<str.length() || do_something(); i++)
//        qDebug()<<str.at(i);
//    qDebug()<<"angle = "<<angle_between_hands(24,35);

//    std::forward_list<int> mylist = {600, 20, 30, 40};
//    auto d = copy_list(mylist);
//    mylist.reverse();
//    for(auto x: mylist)
//    {
//        qDebug()<<x;
//    }
//    const auto begin = mylist.begin();
////    for(auto current = mylist.end(); current != begin; current--)
////    {
////        qDebug()<<*current;
////    }
    return a.exec();
}
