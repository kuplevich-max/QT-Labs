QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    area.cpp \
    circle.cpp \
    ellipse.cpp \
    main.cpp \
    mainwindow.cpp \
    polygon.cpp \
    quadro.cpp \
    rectan.cpp \
    rombus.cpp \
    star.cpp \
    triangle.cpp \
    utils.cpp

HEADERS += \
    area.h \
    circle.h \
    ellipse.h \
    figure.h \
    mainwindow.h \
    polygon.h \
    quadro.h \
    rectan.h \
    rombus.h \
    star.h \
    triangle.h \
    utils.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
