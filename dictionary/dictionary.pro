#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T11:03:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dictionary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbviewer.cpp \
    dbcontroler.cpp \
    prelearnwords.cpp

HEADERS  += mainwindow.h \
    dbviewer.h \
    dbcontroler.h \
    prelearnwords.h

FORMS    += mainwindow.ui
