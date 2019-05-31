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
        container/domain/node.cpp \
        container/domain/tree.cpp \
        container/exception/treeexception.cpp \
        container/treeiterator.cpp \
        main.cpp \
        service/search.cpp \
        service/statemanager.cpp \
        widget/edge.cpp \
        widget/graphwidget.cpp \
        widget/listview/listlinewidget.cpp \
        widget/listview/listviewboxlayout.cpp \
        widget/nodeeditor.cpp \
        widget/nodetreegraph.cpp \
        widget/search/searchcriteriaboxlayout.cpp \
        widget/search/searchcriteriawidget.cpp \
        widget/search/searchresultboxlayout.cpp \
        widget/treenode.cpp \
        window/addtreepopup.cpp \
        window/mainwindow.cpp

HEADERS += \
        container/allocator.h \
        container/domain/node.h \
        container/domain/tree.h \
        container/exception/treeexception.h \
        container/treeiterator.h \
        service/search.h \
        service/statemanager.h \
        widget/edge.h \
        widget/graphwidget.h \
        widget/listview/listlinewidget.h \
        widget/listview/listviewboxlayout.h \
        widget/nodeeditor.h \
        widget/nodetreegraph.h \
        widget/search/searchcriteriaboxlayout.h \
        widget/search/searchcriteriawidget.h \
        widget/search/searchresultboxlayout.h \
        widget/treenode.h \
        window/addtreepopup.h \
        window/mainwindow.h

FORMS += \
        window/addtreepopup.ui \
        window/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
