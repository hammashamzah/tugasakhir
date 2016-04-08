/****************************************************************************
** Meta object code from reading C++ file 'Tracking.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tracking.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tracking.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tracking_t {
    QByteArrayData data[14];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tracking_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tracking_t qt_meta_stringdata_Tracking = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Tracking"
QT_MOC_LITERAL(1, 9, 18), // "sendDataQFoundLost"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "QList<DataInputCam>"
QT_MOC_LITERAL(4, 49, 24), // "signalupdateAssociateMat"
QT_MOC_LITERAL(5, 74, 3), // "Mat"
QT_MOC_LITERAL(6, 78, 14), // "requestDataCam"
QT_MOC_LITERAL(7, 93, 16), // "SendHasilMapping"
QT_MOC_LITERAL(8, 110, 4), // "run1"
QT_MOC_LITERAL(9, 115, 5), // "Frame"
QT_MOC_LITERAL(10, 121, 11), // "dataCamera1"
QT_MOC_LITERAL(11, 133, 11), // "dataCamera2"
QT_MOC_LITERAL(12, 145, 4), // "run2"
QT_MOC_LITERAL(13, 150, 21) // "QList<DataInputTrans>"

    },
    "Tracking\0sendDataQFoundLost\0\0"
    "QList<DataInputCam>\0signalupdateAssociateMat\0"
    "Mat\0requestDataCam\0SendHasilMapping\0"
    "run1\0Frame\0dataCamera1\0dataCamera2\0"
    "run2\0QList<DataInputTrans>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tracking[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x06 /* Public */,
       4,    1,   53,    2, 0x06 /* Public */,
       6,    1,   56,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   62,    2, 0x0a /* Public */,
      12,    4,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3,    9,   10,   11,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 13,    2,    2,    2,    2,

       0        // eod
};

void Tracking::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tracking *_t = static_cast<Tracking *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataQFoundLost((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[2])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[3])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[4]))); break;
        case 1: _t->signalupdateAssociateMat((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 2: _t->requestDataCam((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SendHasilMapping((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        case 4: _t->run1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[2])),(*reinterpret_cast< QList<DataInputCam>(*)>(_a[3]))); break;
        case 5: _t->run2((*reinterpret_cast< QList<DataInputTrans>(*)>(_a[1])),(*reinterpret_cast< QList<DataInputTrans>(*)>(_a[2])),(*reinterpret_cast< QList<DataInputTrans>(*)>(_a[3])),(*reinterpret_cast< QList<DataInputTrans>(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tracking::*_t)(QList<DataInputCam> , QList<DataInputCam> , QList<DataInputCam> , QList<DataInputCam> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tracking::sendDataQFoundLost)) {
                *result = 0;
            }
        }
        {
            typedef void (Tracking::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tracking::signalupdateAssociateMat)) {
                *result = 1;
            }
        }
        {
            typedef void (Tracking::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tracking::requestDataCam)) {
                *result = 2;
            }
        }
        {
            typedef void (Tracking::*_t)(QList<DataInputCam> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tracking::SendHasilMapping)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Tracking::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tracking.data,
      qt_meta_data_Tracking,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tracking::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tracking::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tracking.stringdata0))
        return static_cast<void*>(const_cast< Tracking*>(this));
    return QObject::qt_metacast(_clname);
}

int Tracking::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Tracking::sendDataQFoundLost(QList<DataInputCam> _t1, QList<DataInputCam> _t2, QList<DataInputCam> _t3, QList<DataInputCam> _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tracking::signalupdateAssociateMat(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tracking::requestDataCam(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Tracking::SendHasilMapping(QList<DataInputCam> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
