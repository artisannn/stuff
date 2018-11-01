#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T16:51:43
#
#-------------------------------------------------

QT += xml core gui widgets sql
CONFIG += no_lflags_merge
#CONFIG += debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mmetadata
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -ldfProcess
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -ldfProcess
else:unix: LIBS += -L$$PWD/../../bin/ -ldfProcess
LIBS += -L$$PWD/../../bin/ -ldfProcess

INCLUDEPATH += $$PWD/../../bin/include/xobjects \
               $$PWD/../../bin/include/db \
               $$PWD/../../bin/include/mdlib \
               $$PWD/../../bin/include/plugins\
               $$PWD C:/Qt/Qt5.8.0/5.8/msvc2015_64/include/QtXml\



DEPENDPATH += $$PWD/../../bin/include/xobjects \
              $$PWD/../../bin/include/db \
              $$PWD/../../bin/include/mdlib \
              $$PWD/../../bin/include/plugins


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RC_FILE = Metadata.rc
