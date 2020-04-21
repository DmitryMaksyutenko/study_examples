!include(../../conf/libbase.pro){
  error(File libbase.pro nor found.)
}

HEADERS += iwheels.h \
            enkel.h \
            aloca.h

SOURCES += enkel.cpp \
            aloca.cpp
