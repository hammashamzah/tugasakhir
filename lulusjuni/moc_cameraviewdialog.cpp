/****************************************************************************
** Meta object code from reading C++ file 'cameraviewdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cameraviewdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraviewdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraViewDialog_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraViewDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraViewDialog_t qt_meta_stringdata_CameraViewDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CameraViewDialog"
QT_MOC_LITERAL(1, 17, 19), // "updateRawPlayerUI_1"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 3), // "img"
QT_MOC_LITERAL(4, 42, 19), // "updateRawPlayerUI_2"
QT_MOC_LITERAL(5, 62, 19) // "updateRawPlayerUI_3"

    },
    "CameraViewDialog\0updateRawPlayerUI_1\0"
    "\0img\0updateRawPlayerUI_2\0updateRawPlayerUI_3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraViewDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,

       0        // eod
};

void CameraViewDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraViewDialog *_t = static_cast<CameraViewDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRawPlayerUI_1((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->updateRawPlayerUI_2((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->updateRawPlayerUI_3((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CameraViewDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CameraViewDialog.data,
      qt_meta_data_CameraViewDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraViewDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraViewDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraViewDialog.stringdata0))
        return static_cast<void*>(const_cast< CameraViewDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CameraViewDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
