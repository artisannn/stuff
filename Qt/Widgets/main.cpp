#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <stdlib.h>
#include <iostream>
#include <QtWidgets>
#include <QPushButton>
#include "mywindow.h"
#include "list.h"
#include "hyper_sphere.h"
//#include "notification_box.h"
#include "singleton_no_ntfns.h"

int f (int a)
{
    qDebug() << QString::number(a);
    return a;
}

// Бинарное представление числа
void forv_bin (int n)
{
    if (n)
    {
        qDebug()<< n%2;
        forv_bin(n/2);
    }
    else return;
}//   forv_bin(16);

// Попробовал получить ряд имен, отличающихся лишь цифрой в конце
void concat_i_with_str ()
{
    QString Str("Hello");
    qDebug() << "Str = " << Str;
    for (int i=1;  i<=5 ; i++)
    {
        qDebug() << Str;
        qDebug() << "hello";
        qDebug() << "Str = " << Str + QString::number(i);
        std::cout << "cout_ring \r" << std::endl;
        printf("printf_ring \r");
    }
}
// Попробовал "на кошках" возможности условного ветвления без if else
void test_logic_operators ()
{
    if (f(0) && f(2) || f(3) || f(4) && f(5))
    {
        qDebug() << "withhout ()";
    }
}
// Далее идут рекурсивные реализации различных функций
void print_1_to_N (unsigned int n)
{
    if (n <= 0)
    {
        qDebug() << n ;
    }
    else
    {
        print_1_to_N(n-1);
        qDebug() << n ;
    }
}//    print_1_to_N(5);

void print_a_to_b (int a, int b)
{
    if (a==b)
    {
        qDebug() << a ;
    }
    else if (a<b)
    {
        qDebug() << a ;
        print_a_to_b(a+1,b);
    }
    else
    {
        qDebug() << a ;
        print_a_to_b(a-1,b);
    }
}//    print_a_to_b(5,-2);

// Проверяет является ли число степенью двойки
void power_of_two_REC (int n)
{
    if(n%2 == 1)
    {
        qDebug() << "the number is NOT power of two!" ;
    }
    else if(n/2==1)
    {
        qDebug() << "the number is realy power of two!" ;
    }
    else
    {
        power_of_two_REC(n/2);
    }
}//    power_of_two(256);

// Тоже, проверка на степень двойки, только не рекурсивная, но оооочень быстрая
void power_of_two_BIN(int n)
{
    if (!(n & n-1) && n>=2)
    {
        qDebug() << "the number" << n <<" is realy power of two!" ;
    }
    else
        qDebug() << "the number" << n <<" is NOT power of two!";
}/*                   for (int i=1; i<257; i++)
                    {
                        power_of_two_BIN(i);
                    }*/

// Возведение числа в степень
int power(int n, int power_value)
{
    if (power_value==1)
    {
        return n;
    }
    else if (power_value>1)
    {
        return n * power(n,power_value-1);
    }
    else
    {
        qDebug() << "the power value is NOT positive!" ;
        return 0;
    }
}//    qDebug() << power(-3,-4);

// печатает сумму цифр числа
int sum_of_the_number_of_digits (int n)
{
    if (n<=9)
        return n;
    else
        return n%10 + sum_of_the_number_of_digits(n/10);
}//    qDebug() << sum_of_the_number_of_digits(2182);

// печатает цифры из которых состоит число в ПРЯМОМ порядке, если поменять строчки кода в блоке else местами то число будет печататься в обратном порядке
void print_digits_of_number_FORWARD (int n)
{
    if (n<=9)
        qDebug() << n;
    else
    {
        print_digits_of_number_FORWARD(n/10);
        qDebug() << n%10;
    }
}//    print_digits_of_number_FORWARD(123456);

