#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T10:24:38
#
#-------------------------------------------------

QT       += core gui\
            webkit
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VennPainter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    LinSetClass.cpp \
    LinSvg.cpp

HEADERS  += mainwindow.h \
    LinSetClass.h \
    LinSvg.h \
    values.h

FORMS    += mainwindow.ui

RESOURCES += \
    VennPainter.qrc

RC_FILE += \
    icon.rc
