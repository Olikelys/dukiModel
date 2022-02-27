/****************************************************************************
** Meta object code from reading C++ file 'ROrigin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Modules/Model/ROrigin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ROrigin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ROrigin_t {
    QByteArrayData data[12];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ROrigin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ROrigin_t qt_meta_stringdata_ROrigin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ROrigin"
QT_MOC_LITERAL(1, 8, 11), // "typeChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "dateChanged"
QT_MOC_LITERAL(4, 33, 11), // "nameChanged"
QT_MOC_LITERAL(5, 45, 10), // "valChanged"
QT_MOC_LITERAL(6, 56, 16), // "agencyValChanged"
QT_MOC_LITERAL(7, 73, 9), // "QVariant&"
QT_MOC_LITERAL(8, 83, 3), // "val"
QT_MOC_LITERAL(9, 87, 4), // "type"
QT_MOC_LITERAL(10, 92, 4), // "date"
QT_MOC_LITERAL(11, 97, 4) // "name"

    },
    "ROrigin\0typeChanged\0\0dateChanged\0"
    "nameChanged\0valChanged\0agencyValChanged\0"
    "QVariant&\0val\0type\0date\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ROrigin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void ROrigin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ROrigin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typeChanged(); break;
        case 1: _t->dateChanged(); break;
        case 2: _t->nameChanged(); break;
        case 3: _t->valChanged(); break;
        case 4: _t->agencyValChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ROrigin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ROrigin::typeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ROrigin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ROrigin::dateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ROrigin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ROrigin::nameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ROrigin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ROrigin::valChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ROrigin::*)(QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ROrigin::agencyValChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ROrigin *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->type(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->date(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->val(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ROrigin *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setType(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDate(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setVal(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ROrigin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ROrigin.data,
    qt_meta_data_ROrigin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ROrigin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ROrigin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ROrigin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ROrigin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ROrigin::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ROrigin::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ROrigin::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ROrigin::valChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ROrigin::agencyValChanged(QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
