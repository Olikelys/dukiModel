/****************************************************************************
** Meta object code from reading C++ file 'RConnectSerialPort.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Modules/Link/RConnectSerialPort.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RConnectSerialPort.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RLink__RConnectSerialPort_t {
    QByteArrayData data[14];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RLink__RConnectSerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RLink__RConnectSerialPort_t qt_meta_stringdata_RLink__RConnectSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 25), // "RLink::RConnectSerialPort"
QT_MOC_LITERAL(1, 26, 20), // "sigGetSerialPortName"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 20), // "sigSetSerialPortName"
QT_MOC_LITERAL(4, 69, 14), // "serialPortName"
QT_MOC_LITERAL(5, 84, 12), // "sigReadyRead"
QT_MOC_LITERAL(6, 97, 13), // "sigReadBuffer"
QT_MOC_LITERAL(7, 111, 11), // "QByteArray*"
QT_MOC_LITERAL(8, 123, 19), // "newQByteArraybuffer"
QT_MOC_LITERAL(9, 143, 21), // "SlotGetSerialPortName"
QT_MOC_LITERAL(10, 165, 13), // "SlotReadyRead"
QT_MOC_LITERAL(11, 179, 5), // "Write"
QT_MOC_LITERAL(12, 185, 11), // "QByteArray&"
QT_MOC_LITERAL(13, 197, 11) // "writebuffer"

    },
    "RLink::RConnectSerialPort\0"
    "sigGetSerialPortName\0\0sigSetSerialPortName\0"
    "serialPortName\0sigReadyRead\0sigReadBuffer\0"
    "QByteArray*\0newQByteArraybuffer\0"
    "SlotGetSerialPortName\0SlotReadyRead\0"
    "Write\0QByteArray&\0writebuffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RLink__RConnectSerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   57,    2, 0x0a /* Public */,
      10,    0,   58,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 12,   13,

       0        // eod
};

void RLink::RConnectSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RConnectSerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigGetSerialPortName(); break;
        case 1: _t->sigSetSerialPortName((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->sigReadyRead(); break;
        case 3: _t->sigReadBuffer((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 4: { int _r = _t->SlotGetSerialPortName();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->SlotReadyRead();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->Write((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RConnectSerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectSerialPort::sigGetSerialPortName)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RConnectSerialPort::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectSerialPort::sigSetSerialPortName)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RConnectSerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectSerialPort::sigReadyRead)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RConnectSerialPort::*)(QByteArray * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RConnectSerialPort::sigReadBuffer)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RLink::RConnectSerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<RConnectAbstract::staticMetaObject>(),
    qt_meta_stringdata_RLink__RConnectSerialPort.data,
    qt_meta_data_RLink__RConnectSerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RLink::RConnectSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RLink::RConnectSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RLink__RConnectSerialPort.stringdata0))
        return static_cast<void*>(this);
    return RConnectAbstract::qt_metacast(_clname);
}

int RLink::RConnectSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RConnectAbstract::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RLink::RConnectSerialPort::sigGetSerialPortName()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RLink::RConnectSerialPort::sigSetSerialPortName(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RLink::RConnectSerialPort::sigReadyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RLink::RConnectSerialPort::sigReadBuffer(QByteArray * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
