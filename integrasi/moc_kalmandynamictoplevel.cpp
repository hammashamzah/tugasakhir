/****************************************************************************
** Meta object code from reading C++ file 'kalmandynamictoplevel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kalmandynamictoplevel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kalmandynamictoplevel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KalmanDynamicTopLevel_t {
    QByteArrayData data[7];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KalmanDynamicTopLevel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KalmanDynamicTopLevel_t qt_meta_stringdata_KalmanDynamicTopLevel = {
    {
QT_MOC_LITERAL(0, 0, 21), // "KalmanDynamicTopLevel"
QT_MOC_LITERAL(1, 22, 13), // "sendtoKalman1"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "QList<Player>"
QT_MOC_LITERAL(4, 51, 13), // "sendPredictor"
QT_MOC_LITERAL(5, 65, 12), // "sendPrevious"
QT_MOC_LITERAL(6, 78, 13) // "getMappedData"

    },
    "KalmanDynamicTopLevel\0sendtoKalman1\0"
    "\0QList<Player>\0sendPredictor\0sendPrevious\0"
    "getMappedData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KalmanDynamicTopLevel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void KalmanDynamicTopLevel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KalmanDynamicTopLevel *_t = static_cast<KalmanDynamicTopLevel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendtoKalman1((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 1: _t->sendPredictor((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 2: _t->sendPrevious((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 3: _t->getMappedData((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KalmanDynamicTopLevel::*_t)(QList<Player> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KalmanDynamicTopLevel::sendtoKalman1)) {
                *result = 0;
            }
        }
        {
            typedef void (KalmanDynamicTopLevel::*_t)(QList<Player> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KalmanDynamicTopLevel::sendPredictor)) {
                *result = 1;
            }
        }
        {
            typedef void (KalmanDynamicTopLevel::*_t)(QList<Player> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KalmanDynamicTopLevel::sendPrevious)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject KalmanDynamicTopLevel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KalmanDynamicTopLevel.data,
      qt_meta_data_KalmanDynamicTopLevel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KalmanDynamicTopLevel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KalmanDynamicTopLevel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KalmanDynamicTopLevel.stringdata0))
        return static_cast<void*>(const_cast< KalmanDynamicTopLevel*>(this));
    return QObject::qt_metacast(_clname);
}

int KalmanDynamicTopLevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void KalmanDynamicTopLevel::sendtoKalman1(QList<Player> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KalmanDynamicTopLevel::sendPredictor(QList<Player> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KalmanDynamicTopLevel::sendPrevious(QList<Player> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE