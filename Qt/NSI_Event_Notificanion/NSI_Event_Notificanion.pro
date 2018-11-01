#-------------------------------------------------
#
# Project created by QtCreator 2017-05-31T15:04:21
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NSI_Event_Notificanion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/../../bin/include/xobjects \
               $$PWD/../../bin/include/db \
               $$PWD/../../bin/include/mdlib \
               $$PWD/../../bin/include/plugins\

DEPENDPATH += $$PWD/../../bin/include/xobjects \
              $$PWD/../../bin/include/db \
              $$PWD/../../bin/include/mdlib \
              $$PWD/../../bin/include/plugins

SOURCES += main.cpp\
    notification_box.cpp \
    notification_window.cpp \
    settings_form.cpp

HEADERS  += \
    notification_box.h \
    notification_window.h \
    settings_form.h \
    notification_modes.h

FORMS    += \
    notification_box.ui \
    notification_window.ui \
    settings_form.ui

DESTDIR = $$PWD/../../bin

RESOURCES += \
    icons.qrc
RC_FILE = NSI_Event_Notificanion.rc
