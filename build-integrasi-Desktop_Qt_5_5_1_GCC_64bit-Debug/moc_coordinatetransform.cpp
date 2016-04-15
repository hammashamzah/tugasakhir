/****************************************************************************
** Meta object code from reading C++ file 'coordinatetransform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../integrasi/coordinatetransform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coordinatetransform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CoordinateTransform_t {
    QByteArrayData data[16];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoordinateTransform_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoordinateTransform_t qt_meta_stringdata_CoordinateTransform = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CoordinateTransform"
QT_MOC_LITERAL(1, 20, 22), // "sendTransformedRawData"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 13), // "QList<Player>"
QT_MOC_LITERAL(4, 58, 17), // "sendPlayerformed1"
QT_MOC_LITERAL(5, 76, 21), // "QList<QList<Player> >"
QT_MOC_LITERAL(6, 98, 17), // "sendPlayerformed2"
QT_MOC_LITERAL(7, 116, 23), // "sendTransformedPosition"
QT_MOC_LITERAL(8, 140, 23), // "QVector<QList<Player> >"
QT_MOC_LITERAL(9, 164, 18), // "getTransformMatrix"
QT_MOC_LITERAL(10, 183, 10), // "QList<Mat>"
QT_MOC_LITERAL(11, 194, 12), // "getImageSize"
QT_MOC_LITERAL(12, 207, 12), // "QList<QSize>"
QT_MOC_LITERAL(13, 220, 24), // "processTransformPosition"
QT_MOC_LITERAL(14, 245, 28), // "setTransformationCoordinates"
QT_MOC_LITERAL(15, 274, 23) // "QVector<QList<QPoint> >"

    },
    "CoordinateTransform\0sendTransformedRawData\0"
    "\0QList<Player>\0sendPlayerformed1\0"
    "QList<QList<Player> >\0sendPlayerformed2\0"
    "sendTransformedPosition\0QVector<QList<Player> >\0"
    "getTransformMatrix\0QList<Mat>\0"
    "getImageSize\0QList<QSize>\0"
    "processTransformPosition\0"
    "setTransformationCoordinates\0"
    "QVector<QList<QPoint> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoordinateTransform[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       7,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   66,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,
      13,    1,   72,    2, 0x0a /* Public */,
      14,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

void CoordinateTransform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CoordinateTransform *_t = static_cast<CoordinateTransform *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTransformedRawData((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 1: _t->sendPlayerformed1((*reinterpret_cast< QList<QList<Player> >(*)>(_a[1]))); break;
        case 2: _t->sendPlayerformed2((*reinterpret_cast< QList<QList<Player> >(*)>(_a[1]))); break;
        case 3: _t->sendTransformedPosition((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 4: _t->getTransformMatrix((*reinterpret_cast< QList<Mat>(*)>(_a[1]))); break;
        case 5: _t->getImageSize((*reinterpret_cast< QList<QSize>(*)>(_a[1]))); break;
        case 6: _t->processTransformPosition((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 7: _t->setTransformationCoordinates((*reinterpret_cast< QVector<QList<QPoint> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSize> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QList<QPoint> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CoordinateTransform::*_t)(QList<Player> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CoordinateTransform::sendTransformedRawData)) {
                *result = 0;
            }
        }
        {
            typedef void (CoordinateTransform::*_t)(QList<QList<Player> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CoordinateTransform::sendPlayerformed1)) {
                *result = 1;
            }
        }
        {
            typedef void (CoordinateTransform::*_t)(QList<QList<Player> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CoordinateTransform::sendPlayerformed2)) {
                *result = 2;
            }
        }
        {
            typedef void (CoordinateTransform::*_t)(QVector<QList<Player> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CoordinateTransform::sendTransformedPosition)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CoordinateTransform::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CoordinateTransform.data,
      qt_meta_data_CoordinateTransform,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CoordinateTransform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoordinateTransform::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CoordinateTransform.stringdata0))
        return static_cast<void*>(const_cast< CoordinateTransform*>(this));
    return QObject::qt_metacast(_clname);
}

int CoordinateTransform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CoordinateTransform::sendTransformedRawData(QList<Player> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CoordinateTransform::sendPlayerformed1(QList<QList<Player> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CoordinateTransform::sendPlayerformed2(QList<QList<Player> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CoordinateTransform::sendTransformedPosition(QVector<QList<Player> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