// Проверяет является ли число простым
bool prime (int n, int i)
{
   int Sqrt_N = sqrt(n);
    if (n==2 ||(i >= Sqrt_N && n%i!=0))
        return true;
    else if (n%i==0 && i <= Sqrt_N)
    {
        return false;
    }
    else
    {
        return prime(n,i+1);
    }
}
/*                 for (int i=2; i<50 ; i++)
                    {
                        if (prime(i,2))
                            qDebug() <<i<<" Простое число" ;
                    }*/

// Тоже проверяет на простоту, но не рекурсивно
bool prime(long long n){
    for(long long i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}
// Рекурсивнывй вариант факторизации, сложность О(n), в лоб короче.
void prime_factorization (int n, int k)
{
    if (k > n / 2) // Если делитель превышает половину n, то возвращаем n
    {
        qDebug() << n;
        return ;
    }
    if (n % k == 0) // Если n четное, то делитель = 2
    {
        qDebug() << k;
        prime_factorization(n/k,k);
    }
    else            // Если n нечетное то пробуем делить на k++ (т.е. 3)
        prime_factorization(n,k++);
}
// Нерекурсивный вариант факторизации,с применением функции проверки на простоту, сложность не посчитана
void prime_factorization (long long n)
{
    long long Sqrt=sqrt(n);
    for (long long i=2;i<=Sqrt;i++)
    {
        if (prime(i))
        {
            if (n%i==0 )
            {
                n=n/i;
                qDebug() << i;
                i--;
            }
            else
                continue;
        }
    }
}//    prime_factorization(12);

// Возвращает простое число по номеру(1е - "2", 2е - "3", 4е - "5"{, 5е - "7" и т.д.),
// счет начинается с 1
long long get_prime_by_number (int item)
{
    int count=0;
    for (long long i=2; ; i++)
    {
        if (prime(i))
        {
            count++;
            if (count==item)
                return i;
        }
    }

}

// Рекурсивный вариант факторизации, но c меньшей сложностью
void prime_factorization_recurse (long long n, int i=1)
{
    long long min_prime = get_prime_by_number(i);
    if (n % min_prime==0)
    {
        qDebug() << i;
        prime_factorization_recurse(n/min_prime,i);
    }
    else
        prime_factorization_recurse(n/min_prime,++i);
}//    prime_factorization_recurse(12,1);// Не доделано

// Функция которая 1001 способом покажет размеры виджета. И они разные :)
/*void the_widget_sizes(QWidget* wgt)
{
    QRect rect = wgt->normalGeometry();
    qDebug()<<" ";
    qDebug()<<"QRect";
    qDebug()<<" ";
    qDebug()<<"normalGeometry():     "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    rect = wgt->rect();
    qDebug()<<"rect():               "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    rect = wgt->contentsRect();
    qDebug()<<"contentsRect():       "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    rect = wgt->frameGeometry();
    qDebug()<<"frameGeometry():      "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    rect = wgt->geometry();
    qDebug()<<"geometry():           "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    rect = wgt->childrenRect();
    qDebug()<<"childrenRect():       "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    rect = Vblayout->geometry();
    qDebug()<<"Vblayout->geometry(): "<<"Width = "<<rect.width()<<", Height = "<<rect.height()<<", x = "<<rect.x()<<", y = "<<rect.y();
    qDebug()<<" ";
    qDebug()<<"QSize";
    qDebug()<<" ";
    QSize size = wgt->baseSize();
    qDebug()<<"baseSize():        "<<"Width = "<<size.width()<<", Height = "<<size.height();
    size = wgt->frameSize();
    qDebug()<<"frameSize():       "<<"Width = "<<size.width()<<", Height = "<<size.height();
    size = wgt->maximumSize();
    qDebug()<<"maximumSize():     "<<"Width = "<<size.width()<<", Height = "<<size.height();
    size = wgt->minimumSize();
    qDebug()<<"minimumSize():     "<<"Width = "<<size.width()<<", Height = "<<size.height();
    size = wgt->size();
    qDebug()<<"size():            "<<"Width = "<<size.width()<<", Height = "<<size.height();
    size = wgt->sizeHint();
    qDebug()<<"sizeHint():        "<<"Width = "<<size.width()<<", Height = "<<size.height();
    qDebug()<<" ";
    qDebug()<<"Others";
    qDebug()<<" ";
    qDebug()<<"int width = "<<wgt->width();
    QRegion region = visibleRegion();
    qDebug()<<"visibleRegion():   "<<"Width = "<<region.boundingRect().width()<<", Height = "<<region.boundingRect().height();
    QLayout* some_layout = layout();
    qDebug()<<"layout()(manager): "<<"Width = "<<some_layout->contentsRect().width()<<", Height = "<<some_layout->contentsRect().height();
    qDebug()<<"Vblayout():        "<<"Width = "<<Vblayout->contentsRect().width()<<", Height = "<<Vblayout->contentsRect().height();
}*/
/*class MyWidget : public QWidget
{
public:
    QVBoxLayout* vblt = new QVBoxLayout;
public slots:
    inline void add_label()
    {
        if (vblt->isEmpty())
            vblt->addWidget(Singleton_no_ntfns::instance());
    }
};*/

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MyWindow* wind = new MyWindow();

    QPushButton button("Add new item");
    button.show();

    wind->show();

/*    QWidget* wgt = new QWidget;
    QVBoxLayout* vblt = new QVBoxLayout;
    wgt->setLayout(vblt);
    Singleton_no_ntfns* singleton = Singleton_no_ntfns::instance();
    vblt->addWidget(singleton);
    wgt->show();
//    Sleep(5000);
    if(singleton)
        singleton->free_instance();*/

    return a.exec();
}

