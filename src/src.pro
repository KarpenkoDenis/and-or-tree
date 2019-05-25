#-------------------------------------------------
#
# Project created by QtCreator 2019-03-09T23:19:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        container/node.cpp \
        container/statemanager.cpp \
        container/tree.cpp \
        container/treeiterator.cpp \
        main.cpp \
        search.cpp \
        widget/listlinewidget.cpp \
        widget/nodeeditor.cpp \
        window/addtreepopup.cpp \
        window/mainwindow.cpp

HEADERS += \
        container/node.h \
        container/statemanager.h \
        container/tree.h \
        container/treeiterator.h \
        widget/listlinewidget.h \
        widget/nodeeditor.h \
        window/addtreepopup.h \
        window/mainwindow.h

FORMS += \
        window/addtreepopup.ui \
        window/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
