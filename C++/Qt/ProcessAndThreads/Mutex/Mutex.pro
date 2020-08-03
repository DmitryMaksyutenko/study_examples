#-------------------------------------------------
#
# Project created by QtCreator 2020-08-02T13:27:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mutex
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp \
    manager.cpp

HEADERS  += mainwindow.h \
    worker.h \
    manager.h
