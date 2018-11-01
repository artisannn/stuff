/********************************************************************************
** Form generated from reading UI file 'settings_form.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_FORM_H
#define UI_SETTINGS_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings_Form
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb_window_mode;
    QRadioButton *rb_baloon_msg;
    QRadioButton *rb_paint_icon;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;

    void setupUi(QDialog *Settings_Form)
    {
        if (Settings_Form->objectName().isEmpty())
            Settings_Form->setObjectName(QStringLiteral("Settings_Form"));
        Settings_Form->resize(483, 232);
        buttonBox = new QDialogButtonBox(Settings_Form);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 190, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Settings_Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 441, 111));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 420, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rb_window_mode = new QRadioButton(layoutWidget);
        rb_window_mode->setObjectName(QStringLiteral("rb_window_mode"));
        rb_window_mode->setChecked(false);

        verticalLayout->addWidget(rb_window_mode);

        rb_baloon_msg = new QRadioButton(layoutWidget);
        rb_baloon_msg->setObjectName(QStringLiteral("rb_baloon_msg"));
        rb_baloon_msg->setChecked(true);

        verticalLayout->addWidget(rb_baloon_msg);

        rb_paint_icon = new QRadioButton(layoutWidget);
        rb_paint_icon->setObjectName(QStringLiteral("rb_paint_icon"));
        rb_paint_icon->setChecked(false);

        verticalLayout->addWidget(rb_paint_icon);

        layoutWidget1 = new QWidget(Settings_Form);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 150, 310, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(layoutWidget1);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(59);
        spinBox->setValue(5);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(layoutWidget1);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(59);
        spinBox_2->setValue(0);

        horizontalLayout->addWidget(spinBox_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);


        retranslateUi(Settings_Form);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings_Form, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings_Form, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings_Form);
    } // setupUi

    void retranslateUi(QDialog *Settings_Form)
    {
        Settings_Form->setWindowTitle(QApplication::translate("Settings_Form", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Settings_Form", "\320\232\320\260\320\272\320\270\320\274 \320\276\320\261\321\200\320\260\320\267\320\276\320\274 \320\222\320\260\321\201 \320\276\320\277\320\276\320\262\320\265\321\211\320\260\321\202\321\214? ", Q_NULLPTR));
        rb_window_mode->setText(QApplication::translate("Settings_Form", "\320\240\320\260\320\267\320\262\320\276\321\200\320\260\321\207\320\270\320\262\320\260\321\202\321\214 \320\276\320\272\320\275\320\276 \321\201 \320\276\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\321\217\320\274\320\270", Q_NULLPTR));
        rb_baloon_msg->setText(QApplication::translate("Settings_Form", "\320\222\321\201\320\277\320\273\321\213\320\262\320\260\321\216\321\211\320\270\320\274\320\270 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217\320\274\320\270 \320\270\320\267 \321\201\320\270\321\201\321\202\320\265\320\274\320\275\320\276\320\263\320\276 \321\202\321\200\320\265\321\217", Q_NULLPTR));
        rb_paint_icon->setText(QApplication::translate("Settings_Form", "\320\235\320\265 \320\277\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\262\320\276\320\276\320\261\321\211\320\265 \320\275\320\270\321\207\320\265\320\263\320\276, \321\202\320\276\320\273\321\214\320\272\320\276 \320\274\320\265\320\275\321\217\321\202\321\214 \321\206\320\262\320\265\321\202 \320\267\320\275\320\260\321\207\320\272\320\260 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\275\320\276\320\274 \321\202\321\200\320\265\320\265", Q_NULLPTR));
        label->setText(QApplication::translate("Settings_Form", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\276\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\320\271 - \321\200\320\260\320\267 \320\262", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings_Form", "\320\274\320\270\320\275\321\203\321\202", Q_NULLPTR));
        label_3->setText(QApplication::translate("Settings_Form", "\321\201\320\265\320\272\321\203\320\275\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings_Form: public Ui_Settings_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_FORM_H
