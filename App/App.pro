TEMPLATE = app   #工程类型
TARGET = dukiModel-app   #目标文件名称名
DESTDIR = ./exe       #目标文件位置

#RC_ICONS =./Images/logo-redblue-128.ico
OTHER_FILES += ./Images/logo/logo.rc
RC_FILE =./Images/logo/logo.rc




QT += quick serialport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target










include(../Libs/Libs.pri)
include(../Plugins/Plugins.pri)
include(../Tools/Tools.pri)
include(../Modules/Modules.pri)



#文件路径
INSTALLS += \
           $$PWD

#头文件
HEADERS += \

#源文件
SOURCES += \
        main.cpp

#资源文件
RESOURCES += qml.qrc\
             images.qrc

