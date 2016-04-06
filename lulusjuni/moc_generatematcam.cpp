/****************************************************************************
** Meta object code from reading C++ file 'generatematcam.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "generatematcam.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generatematcam.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GenerateMatCam_t {
    QByteArrayData data[10];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenerateMatCam_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenerateMatCam_t qt_meta_stringdata_GenerateMatCam = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GenerateMatCam"
QT_MOC_LITERAL(1, 15, 14), // "updateMatrices"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "Mat"
QT_MOC_LITERAL(4, 35, 15), // "updateOcclusion"
QT_MOC_LITERAL(5, 51, 12), // "QList<Point>"
QT_MOC_LITERAL(6, 64, 11), // "sendCurrent"
QT_MOC_LITERAL(7, 76, 19), // "QList<DataInputCam>"
QT_MOC_LITERAL(8, 96, 12), // "updatePredic"
QT_MOC_LITERAL(9, 109, 14) // "updatePrevious"

    },
    "GenerateMatCam\0updateMatrices\0\0Mat\0"
    "updateOcclusion\0QList<Point>\0sendCurrent\0"
    "QList<DataInputCam>\0updatePredic\0"
    "updatePrevious"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenerateMatCam[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x0a /* Public */,
       9,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void GenerateMatCam::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenerateMatCam *_t = static_cast<GenerateMatCam *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMatrices((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->updateOcclusion((*reinterpret_cast< QList<Point>(*)>(_a[1]))); break;
        case 2: _t->sendCurrent((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        case 3: _t->updatePredic((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        case 4: _t->updatePrevious((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GenerateMatCam::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenerateMatCam::updateMatrices)) {
                *result = 0;
            }
        }
        {
            typedef void (GenerateMatCam::*_t)(QList<Point> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenerateMatCam::updateOcclusion)) {
                *result = 1;
            }
        }
        {
            typedef void (GenerateMatCam::*_t)(QList<DataInputCam> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenerateMatCam::sendCurrent)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GenerateMatCam::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GenerateMatCam.data,
      qt_meta_data_GenerateMatCam,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GenerateMatCam::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenerateMatCam::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GenerateMatCam.stringdata0))
        return static_cast<void*>(const_cast< GenerateMatCam*>(this));
    return QObject::qt_metacast(_clname);
}

int GenerateMatCam::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void GenerateMatCam::updateMatrices(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GenerateMatCam::updateOcclusion(QList<Point> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GenerateMatCam::sendCurrent(QList<DataInputCam> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
