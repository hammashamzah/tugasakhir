/****************************************************************************
** Meta object code from reading C++ file 'dynamicassociation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dynamicassociation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dynamicassociation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DynamicAssociation_t {
    QByteArrayData data[13];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DynamicAssociation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DynamicAssociation_t qt_meta_stringdata_DynamicAssociation = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DynamicAssociation"
QT_MOC_LITERAL(1, 19, 17), // "sendDataAggregate"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "QVector<QList<Player> >"
QT_MOC_LITERAL(4, 62, 23), // "sendDatatobeTransformed"
QT_MOC_LITERAL(5, 86, 14), // "getCurrentData"
QT_MOC_LITERAL(6, 101, 14), // "getNewDataCam1"
QT_MOC_LITERAL(7, 116, 13), // "QList<Player>"
QT_MOC_LITERAL(8, 130, 14), // "getNewDataCam2"
QT_MOC_LITERAL(9, 145, 21), // "getAssociatedDataCam1"
QT_MOC_LITERAL(10, 167, 21), // "getAssociatedDataCam2"
QT_MOC_LITERAL(11, 189, 19), // "processAssignedData"
QT_MOC_LITERAL(12, 209, 18) // "getTransformedData"

    },
    "DynamicAssociation\0sendDataAggregate\0"
    "\0QVector<QList<Player> >\0"
    "sendDatatobeTransformed\0getCurrentData\0"
    "getNewDataCam1\0QList<Player>\0"
    "getNewDataCam2\0getAssociatedDataCam1\0"
    "getAssociatedDataCam2\0processAssignedData\0"
    "getTransformedData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DynamicAssociation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   65,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      11,    1,   80,    2, 0x0a /* Public */,
      12,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void DynamicAssociation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DynamicAssociation *_t = static_cast<DynamicAssociation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataAggregate((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 1: _t->sendDatatobeTransformed((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 2: _t->getCurrentData((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 3: _t->getNewDataCam1((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 4: _t->getNewDataCam2((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 5: _t->getAssociatedDataCam1((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 6: _t->getAssociatedDataCam2((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 7: _t->processAssignedData((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 8: _t->getTransformedData((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DynamicAssociation::*_t)(QVector<QList<Player> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DynamicAssociation::sendDataAggregate)) {
                *result = 0;
            }
        }
        {
            typedef void (DynamicAssociation::*_t)(QVector<QList<Player> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DynamicAssociation::sendDatatobeTransformed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DynamicAssociation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DynamicAssociation.data,
      qt_meta_data_DynamicAssociation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DynamicAssociation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DynamicAssociation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DynamicAssociation.stringdata0))
        return static_cast<void*>(const_cast< DynamicAssociation*>(this));
    return QObject::qt_metacast(_clname);
}

int DynamicAssociation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DynamicAssociation::sendDataAggregate(QVector<QList<Player> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DynamicAssociation::sendDatatobeTransformed(QVector<QList<Player> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
