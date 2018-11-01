/********************************************************************************
** Form generated from reading UI file 'notification_box.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATION_BOX_H
#define UI_NOTIFICATION_BOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notification_Box
{
public:
    QFrame *frame;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Notification_Box)
    {
        if (Notification_Box->objectName().isEmpty())
            Notification_Box->setObjectName(QStringLiteral("Notification_Box"));
        Notification_Box->resize(881, 180);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Notification_Box->sizePolicy().hasHeightForWidth());
        Notification_Box->setSizePolicy(sizePolicy);
        Notification_Box->setMinimumSize(QSize(878, 180));
        frame = new QFrame(Notification_Box);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 881, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(5);
        frame->setMidLineWidth(2);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(750, 80, 75, 23));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 11, 691, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Notification_Box);

        QMetaObject::connectSlotsByName(Notification_Box);
    } // setupUi

    void retranslateUi(QWidget *Notification_Box)
    {
        Notification_Box->setWindowTitle(QApplication::translate("Notification_Box", "Form", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Notification_Box", "\320\236\320\232", Q_NULLPTR));
        pushButton_2->setShortcut(QApplication::translate("Notification_Box", "Ctrl+Return", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Notification_Box: public Ui_Notification_Box {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATION_BOX_H
