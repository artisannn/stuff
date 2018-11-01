#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T14:47:10
#
#-------------------------------------------------

QT       += core gui sql widgets qml printsupport

TARGET = ma_user
TEMPLATE = lib
CONFIG += plugin

DEFINES += MA_USER_LIBRARY

SOURCES += ma_user.cpp

HEADERS +=\
    ma_user.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lxobjects
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lxobjects
else:unix: LIBS += -L$$PWD/../../bin/ -lxobjects

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -ldb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -ldb
else:unix: LIBS += -L$$PWD/../../bin/ -ldb

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lmdlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lmdlib
else:unix: LIBS += -L$$PWD/../../bin/ -lmdlib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lbasePluginDocument
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lbasePluginDocument
else:unix: LIBS += -L$$PWD/../../bin/ -lbasePluginDocument

INCLUDEPATH += $$PWD/../../bin/include/xobjects \
               $$PWD/../../bin/include/db \
               $$PWD/../../bin/include/mdlib \
               $$PWD/../../bin/include/plugins

DEPENDPATH += $$PWD/../../bin/include/xobjects \
              $$PWD/../../bin/include/db \
              $$PWD/../../bin/include/mdlib \
              $$PWD/../../bin/include/plugins


DESTDIR = $$PWD/../../bin
