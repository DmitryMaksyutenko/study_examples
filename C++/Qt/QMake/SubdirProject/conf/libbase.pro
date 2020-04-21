!include(../base.pro){
  error(File base.pro not included.)
}

# Specifies the name of the template to use when generating the project.
TEMPLATE = lib

# Specifies project configuration and compiler options. The values are
# recognized internally by qmake and have special meaning.
CONFIG += warn_off

# Specifies the directory where all intermediate objects should be placed.
OBJECTS_DIR = $$ROOT_DIR/obj

# Specifies where to put the target file.
DESTDIR = $$ROOT_DIR/lib
