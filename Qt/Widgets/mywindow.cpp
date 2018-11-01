#include "mywindow.h"

MyWindow::MyWindow()
{

    layout_glob = new QVBoxLayout;
    layout = new QHBoxLayout;
    layout2 = new QHBoxLayout;
    layout3 = new QHBoxLayout;

    layout_glob->addLayout(layout);

        button1 = new QPushButton ("&Close");
        layout->addWidget(button1);
        button2 = new QPushButton ("K&lose");
        layout->addWidget(button2);
        button3 = new QPushButton ("Cl&ose");
        layout->addWidget(button3);
        sl = new QSlider(Qt::Horizontal);
        layout->addWidget(sl);
        sl->setMaximum(100);

    layout_glob->addLayout(layout2);

        lb = new QLabel("Enter");
        layout2->addWidget(lb);
        line = new QLineEdit;
        layout2->addWidget(line);

    layout_glob->addLayout(layout3);

        ch = new QCheckBox("Invert");
        layout3->addWidget(ch);

        sb = new QSpinBox;
    layout_glob->addWidget(sb);

    sb->setMaximum(100);

    lb->setBuddy(button1);
    lb->setBuddy(sl);

    scr = new QScrollArea;
    scr->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    window = new QWidget;
    window->setLayout(layout_glob);
    scr->setWidget(window);
    QObject::connect(sb,SIGNAL(valueChanged(int)),sl,SLOT(setValue(int)));
    QObject::connect(sl,SIGNAL(valueChanged(int)),sb,SLOT(setValue(int)));
    QObject::connect(button1,SIGNAL(pressed()),scr,SLOT(close()));
    QObject::connect(button2,SIGNAL(pressed()),scr,SLOT(hide()));

    m_pmnu = new QMenu(this);
    actionAddStr = new QAction("Добавить строки",m_pmnu);
    actionDelStr = new QAction("Удалить строки",m_pmnu);
    actionNewPar = new QAction("Показать новые параметры",m_pmnu);
    m_pmnu->addAction(actionAddStr);
    m_pmnu->addAction(actionDelStr);
    m_pmnu->addAction(actionNewPar);
    window->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(window,SIGNAL(customContextMenuRequested(QPoint)),
                         this, SLOT(call_menu()));
}

 MyWindow::Color MyWindow::Do_tra_la_la(Color clr) // Метод написан для проверки поиска Кёнига
{
    switch (clr)
    {
        case MyWindow::Color::red:
            QMessageBox::warning(nullptr,"Warning!",
                                     "<h4>red.</h4>\n\r");break;
        case MyWindow::Color::green:
            QMessageBox::warning(nullptr,"Warning!",
                                     "<h4>green.</h4>\n\r");break;
        case MyWindow::Color::blue:
            QMessageBox::warning(nullptr,"Warning!",
                                     "<h4>blue.</h4>\n\r");
    }
    return clr;
}

void MyWindow::call_menu()
{
    m_pmnu->exec(QCursor::pos());
}

void MyWindow::show()
{
    scr->show();
}
