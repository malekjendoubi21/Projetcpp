QT+=sql
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer
QT       += sql network multimedia multimediawidgets charts printsupport widgets axcontainer serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    dialog_invite.cpp \
    dialog_mailing.cpp \
    dialog_stats.cpp \
    employe.cpp \
    equipement.cpp \
    gestion_employe.cpp \
    gestion_equipement.cpp \
    invite.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    notification.cpp \
    qcustomplot.cpp \
    qrcode.cpp\
    exportexcelobjet.cpp \
    gestion_programme.cpp \
    smtp.cpp \
    statistique.cpp \
    emission.cpp\
    incendie.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    dialog_invite.h \
    dialog_mailing.h \
    dialog_stats.h \
    employe.h \
    equipement.h \
    gestion_employe.h \
    gestion_equipement.h \
    invite.h \
    mainwindow.h \
    menu.h \
    notification.h \
    qcustomplot.h \
    qrcode.h\
    exportexcelobjet.h \
    emission.h \
    gestion_programme.h \
    smtp.h \
    statistique.h \
    incendie.h
FORMS += \
    dialog_invite.ui \
    dialog_mailing.ui \
    dialog_stats.ui \
    gestion_employe.ui \
    gestion_equipement.ui \
    mainwindow.ui \
    menu.ui\
    gestion_programme.ui \
    statistique.ui \
    incendie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
