#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("ICL");
    QApplication::setApplicationName("Metadata");
    MainWindow w;
    w.show();

    return a.exec();
}
