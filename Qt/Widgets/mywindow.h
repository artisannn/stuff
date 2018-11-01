#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QMenu>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QMessageBox>

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    QScrollArea * scr;
    QMenu* m_pmnu;
    QAction* actionAddStr;
    QAction* actionDelStr;
    QAction* actionNewPar;
    QVBoxLayout * layout_glob;
    QHBoxLayout * layout;
    QHBoxLayout * layout2;
    QHBoxLayout * layout3;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QSlider * sl;
    QLabel* lb;
    QLineEdit* line;
    QCheckBox * ch;
    QSpinBox * sb;
    QWidget * window;
    enum Color {red,green,blue};

    void show();
    MyWindow();
    Color Do_tra_la_la(Color);

public slots:
    void call_menu();
};

#endif // MYWINDOW_H
