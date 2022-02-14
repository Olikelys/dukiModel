/****************************************************************************
** Meta object code from reading C++ file 'GlobalState.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../App/GlobalState.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlobalState.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GlobalState_t {
    QByteArrayData data[14];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GlobalState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GlobalState_t qt_meta_stringdata_GlobalState = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GlobalState"
QT_MOC_LITERAL(1, 12, 14), // "RunTimeChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "LinkTimeChanged"
QT_MOC_LITERAL(4, 44, 25), // "TotalMessageNumberChanged"
QT_MOC_LITERAL(5, 70, 23), // "TotalImageNumberChanged"
QT_MOC_LITERAL(6, 94, 17), // "MessageFpsChanged"
QT_MOC_LITERAL(7, 112, 15), // "ImageFpsChanged"
QT_MOC_LITERAL(8, 128, 7), // "runTime"
QT_MOC_LITERAL(9, 136, 8), // "linkTime"
QT_MOC_LITERAL(10, 145, 18), // "totalMessageNumber"
QT_MOC_LITERAL(11, 164, 16), // "totalImageNumber"
QT_MOC_LITERAL(12, 181, 10), // "messageFps"
QT_MOC_LITERAL(13, 192, 8) // "imageFps"

    },
    "GlobalState\0RunTimeChanged\0\0LinkTimeChanged\0"
    "TotalMessageNumberChanged\0"
    "TotalImageNumberChanged\0MessageFpsChanged\0"
    "ImageFpsChanged\0runTime\0linkTime\0"
    "totalMessageNumber\0totalImageNumber\0"
    "messageFps\0imageFps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobalState[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       6,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   80,    2, 0x02 /* Public */,
       9,    0,   81,    2, 0x02 /* Public */,
      10,    0,   82,    2, 0x02 /* Public */,
      11,    0,   83,    2, 0x02 /* Public */,
      12,    0,   84,    2, 0x02 /* Public */,
      13,    0,   85,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Float,
    QMetaType::Float,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495001,
       9, QMetaType::QString, 0x00495001,
      10, QMetaType::Int, 0x00495001,
      11, QMetaType::Int, 0x00495001,
      12, QMetaType::Float, 0x00495001,
      13, QMetaType::Float, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void GlobalState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GlobalState *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RunTimeChanged(); break;
        case 1: _t->LinkTimeChanged(); break;
        case 2: _t->TotalMessageNumberChanged(); break;
        case 3: _t->TotalImageNumberChanged(); break;
        case 4: _t->MessageFpsChanged(); break;
        case 5: _t->ImageFpsChanged(); break;
        case 6: { QString _r = _t->runTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->linkTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->totalMessageNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->totalImageNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { float _r = _t->messageFps();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 11: { float _r = _t->imageFps();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GlobalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalState::RunTimeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GlobalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalState::LinkTimeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GlobalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalState::TotalMessageNumberChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GlobalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalState::TotalImageNumberChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GlobalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalState::MessageFpsChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GlobalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GlobalState::ImageFpsChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<GlobalState *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->runTime(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->linkTime(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->totalMessageNumber(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->totalImageNumber(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->messageFps(); break;
        case 5: *reinterpret_cast< float*>(_v) = _t->imageFps(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject GlobalState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GlobalState.data,
    qt_meta_data_GlobalState,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GlobalState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlobalState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GlobalState.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GlobalState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GlobalState::RunTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GlobalState::LinkTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GlobalState::TotalMessageNumberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GlobalState::TotalImageNumberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GlobalState::MessageFpsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GlobalState::ImageFpsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
