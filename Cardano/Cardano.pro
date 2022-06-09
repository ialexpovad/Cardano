QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cardano
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
        src/exception.cpp \
        src/abortwindow.cpp \
        src/matrix.cpp \
        src/mybutton.cpp \
        src/squarematrix.cpp \
        src/r_vector.cpp \
        src/vector.cpp \
        src/c_vector.cpp \
        src/basic_operations.cpp

HEADERS += \
        include/mainwindow.h \
        include/version.h \
        include/exception.h \
        include/abortwindow.h \
        include/matrix.h \
        include/mybutton.h \
        include/squarematrix.h \
        include/r_vector.h \
        include/vector.h \
        include/c_vector.h \
        include/basic_operations.h

FORMS += \
        forms/mainwindow.ui \
        forms/abortwindow.ui

DISTFILES += \
        ../README.md \
        CMakeLists.txt
RESOURCES +=\
        res/res.qrc
