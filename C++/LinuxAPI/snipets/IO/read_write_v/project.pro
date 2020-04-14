DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += console
CONFIG += debug

HEADERS += src/read_write_v.h

SOURCES += main.c \
            src/read_write_v.c

DESTDIR = "bin"

TARGET = rwv