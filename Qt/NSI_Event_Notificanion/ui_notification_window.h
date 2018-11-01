/********************************************************************************
** Form generated from reading UI file 'notification_window.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATION_WINDOW_H
#define UI_NOTIFICATION_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notification_window
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *Notification_window)
    {
        if (Notification_window->objectName().isEmpty())
            Notification_window->setObjectName(QStringLiteral("Notification_window"));
        Notification_window->resize(925, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Notification_window->sizePolicy().hasHeightForWidth());
        Notification_window->setSizePolicy(sizePolicy);
        Notification_window->setAutoFillBackground(true);
        gridLayout = new QGridLayout(Notification_window);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Notification_window);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 923, 428));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Notification_window);

        QMetaObject::connectSlotsByName(Notification_window);
    } // setupUi

    void retranslateUi(QWidget *Notification_window)
    {
        Notification_window->setWindowTitle(QApplication::translate("Notification_window", "NSI_Event_Notification", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Notification_window: public Ui_Notification_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATION_WINDOW_H
