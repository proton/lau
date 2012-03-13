#-------------------------------------------------
#
# Project created by QtCreator 2012-03-13T10:25:51
#
#-------------------------------------------------

QT       += core gui sql

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    adddialog.cpp \
    dao.cpp

HEADERS  += mainwindow.h \
    settings.h \
    adddialog.h \
    dao.h

FORMS    += mainwindow.ui \
    settings.ui \
    adddialog.ui

OTHER_FILES += \
    Resource/StatStacMct.ico \
    Resource/PokoyMCT.ico \
    Resource/MainSestStacMCT.ico \
    Resource/LgRecept.ico \
    Resource/LgAdmin.ico \
    Resource/EconMCT.ico \
    Resource/AdmStat.ico

RESOURCES += \
    icons.qrc
