#-------------------------------------------------
#
# Project created by QtCreator 2015-07-27T12:47:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alarm
TEMPLATE = app


SOURCES += main.cpp\
        alarmwindow.cpp \
    alarmtask.cpp \
    alarmrepository.cpp

HEADERS  += alarmwindow.h \
    alarmtask.h \
    alarmrepository.h

FORMS    += alarmwindow.ui
