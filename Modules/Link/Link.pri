


#记得在pro文件上添加   Qt += serialport
INCLUDEPATH +=\
         $$PWD



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
    $$PWD/RConnectManagerView.qml

