#-------------------------------------------------
#
# Project created by QtCreator 2015-06-19T09:27:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    horizontal.cpp \
    vertical.cpp \
    ninebox.cpp \
    delete_blank.cpp \
    star.cpp \
    normal_delete.cpp

HEADERS  += mainwindow.h \
    blank.h \
    horizontal.h \
    vertical.h \
    ninebox.h \
    delete_blank.h \
    star.h \
    normal_delete.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc
