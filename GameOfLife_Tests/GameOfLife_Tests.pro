include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
CONFIG += static exceptions
CONFIG -= debug_and_release

HEADERS += \
        tst_golneighbourcntcheck.h

SOURCES += \
        main.cpp

INCLUDEPATH += \
    ../GameOfLife
