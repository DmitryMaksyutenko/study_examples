! include(../../conf/libbase.pro){
  error(File libbase.pro not included)
}

HEADERS += iframe.h \
            xframe.h \
            perimeterframe.h

SOURCES += xframe.cpp \
            perimeterframe.cpp
