CONFIG += debug

PRECOMPILED_HEADER += precompiledHello.h

TARGET = helloQMake

HEADER += class.h

SOURCES += main.cpp \
          class.cpp

exists(main.cpp){
  message("main.cpp exists")
}
