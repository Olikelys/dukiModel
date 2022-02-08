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
    QByteArrayData data[29];
    char stringdata0[381];
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
QT_MOC_LITERAL(6, 98, 8), // "sigWrite"
QT_MOC_LITERAL(7, 107, 11), // "QByteArray&"
QT_MOC_LITERAL(8, 119, 11), // "writebuffer"
QT_MOC_LITERAL(9, 131, 25), // "connectDataSourcesChanged"
QT_MOC_LITERAL(10, 157, 20), // "m_connectDataSources"
QT_MOC_LITERAL(11, 178, 18), // "connectStateChaged"
QT_MOC_LITERAL(12, 197, 14), // "m_connectState"
QT_MOC_LITERAL(13, 212, 13), // "sigReadBuffer"
QT_MOC_LITERAL(14, 226, 11), // "QByteArray*"
QT_MOC_LITERAL(15, 238, 19), // "newQByteArraybuffer"
QT_MOC_LITERAL(16, 258, 7), // "Connect"
QT_MOC_LITERAL(17, 266, 8), // "portName"
QT_MOC_LITERAL(18, 275, 8), // "baudRate"
QT_MOC_LITERAL(19, 284, 8), // "dataBits"
QT_MOC_LITERAL(20, 293, 6), // "parity"
QT_MOC_LITERAL(21, 300, 8), // "stopBits"
QT_MOC_LITERAL(22, 309, 11), // "flowControl"
QT_MOC_LITERAL(23, 321, 10), // "DisConnect"
QT_MOC_LITERAL(24, 332, 4), // "Read"
QT_MOC_LITERAL(25, 337, 5), // "Write"
QT_MOC_LITERAL(26, 343, 5), // "slots"
QT_MOC_LITERAL(27, 349, 18), // "connectDataSources"
QT_MOC_LITERAL(28, 368, 12) // "connectState"

    },
    "RLink::RConnectManager\0sigGetSerialPortName\0"
    "\0sigSetSerialPortName\0serialPortNameList\0"
    "sigReadyRead\0sigWrite\0QByteArray&\0"
    "writebuffer\0connectDataSourcesChanged\0"
    "m_connectDataSources\0connectStateChaged\0"
    "m_connectState\0sigReadBuffer\0QByteArray*\0"
    "newQByteArraybuffer\0Connect\0portName\0"
    "baudRate\0dataBits\0parity\0stopBits\0"
    "flowControl\0DisConnect\0Read\0Write\0"
    "slots\0connectDataSources\0connectState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RLink__RConnectManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       2,  116, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       5,    0,   83,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,
       9,    1,   87,    2, 0x06 /* Public */,
      11,    1,   90,    2, 0x06 /* Public */,
      13,    1,   93,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      16,    0,   96,    2, 0x02 /* Public */,
      16,    6,   97,    2, 0x02 /* Public */,
      23,    0,  110,    2, 0x02 /* Public */,
      24,    0,  111,    2, 0x02 /* Public */,
      25,    0,  112,    2, 0x02 /* Public */,
      25,    1,  113,   26, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   18,   19,   20,   21,   22,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 7,    8,

 // properties: name, type, flags
      27, QMetaType::Int, 0x00495103,
      28, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       4,
       5,

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
        case 3: _t->sigWrite((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->connectDataSourcesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->connectStateChaged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sigReadBuffer((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 7: { int _r = _t->Connect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->Connect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->DisConnect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->Read();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->Write();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->Write((*reinterpret_cast< QByteArray(*)>(_a[1])));
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
            using _t = void (RConnectManager::*)(QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::sigWrite)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::connectDataSourcesChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::connectStateChaged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (RConnectManager::*)(QByteArray * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectManager::sigReadBuffer)) {
                *result = 6;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
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
void RLink::RConnectManager::sigWrite(QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RLink::RConnectManager::connectDataSourcesChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RLink::RConnectManager::connectStateChaged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RLink::RConnectManager::sigReadBuffer(QByteArray * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
