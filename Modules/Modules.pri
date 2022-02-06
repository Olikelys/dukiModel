

include(./Link/Link.pri)
include(./ProtocolEngine/ProtocolEngine.pri)


INCLUDEPATH += \
             $$PWD/  \



HEADERS += \
    $$PWD/RModulesConfig.h








QML2_IMPORT_PATH +=  $$PWD/
QML_IMPORT_PATH  +=  $$PWD
QML_DESIGNER_IMPORT_PATH = $$PWD
