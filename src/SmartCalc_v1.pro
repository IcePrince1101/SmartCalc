QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qcustomplot.cpp \
    s21_calculate.c \
    s21_input_check.c \
    s21_reverse_polish_notation.c \
    s21_smart_calc.c \
    form.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
qcustomplot.h \
    s21_smart_calc.h \
    form.h \
    mainwindow.h \

FORMS += \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target