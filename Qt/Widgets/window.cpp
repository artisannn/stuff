#include "window.h"
#include "ui_window.h"

My_Window::My_Window(QWidget *parent) :
    QMainWindow(parent),
    My_Window::ui(new Ui::My_Window)
{
    My_Window::ui->setupUi(this);
}

My_Window::~My_Window()
{
    delete My_Window::ui;
}
