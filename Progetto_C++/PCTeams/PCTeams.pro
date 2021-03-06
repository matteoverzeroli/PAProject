QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/loginform/loginform.cpp \
    $$PWD/user/userrepository.cpp \
    operation/operation.cpp \
    operation/operationrepository.cpp \
    team/team.cpp \
    team/teamrepository.cpp \
    user/administrator.cpp \
    user/foreman.cpp \
    user/user.cpp \
    main.cpp \
    $$PWD/mainwindow/mainwindow.cpp \
    user/volunteer.cpp

HEADERS += \
    $$PWD/user/userrepository.h \
    $$PWD/loginform/loginform.h \
    $$PWD/mainwindow/mainwindow.h \
    helpers.h \
    operation/color.h \
    operation/operation.h \
    operation/operationrepository.h \
    team/team.h \
    team/teamrepository.h \
    user/administrator.h \
    user/foreman.h \
    user/user.h \
    user/volunteer.h

FORMS += \
    $$PWD/loginform/loginform.ui \
    $$PWD/mainwindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

QT += positioning
