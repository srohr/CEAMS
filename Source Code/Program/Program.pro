#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T14:05:49
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Program
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    PopUp.cpp \
    dialog2.cpp \
    tutorial.cpp \
    choosechar.cpp \
    ddmath.cpp \
    Character.cpp \
    Class.cpp \
    Feat.cpp \
    DBIO.cpp \
    LoadFromDB.cpp \
    sqlite3.c

HEADERS  += mainwindow.h \
    dialog.h \
    dialog2.h \
    tutorial.h \
    choosechar.h \
    ddmath.h \
    Character.h \
    Class.h \
    Feat.h \
    Item.h \
    Race.h \
    Skill.h \
    Spell.h \
    sqlite3.h \
    sqlite3ext.h \
    DBIO.h \
    Religion.h \
    Alignment.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui \
    tutorial.ui \
    choosechar.ui
