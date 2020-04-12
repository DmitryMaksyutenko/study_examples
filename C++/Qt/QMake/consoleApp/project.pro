QT += core

DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE = subdirs

SUBDIRS = showmessage \
            content \
            consoleapp.pro

PRECOMPILED_HEADER = precompileConsoleApp.h

TARGET = consoleapp
