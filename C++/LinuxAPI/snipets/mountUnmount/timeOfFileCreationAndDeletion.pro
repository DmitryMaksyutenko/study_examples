TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    cmd.c \
    files.c

HEADERS += \
    cmd.h \
    files.h

