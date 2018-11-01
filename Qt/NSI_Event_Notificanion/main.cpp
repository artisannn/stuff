#include <QApplication>
#include "notification_window.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "notification_box.h"
#include "notification_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    QApplication::setOrganizationName("ICL");
    QApplication::setApplicationName("NSI_Event_Notificanion");
    Notification_window main_window;
    if(main_window.connect_to_db(argv[1],argv[2],argv[3],argv[4],argv[5]))
    {
        main_window.init();
        main_window.show();
    }
    else
    {
        main_window.hide();
        QMessageBox::warning(0,"NSI_Event_Notificanion",
            "Для повторной попытки подключения попробуйте перезапустить MVisiData.");
        return -1;
    }
/*    for(int i=1; i<argc ; i++)
    {
        QMessageBox::information(0,"NSI_Event_Notificanion",
                                         QString(argv[i]));
    }*/

/*    QPushButton add_ntfx_btn;
    QObject::connect(&add_ntfx_btn,SIGNAL(clicked(bool)),&main_window,SLOT(add_ntbx_by_btn_click()));
    add_ntfx_btn.show();        А это нужно будет разкомментировать - три   */

    return a.exec();
}


