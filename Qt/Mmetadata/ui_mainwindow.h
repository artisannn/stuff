/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_connect;
    QAction *action_unload;
    QAction *action_load;
    QAction *action_search;
    QAction *action_refresh;
    QAction *action_exit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QTreeWidget *treeWidget_2;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuMmetadata;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(765, 547);
        MainWindow->setIconSize(QSize(456, 33));
        action_connect = new QAction(MainWindow);
        action_connect->setObjectName(QStringLiteral("action_connect"));
        action_connect->setCheckable(true);
        action_connect->setChecked(false);
        QIcon icon;
        icon.addFile(QStringLiteral("icons/flaticons/plugin.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_connect->setIcon(icon);
        action_unload = new QAction(MainWindow);
        action_unload->setObjectName(QStringLiteral("action_unload"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icons/flaticons/arrowup.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_unload->setIcon(icon1);
        action_load = new QAction(MainWindow);
        action_load->setObjectName(QStringLiteral("action_load"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icons/flaticons/arrowdown.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_load->setIcon(icon2);
        action_search = new QAction(MainWindow);
        action_search->setObjectName(QStringLiteral("action_search"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("icons/flaticons/magnifyingglass.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_search->setIcon(icon3);
        action_refresh = new QAction(MainWindow);
        action_refresh->setObjectName(QStringLiteral("action_refresh"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icons/flaticons/reload-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_refresh->setIcon(icon4);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icons/flaticons/power.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setEnabled(true);
        treeWidget->setSortingEnabled(true);

        horizontalLayout->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        treeWidget_2 = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        treeWidget_2->setSortingEnabled(true);

        horizontalLayout->addWidget(treeWidget_2);


        verticalLayout_3->addLayout(horizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setMinimumSize(QSize(0, 0));
        plainTextEdit->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(plainTextEdit);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 765, 21));
        menuMmetadata = new QMenu(menuBar);
        menuMmetadata->setObjectName(QStringLiteral("menuMmetadata"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(30, 30));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMmetadata->menuAction());
        menuBar->addAction(menu->menuAction());
        menuMmetadata->addAction(action_connect);
        menuMmetadata->addSeparator();
        menu->addAction(action_refresh);
        menu->addSeparator();
        menu->addAction(action_unload);
        menu->addAction(action_load);
        menu->addSeparator();
        menu->addAction(action_search);
        menu->addSeparator();
        menu->addAction(action_exit);
        mainToolBar->addAction(action_connect);
        mainToolBar->addAction(action_unload);
        mainToolBar->addAction(action_load);
        mainToolBar->addAction(action_search);
        mainToolBar->addAction(action_refresh);
        mainToolBar->addAction(action_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MetaData", Q_NULLPTR));
        action_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\272 \320\221\320\224", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_connect->setToolTip(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \320\221\320\224", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_connect->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        action_unload->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_unload->setToolTip(QApplication::translate("MainWindow", "\320\222\321\213\320\263\321\200\321\203\320\267\320\272\320\260 \320\274\320\265\321\202\320\260\320\264\320\260\320\275\320\275\321\213\321\205 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262 \320\275\320\260 \320\264\320\270\321\201\320\272 \321\201 \320\221\320\224", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_unload->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", Q_NULLPTR));
        action_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_load->setToolTip(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\274\320\265\321\202\320\260\320\264\320\260\320\275\320\275\321\213\321\205 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262 \321\201 \320\264\320\270\321\201\320\272\320\260 \320\262 \320\221\320\224", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_load->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
        action_search->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_search->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202 \320\262 \321\201\320\277\320\270\321\201\320\272\320\265", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_search->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
        action_refresh->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_refresh->setToolTip(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \321\215\320\272\321\200\320\260\320\275", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_refresh->setShortcut(QApplication::translate("MainWindow", "F5", Q_NULLPTR));
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_exit->setToolTip(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_exit->setShortcut(QApplication::translate("MainWindow", "F10", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        pushButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+.", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        pushButton_3->setShortcut(QApplication::translate("MainWindow", "Ctrl+,", Q_NULLPTR));
        menuMmetadata->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
