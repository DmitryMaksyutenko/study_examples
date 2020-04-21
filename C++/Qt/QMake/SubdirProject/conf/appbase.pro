!include(../base.pro){
  error(File base.pro not included.)
}

# Specifies the name of the template to use when generating the project.
TEMPLATE = app

CONFIG += warn_off

# Specifies a list of library search paths for all projects.
QMAKE_LIBDIR += $$ROOT_DIR/lib

# Specifies the directory where all intermediate objects should be placed.
OBJECTS_DIR = $$ROOT_DIR/obj

# Specifies where to put the target file.
DESTDIR = $$ROOT_DIR/bin

