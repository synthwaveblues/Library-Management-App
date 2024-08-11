QT       += core gui
QT += widgets gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activitylist.cpp \
    adminpanel.cpp \
    book.cpp \
    bookmanager.cpp \
    main.cpp \
    userpanel.cpp \
    welcome.cpp

HEADERS += \
    activitylist.h \
    adminpanel.h \
    book.h \
    bookmanager.h \
    userpanel.h \
    welcome.h

FORMS += \
    activitylist.ui \
    adminpanel.ui \
    userpanel.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    admins.txt \
    books.txt \
    users.txt \
    usersBooks.txt
