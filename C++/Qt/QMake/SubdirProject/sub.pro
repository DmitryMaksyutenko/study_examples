! include(conf/appbase.pro){
  error(File appbase.pro not included)
}

# Defines the header files for the project.
HEADERS += src/carframe/iframe.h \
           src/carframe/xframe.h \
           src/carwheels/iwheels.h \
           src/carframe/perimeterframe.h \
           src/carwheels/aloca.h \
           src/carwheels/enkel.h \
           src/carfactory/icar.h \
           src/carfactory/ferrari.h \
           src/carfactory/bmw.h

# Specifies the names of all source files in the project.
SOURCES += src/carframe/xframe.cpp \
           src/carframe/perimeterframe.cpp \
           src/carwheels/aloca.cpp \
           src/carwheels/enkel.cpp \
           src/carfactory/ferrari.cpp \
           src/carfactory/bmw.cpp \
           main.cpp \

# Specifies the name of the target file. Contains the base name of the project file by default.
TARGET = abstract_factory
