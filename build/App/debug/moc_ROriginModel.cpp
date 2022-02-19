/****************************************************************************
** Meta object code from reading C++ file 'ROriginModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Modules/Model/ROriginModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ROriginModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ROriginModel_t {
    QByteArrayData data[15];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ROriginModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ROriginModel_t qt_meta_stringdata_ROriginModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ROriginModel"
QT_MOC_LITERAL(1, 13, 26), // "ROriginModel_unPackROrigin"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "ROrigin*"
QT_MOC_LITERAL(4, 50, 10), // "tempOrigin"
QT_MOC_LITERAL(5, 61, 10), // "addROrigin"
QT_MOC_LITERAL(6, 72, 7), // "rorigin"
QT_MOC_LITERAL(7, 80, 15), // "SequentiaSearch"
QT_MOC_LITERAL(8, 96, 4), // "type"
QT_MOC_LITERAL(9, 101, 4), // "name"
QT_MOC_LITERAL(10, 106, 9), // "UpDateVal"
QT_MOC_LITERAL(11, 116, 5), // "index"
QT_MOC_LITERAL(12, 122, 4), // "time"
QT_MOC_LITERAL(13, 127, 3), // "val"
QT_MOC_LITERAL(14, 131, 11) // "QByteArray*"

    },
    "ROriginModel\0ROriginModel_unPackROrigin\0"
    "\0ROrigin*\0tempOrigin\0addROrigin\0rorigin\0"
    "SequentiaSearch\0type\0name\0UpDateVal\0"
    "index\0time\0val\0QByteArray*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ROriginModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x0a /* Public */,
       7,    2,   50,    2, 0x0a /* Public */,
       7,    2,   55,    2, 0x0a /* Public */,
      10,    3,   60,    2, 0x0a /* Public */,
      10,    3,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Int, QMetaType::UChar, QMetaType::QString,    8,    9,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QVariant,   11,   12,   13,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 14,   11,   12,   13,

       0        // eod
};

void ROriginModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ROriginModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->ROriginModel_unPackROrigin((*reinterpret_cast< ROrigin*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->addROrigin((*reinterpret_cast< ROrigin*(*)>(_a[1]))); break;
        case 2: { int _r = _t->SequentiaSearch((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->SequentiaSearch((*reinterpret_cast< const quint8(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->UpDateVal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->UpDateVal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QByteArray*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ROrigin* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ROrigin* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ROriginModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_ROriginModel.data,
    qt_meta_data_ROriginModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ROriginModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ROriginModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ROriginModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ROriginModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
