#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T01:02:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trytrysee
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    move_success.cpp \
    star.cpp \
    bomb.cpp \
    blank.cpp \
    four.cpp \
    three.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    move_success.h \
    star.h \
    bomb.h \
    blank.h \
    four.h \
    three.h \
    result.h

FORMS    += mainwindow.ui \
    result.ui

RESOURCES += \
    picture.qrc
