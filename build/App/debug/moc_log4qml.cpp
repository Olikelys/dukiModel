/****************************************************************************
** Meta object code from reading C++ file 'log4qml.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Libs/RCommon/QmlLog4/log4qml.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'log4qml.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log4Qml_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log4Qml_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log4Qml_t qt_meta_stringdata_Log4Qml = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Log4Qml"
QT_MOC_LITERAL(1, 8, 14), // "setLog4QmlPath"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "log4qmlpath"
QT_MOC_LITERAL(4, 36, 14), // "setLog4QmlName"
QT_MOC_LITERAL(5, 51, 11), // "log4qmlname"
QT_MOC_LITERAL(6, 63, 14), // "getLog4QmlPath"
QT_MOC_LITERAL(7, 78, 14), // "getLog4QmlName"
QT_MOC_LITERAL(8, 93, 11), // "qDebug_Info"
QT_MOC_LITERAL(9, 105, 4), // "type"
QT_MOC_LITERAL(10, 110, 7), // "strInfo"
QT_MOC_LITERAL(11, 118, 11), // "Log4QmlPath"
QT_MOC_LITERAL(12, 130, 11) // "Log4QmlName"

    },
    "Log4Qml\0setLog4QmlPath\0\0log4qmlpath\0"
    "setLog4QmlName\0log4qmlname\0getLog4QmlPath\0"
    "getLog4QmlName\0qDebug_Info\0type\0strInfo\0"
    "Log4QmlPath\0Log4QmlName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log4Qml[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x02 /* Public */,
       4,    1,   42,    2, 0x02 /* Public */,
       6,    0,   45,    2, 0x02 /* Public */,
       7,    0,   46,    2, 0x02 /* Public */,
       8,    2,   47,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::QString, 0x00095103,

       0        // eod
};

void Log4Qml::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Log4Qml *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLog4QmlPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setLog4QmlName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: { QString _r = _t->getLog4QmlPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getLog4QmlName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->qDebug_Info((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Log4Qml *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getLog4QmlPath(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getLog4QmlName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Log4Qml *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLog4QmlPath(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLog4QmlName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Log4Qml::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Log4Qml.data,
    qt_meta_data_Log4Qml,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Log4Qml::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log4Qml::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log4Qml.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Log4Qml::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
