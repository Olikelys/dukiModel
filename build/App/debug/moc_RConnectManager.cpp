/****************************************************************************
** Meta object code from reading C++ file 'RConnectManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Modules/Link/RConnectManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RConnectManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RLink__RConnectManager_t {
    QByteArrayData data[22];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RLink__RConnectManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RLink__RConnectManager_t qt_meta_stringdata_RLink__RConnectManager = {
    {
QT_MOC_LITERAL(0, 0, 22), // "RLink::RConnectManager"
QT_MOC_LITERAL(1, 23, 20), // "sigGetSerialPortName"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 20), // "sigSetSerialPortName"
QT_MOC_LITERAL(4, 66, 18), // "serialPortNameList"
QT_MOC_LITERAL(5, 85, 12), // "sigReadyRead"
QT_MOC_LITERAL(6, 98, 25), // "connectDataSourcesChanged"
QT_MOC_LITERAL(7, 124, 20), // "m_connectDataSources"
QT_MOC_LITERAL(8, 145, 18), // "connectStateChaged"
QT_MOC_LITERAL(9, 164, 14), // "m_connectState"
QT_MOC_LITERAL(10, 179, 7), // "Connect"
QT_MOC_LITERAL(11, 187, 8), // "portName"
QT_MOC_LITERAL(12, 196, 8), // "baudRate"
QT_MOC_LITERAL(13, 205, 8), // "dataBits"
QT_MOC_LITERAL(14, 214, 6), // "parity"
QT_MOC_LITERAL(15, 221, 8), // "stopBits"
QT_MOC_LITERAL(16, 230, 11), // "flowControl"
QT_MOC_LITERAL(17, 242, 10), // "DisConnect"
QT_MOC_LITERAL(18, 253, 4), // "Read"
QT_MOC_LITERAL(19, 258, 5), // "Write"
QT_MOC_LITERAL(20, 264, 18), // "connectDataSources"
QT_MOC_LITERAL(21, 283, 12) // "connectState"

    },
    "RLink::RConnectManager\0sigGetSerialPortName\0"
    "\0sigSetSerialPortName\0serialPortNameList\0"
    "sigReadyRead\0connectDataSourcesChanged\0"
    "m_connectDataSources\0connectStateChaged\0"
    "m_connectState\0Connect\0portName\0"
    "baudRate\0dataBits\0parity\0stopBits\0"
    "flowControl\0DisConnect\0Read\0Write\0"
    "connectDataSources\0connectState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RLink__RConnectManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    1,   65,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,
       6,    1,   69,    2, 0x06 /* Public */,
       8,    1,   72,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   75,    2, 0x02 /* Public */,
      10,    6,   76,    2, 0x02 /* Public */,
      17,    0,   89,    2, 0x02 /* Public */,
      18,    0,   90,    2, 0x02 /* Public */,
      19,    0,   91,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,   16,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

 // properties: name, type, flags
      20, QMetaType::Int, 0x00495103,
      21, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       3,
       4,

       0        // eod
};

void RLink::RConnectManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RConnectManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigGetSerialPortName(); break;
        case 1: _t->sigSetSerialPortName((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->sigReadyRead(); break;
        case 3: _t->connectDataSourcesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->connectStateChaged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { int _r = _t->Connect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->Connect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->DisConnect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->Read();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->Write();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RConnectManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::sigGetSerialPortName)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::sigSetSerialPortName)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::sigReadyRead)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::connectDataSourcesChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::connectStateChaged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<RConnectManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getConnectDataSources(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getConnectState(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<RConnectManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setConnectDataSources(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setConnectState(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject RLink::RConnectManager::staticMetaObject = { {
    QMetaObject::SuperData::link<RConnectAbstract::staticMetaObject>(),
    qt_meta_stringdata_RLink__RConnectManager.data,
    qt_meta_data_RLink__RConnectManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RLink::RConnectManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RLink::RConnectManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RLink__RConnectManager.stringdata0))
        return static_cast<void*>(this);
    return RConnectAbstract::qt_metacast(_clname);
}

int RLink::RConnectManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RConnectAbstract::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RLink::RConnectManager::sigGetSerialPortName()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RLink::RConnectManager::sigSetSerialPortName(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RLink::RConnectManager::sigReadyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RLink::RConnectManager::connectDataSourcesChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RLink::RConnectManager::connectStateChaged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