/*  Пытался выявить всяческие маргины у моего окна со всеми его вложенными виджетами
    int l,r,t,b,left=0,right=0,top=0,bottom=0;
    current_ntbx->getContentsMargins(&l,&t,&r,&b);
    left+=l;
    right+=r;
    top+=t;
    bottom+=b;
    qDebug()<<"current_ntbx margins: "<<"Left = "<<l<<", Right = "<<r<<", Bottom = "<<b<<", Top = "<<t;
    scrollArea->getContentsMargins(&l,&t,&r,&b);
    left+=l;
    right+=r;
    top+=t;
    bottom+=b;
    qDebug()<<"scrollArea margins: "<<"Left = "<<l<<", Right = "<<r<<", Bottom = "<<b<<", Top = "<<t;
    //    Vblayout->setMargin(0);
    Vblayout->getContentsMargins(&l,&t,&r,&b);
    left+=l;
    right+=r;
    top+=t;
    bottom+=b;
    qDebug()<<"Vblayout margins: "<<"Left = "<<l<<", Right = "<<r<<", Bottom = "<<b<<", Top = "<<t;
    wgt->getContentsMargins(&l,&t,&r,&b);
    left+=l;
    right+=r;
    top+=t;
    bottom+=b;
    qDebug()<<"wgt margins: "<<"Left = "<<l<<", Right = "<<r<<", Bottom = "<<b<<", Top = "<<t;
    this->getContentsMargins(&l,&t,&r,&b);
    left+=l;
    right+=r;
    top+=t;
    bottom+=b;
    qDebug()<<"this margins: "<<"Left = "<<l<<", Right = "<<r<<", Bottom = "<<b<<", Top = "<<t;
    QMargins margins = scrollArea->contentsMargins();
    left+=margins.left();
    right+=margins.right();
    top+=margins.top();
    bottom+=margins.bottom();
    qDebug()<<"scrollArea->contentsMargins() margins: "<<"Left = "<<margins.left()<<", Right = "<<margins.right()<<", Bottom = "<<margins.bottom()<<", Top = "<<margins.top();
*/


