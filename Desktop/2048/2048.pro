#-------------------------------------------------
#
# Project created by QtCreator 2015-05-27T00:06:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        start.cpp \
    game.cpp \
    result.cpp

HEADERS  += start.h \
    game.h \
    result.h

FORMS    += start.ui \
    game.ui \
    result.ui

RESOURCES += \
    res.qrc
