TEMPLATE = subdirs

# Specifies the names of all subdirectories or project files that contain parts of the project
# that need to be built. Each subdirectory specified using this variable must contain its own project file.
SUBDIRS += src/carframe \
            src/carwheels \
            src/carfactory \
            sub.pro

# Indicates the header file for creating a precompiled header file, to increase the compilation speed of a project.
PRECOMPILED_HEADER = precompiled.h
