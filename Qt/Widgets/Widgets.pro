#-------------------------------------------------
#
# Project created by QtCreator 2016-10-07T16:31:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Widgets
TEMPLATE = app
CONFIG += debug


SOURCES += main.cpp \
    mywindow.cpp \
    hyper_sphere.cpp \
    singleton_no_ntfns.cpp

HEADERS  += \
    mywindow.h \
    list.h \
    hyper_sphere.h \
    singleton_no_ntfns.h

FORMS += \
    dialog.ui \
    mainwindow.ui

