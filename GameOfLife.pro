#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T08:58:45
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_LFLAGS += -stdlib=libc++

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    grid.cpp \
    filemanager.cpp \
    loader.cpp \
    gameoflife.cpp \
    rules.cpp

HEADERS  += mainwindow.h \
    grid.h \
    filemanager.h \
    loader.h \
    gameoflife.h \
    rules.h

FORMS    += mainwindow.ui

DISTFILES += \
    TODO_Kristoffer.txt