/*      "Этот фрагмент часть хайринг теста"
    const int int_array [] = {1,2,3,4,5,6,7,8,9};
    const QString array_string [] = {"Hello,","my","name","is","Arthur"};

    List<int,9> Int_List (int_array);
    List<QString,5> String_List (array_string);

    Int_List.print();
    String_List.print();

    Hyper_sphere A(15,3);
    qDebug ()<<"A.volume = "<<A.sphere_volume();
*/

/*  Тема с поиском Кёнига
    wind->Do_tra_la_la(MyWindow::green);
*/

/*  Тема с Саховским
    QString s = "какая-то строка";
    qDebug() << "(в qdfconnectionpool) s= " << s << " ДО преобразования";
    QByteArray ba;
    ba.append(s.toUtf8());
    s = ba.toBase64().data();
    qDebug() << "(в qdfconnectionpool) s= " << s <<" toHex()";

    QByteArray ba1;
    ba1.append("d098d0b42e20d181d0b2d18fd0b7d0b820d0bad0bbd0b0d181d181d0bed0b22028504b29");
    QByteArray  ba2 = QByteArray::fromHex(ba1);
    s = QString::fromUtf8(ba2.data());
    qDebug() << "d098d0b42e20d181d0b2d18fd0b7d0b820d0bad0bbd0b0d181d181d0bed0b22028504b29 = " << s << " fromHex(ba1)";
*/
// Запись в файл чего-то в указанную директорию
//    QTextEdit * txt = new QTextEdit("Хэлловорлд!");
//    QTextDocumentWriter writer ;
//    writer.setFormat("txt");
//    writer.setFileName("D:\\Hello.txt");
//    writer.write(txt->document());

// Попробовал поиграться с HTML в титулах окон, не плохо
//    QMessageBox::warning(nullptr,"Warning!",
//                             "<h4>Заполнение данных завершено.</h4>\n\r"+Str);
//    QLabel lbl("<h1> <font color =red> Hello World </font> h1 <h1>");

// Набросок использования конструкции try catch
//   func ()
//    {
//       try
//       {
//           for(;;)
//            {
//               for(;;)
//                {//                   for(;;)
//                    {
//                        // Мы находимся здесь
//                       if (c=='27') throw "Esc";
//                    }
//                }
//            }
//        // Нужно прыгнуть сюда
//       }
//       catch (QString c)
//       {
//           if (c=="Esc")
//             ;
//       }
//    }


// Все что ниже, какой-то код с инета, реализующий контекстное меню
//main.cpp
//@
//#include <QtGui/QApplication>
//#include "widget.h"

//int main(int argc, char *argv[])
//{
//QApplication a(argc, argv);
//Widget w;
//w.show();

//return a.exec&#40;&#41;;
//}
//@

//widget.h
//@
//#ifndef WIDGET_H
//#define WIDGET_H

//#include <QtGui/QWidget>

//class QTableView;

//class Widget : public QWidget
//{
//Q_OBJECT

//public:
//    Widget(QWidget *parent = 0);
//    ~Widget();

//public slots:
//    void customMenuRequested(QPoint pos);

//private:
//    QTableView *table;
//};

//#endif // WIDGET_H
//@

//widget.cpp
//@
//#include <QtGui>
//#include "widget.h"

//Widget::Widget(QWidget *parent)
//: QWidget(parent)
//{
//    QVBoxLayout *l=new QVBoxLayout(this);
//    table=new QTableView(this);
//    table->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(table, SIGNAL(customContextMenuRequested(QPoint)),
//    SLOT(customMenuRequested(QPoint)));
//    l->addWidget(table);
//}

//Widget::~Widget(){}

//void Widget::customMenuRequested(QPoint pos)
//{
//    QModelIndex index=table->indexAt(pos);
//    QMenu *menu=new QMenu(this);
//    menu->addAction(new QAction("Action 1", this));
//    menu->addAction(new QAction("Action 2", this));
//    menu->addAction(new QAction("Action 3", this));
//    menu->popup(table->viewport()->mapToGlobal(pos));
//}
