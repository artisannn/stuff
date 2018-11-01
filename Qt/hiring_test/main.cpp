#include <QCoreApplication>
#include <QDebug>
#include "list.h"
#include "hyper_sphere.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int int_array [] = {1,2,3,4,5,6,7,8,9};
    const QString array_string [] = {"Hello,","my","name","is","Arthur"};

    List<int,9> Int_List (int_array);
    List<QString,5> String_List (array_string);

    Int_List.print();
    String_List.print();

    qDebug()<<"Wait";
    Hyper_sphere Sphere(15,3);
    qDebug ()<<"Sphere with radius: "<< Sphere.sphere_radius()<<
               " and dimentions number :"<<Sphere.sphere_dimentions()<<
               " has volume: "<<Sphere.sphere_volume();
    return a.exec();
}
