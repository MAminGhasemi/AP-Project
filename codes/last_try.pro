QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alfalfaland.cpp \
    animal.cpp \
    aviculture.cpp \
    building.cpp \
    cow_dialog.cpp \
    farm.cpp \
    farm_page.cpp \
    field.cpp \
    gandom_dialog.cpp \
    hen_dialog.cpp \
    livestock.cpp \
    main.cpp \
    mainwindow.cpp \
    sheep_dialog.cpp \
    sheepfold.cpp \
    shop_dialog.cpp \
    silo.cpp \
    silo_dialog.cpp \
    store.cpp \
    user.cpp \
    warehouse.cpp \
    warehouse_dialog.cpp \
    wheatland.cpp \
    yonje_dialog.cpp

HEADERS += \
    alfalfaland.h \
    animal.h \
    aviculture.h \
    building.h \
    cow_dialog.h \
    farm.h \
    farm_page.h \
    field.h \
    gandom_dialog.h \
    hen_dialog.h \
    livestock.h \
    mainwindow.h \
    sheep_dialog.h \
    sheepfold.h \
    shop_dialog.h \
    silo.h \
    silo_dialog.h \
    store.h \
    user.h \
    warehouse.h \
    warehouse_dialog.h \
    wheatland.h \
    yonje_dialog.h

FORMS += \
    cow_dialog.ui \
    farm_page.ui \
    gandom_dialog.ui \
    hen_dialog.ui \
    mainwindow.ui \
    sheep_dialog.ui \
    shop_dialog.ui \
    silo_dialog.ui \
    warehouse_dialog.ui \
    yonje_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    project.qrc
