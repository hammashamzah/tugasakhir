/****************************************************************************
** Meta object code from reading C++ file 'ObjAssociate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ObjAssociate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjAssociate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Associate_t {
    QByteArrayData data[14];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Associate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Associate_t qt_meta_stringdata_Associate = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Associate"
QT_MOC_LITERAL(1, 10, 13), // "getOcclusion1"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "QList<Point>"
QT_MOC_LITERAL(4, 38, 13), // "getOcclusion2"
QT_MOC_LITERAL(5, 52, 13), // "getOcclusion3"
QT_MOC_LITERAL(6, 66, 13), // "updateMatCam1"
QT_MOC_LITERAL(7, 80, 3), // "Mat"
QT_MOC_LITERAL(8, 84, 13), // "updateMatCam2"
QT_MOC_LITERAL(9, 98, 13), // "updateMatCam3"
QT_MOC_LITERAL(10, 112, 17), // "updateCurrentCam1"
QT_MOC_LITERAL(11, 130, 19), // "QList<DataInputCam>"
QT_MOC_LITERAL(12, 150, 17), // "updateCurrentCam2"
QT_MOC_LITERAL(13, 168, 17) // "updateCurrentCam3"

    },
    "Associate\0getOcclusion1\0\0QList<Point>\0"
    "getOcclusion2\0getOcclusion3\0updateMatCam1\0"
    "Mat\0updateMatCam2\0updateMatCam3\0"
    "updateCurrentCam1\0QList<DataInputCam>\0"
    "updateCurrentCam2\0updateCurrentCam3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Associate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    1,   65,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void Associate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Associate *_t = static_cast<Associate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getOcclusion1((*reinterpret_cast< QList<Point>(*)>(_a[1]))); break;
        case 1: _t->getOcclusion2((*reinterpret_cast< QList<Point>(*)>(_a[1]))); break;
        case 2: _t->getOcclusion3((*reinterpret_cast< QList<Point>(*)>(_a[1]))); break;
        case 3: _t->updateMatCam1((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->updateMatCam2((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 5: _t->updateMatCam3((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 6: _t->updateCurrentCam1((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        case 7: _t->updateCurrentCam2((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        case 8: _t->updateCurrentCam3((*reinterpret_cast< QList<DataInputCam>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Associate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Associate.data,
      qt_meta_data_Associate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Associate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Associate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Associate.stringdata0))
        return static_cast<void*>(const_cast< Associate*>(this));
    return QObject::qt_metacast(_clname);
}

int Associate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
