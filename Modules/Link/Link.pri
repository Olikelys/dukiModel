


#记得在pro文件上添加   Qt += serialport
INCLUDEPATH +=\
         $$PWD/

QML2_IMPORT_PATH +=  $$PWD
QML_IMPORT_PATH  +=  $$PWD
QML_DESIGNER_IMPORT_PATH = $$PWD



DEFINES +=  RLinkImportPath=$$PWD




SOURCES += \
    $$PWD/RConnectAbstract.cpp \
    $$PWD/RConnectManager.cpp \
    $$PWD/RConnectSerialPort.cpp \
    $$PWD/RConnectUdp.cpp

HEADERS += \
    $$PWD/RConnectAbstract.h \
    $$PWD/RConnectManager.h \
    $$PWD/RConnectSerialPort.h \
    $$PWD/RConneectUdp.h

DISTFILES += \



RESOURCES += \
    $$PWD/Link.qrc

