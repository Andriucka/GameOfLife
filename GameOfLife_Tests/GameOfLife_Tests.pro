include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
CONFIG += static exceptions
CONFIG -= debug_and_release

HEADERS += \
        ../GameOfLife/cell.h \
        tst_golneighbourcntcheck.h \
        ../GameOfLife/gameoflife.h

INCLUDEPATH += C:\Qt\Tools\mingw810_64\lib\gcc\x86_64-w64-mingw32\8.1.0\include \
            ../GameOfLife
SOURCES += main.cpp \
    ../GameOfLife/gameoflife.cpp \
    ../GameOfLife/cell.cpp

SUBDIRS += \
    ../GameOfLife/GameOfLife.pro

RESOURCES += \
    ../GameOfLife/qml.qrc

DISTFILES += \
    ../GameOfLife/main.qml
