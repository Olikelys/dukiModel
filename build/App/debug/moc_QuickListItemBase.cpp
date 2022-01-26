/****************************************************************************
** Meta object code from reading C++ file 'QuickListItemBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Libs/3rdparty/TaoCommon/QuickModel/QuickListItemBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuickListItemBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QuickListItemBase_t {
    QByteArrayData data[14];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuickListItemBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuickListItemBase_t qt_meta_stringdata_QuickListItemBase = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QuickListItemBase"
QT_MOC_LITERAL(1, 18, 16), // "isCheckedChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "isChecked"
QT_MOC_LITERAL(4, 46, 17), // "isSelectedChanged"
QT_MOC_LITERAL(5, 64, 10), // "isSelected"
QT_MOC_LITERAL(6, 75, 16), // "isVisibleChanged"
QT_MOC_LITERAL(7, 92, 9), // "isVisible"
QT_MOC_LITERAL(8, 102, 18), // "isAlternateChanged"
QT_MOC_LITERAL(9, 121, 11), // "isAlternate"
QT_MOC_LITERAL(10, 133, 12), // "setIsChecked"
QT_MOC_LITERAL(11, 146, 13), // "setIsSelected"
QT_MOC_LITERAL(12, 160, 12), // "setIsVisible"
QT_MOC_LITERAL(13, 173, 14) // "setIsAlternate"

    },
    "QuickListItemBase\0isCheckedChanged\0\0"
    "isChecked\0isSelectedChanged\0isSelected\0"
    "isVisibleChanged\0isVisible\0"
    "isAlternateChanged\0isAlternate\0"
    "setIsChecked\0setIsSelected\0setIsVisible\0"
    "setIsAlternate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickListItemBase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   66,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495103,
       5, QMetaType::Bool, 0x00495103,
       7, QMetaType::Bool, 0x00495103,
       9, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void QuickListItemBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QuickListItemBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isCheckedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->isSelectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->isVisibleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->isAlternateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setIsChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setIsSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setIsVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setIsAlternate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QuickListItemBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuickListItemBase::isCheckedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QuickListItemBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuickListItemBase::isSelectedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QuickListItemBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuickListItemBase::isVisibleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QuickListItemBase::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuickListItemBase::isAlternateChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QuickListItemBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isChecked(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isSelected(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isVisible(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isAlternate(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QuickListItemBase *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIsChecked(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setIsSelected(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setIsVisible(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setIsAlternate(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QuickListItemBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QuickListItemBase.data,
    qt_meta_data_QuickListItemBase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QuickListItemBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickListItemBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QuickListItemBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuickListItemBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void QuickListItemBase::isCheckedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QuickListItemBase::isSelectedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QuickListItemBase::isVisibleChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QuickListItemBase::isAlternateChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
