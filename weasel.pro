#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T20:41:02
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = weasel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myplayer.cpp \
    settingdialog.cpp

HEADERS  += mainwindow.h \
    myplayer.h \
    settingdialog.h

FORMS    += mainwindow.ui \
    settingdialog.ui
