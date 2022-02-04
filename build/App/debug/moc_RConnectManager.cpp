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
    QByteArrayData data[12];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RLink__RConnectManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RLink__RConnectManager_t qt_meta_stringdata_RLink__RConnectManager = {
    {
QT_MOC_LITERAL(0, 0, 22), // "RLink::RConnectManager"
QT_MOC_LITERAL(1, 23, 7), // "Connect"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "portName"
QT_MOC_LITERAL(4, 41, 8), // "baudRate"
QT_MOC_LITERAL(5, 50, 8), // "dataBits"
QT_MOC_LITERAL(6, 59, 6), // "parity"
QT_MOC_LITERAL(7, 66, 8), // "stopBits"
QT_MOC_LITERAL(8, 75, 11), // "flowControl"
QT_MOC_LITERAL(9, 87, 10), // "DisConnect"
QT_MOC_LITERAL(10, 98, 4), // "Read"
QT_MOC_LITERAL(11, 103, 5) // "Write"

    },
    "RLink::RConnectManager\0Connect\0\0"
    "portName\0baudRate\0dataBits\0parity\0"
    "stopBits\0flowControl\0DisConnect\0Read\0"
    "Write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RLink__RConnectManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x02 /* Public */,
       1,    6,   40,    2, 0x02 /* Public */,
       9,    0,   53,    2, 0x02 /* Public */,
      10,    0,   54,    2, 0x02 /* Public */,
      11,    0,   55,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void RLink::RConnectManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RConnectManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->Connect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->Connect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->DisConnect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->Read();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->Write();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
