/****************************************************************************
** Meta object code from reading C++ file 'Highlevel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Highlevel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Highlevel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HighLevel_t {
    QByteArrayData data[9];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HighLevel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HighLevel_t qt_meta_stringdata_HighLevel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HighLevel"
QT_MOC_LITERAL(1, 10, 18), // "sendDataQFoundLost"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "QList<DataInputCam>"
QT_MOC_LITERAL(4, 50, 14), // "requestDataCam"
QT_MOC_LITERAL(5, 65, 24), // "sendFlagGetLostFoundData"
QT_MOC_LITERAL(6, 90, 24), // "signalupdateAssociateMat"
QT_MOC_LITERAL(7, 115, 3), // "Mat"
QT_MOC_LITERAL(8, 119, 4) // "run1"

    },
    "HighLevel\0sendDataQFoundLost\0\0"
    "QList<DataInputCam>\0requestDataCam\0"
    "sendFlagGetLostFoundData\0"
    "signalupdateAssociateMat\0Mat\0run1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HighLevel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   39,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,

       0        // eod
};

void HighLevel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HighLevel *_t = static_cast<HighLevel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataQFoundLost((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[2])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[3])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[4])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[5])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[6]))); break;
        case 1: _t->requestDataCam((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendFlagGetLostFoundData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->signalupdateAssociateMat((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->run1((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[2])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HighLevel::*_t)(QList<DataInputCam> , QList<DataInputCam> , QList<DataInputCam> , QList<DataInputCam> , QList<DataInputCam> , QList<DataInputCam> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HighLevel::sendDataQFoundLost)) {
                *result = 0;
            }
        }
        {
            typedef void (HighLevel::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HighLevel::requestDataCam)) {
                *result = 1;
            }
        }
        {
            typedef void (HighLevel::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HighLevel::sendFlagGetLostFoundData)) {
                *result = 2;
            }
        }
        {
            typedef void (HighLevel::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HighLevel::signalupdateAssociateMat)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject HighLevel::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_HighLevel.data,
      qt_meta_data_HighLevel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HighLevel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HighLevel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HighLevel.stringdata0))
        return static_cast<void*>(const_cast< HighLevel*>(this));
    return QThread::qt_metacast(_clname);
}

int HighLevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void HighLevel::sendDataQFoundLost(QList<DataInputCam> _t1, QList<DataInputCam> _t2, QList<DataInputCam> _t3, QList<DataInputCam> _t4, QList<DataInputCam> _t5, QList<DataInputCam> _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HighLevel::requestDataCam(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HighLevel::sendFlagGetLostFoundData(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HighLevel::signalupdateAssociateMat(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
