QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activity.cpp \
    activityhistory.cpp \
    dashboard.cpp \
    facade.cpp \
    main.cpp \
    mainmenu.cpp \
    manageactivities.cpp \
    manageprofile.cpp \
    signup.cpp \
    user.cpp \
    walk.cpp

HEADERS += \
    activity.h \
    activityhistory.h \
    dashboard.h \
    facade.h \
    mainmenu.h \
    manageactivities.h \
    manageprofile.h \
    signup.h \
    user.h \
    walk.h

FORMS += \
    activityhistory.ui \
    dashboard.ui \
    mainmenu.ui \
    manageactivities.ui \
    manageprofile.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
