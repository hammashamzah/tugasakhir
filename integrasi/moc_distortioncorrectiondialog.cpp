/****************************************************************************
** Meta object code from reading C++ file 'distortioncorrectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "distortioncorrectiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'distortioncorrectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DistortionCorrectionDialog_t {
    QByteArrayData data[14];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DistortionCorrectionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DistortionCorrectionDialog_t qt_meta_stringdata_DistortionCorrectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 26), // "DistortionCorrectionDialog"
QT_MOC_LITERAL(1, 27, 25), // "sendDistortionCoeffisient"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 20), // "sendUndistortedImage"
QT_MOC_LITERAL(4, 75, 39), // "on_doubleSpinBox_koefisien_va..."
QT_MOC_LITERAL(5, 115, 4), // "arg1"
QT_MOC_LITERAL(6, 120, 30), // "on_verticalSlider_valueChanged"
QT_MOC_LITERAL(7, 151, 5), // "value"
QT_MOC_LITERAL(8, 157, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(9, 179, 18), // "setFirstFrameImage"
QT_MOC_LITERAL(10, 198, 15), // "QVector<QImage>"
QT_MOC_LITERAL(11, 214, 10), // "firstFrame"
QT_MOC_LITERAL(12, 225, 28), // "on_comboBox_camera_activated"
QT_MOC_LITERAL(13, 254, 5) // "index"

    },
    "DistortionCorrectionDialog\0"
    "sendDistortionCoeffisient\0\0"
    "sendUndistortedImage\0"
    "on_doubleSpinBox_koefisien_valueChanged\0"
    "arg1\0on_verticalSlider_valueChanged\0"
    "value\0on_buttonBox_accepted\0"
    "setFirstFrameImage\0QVector<QImage>\0"
    "firstFrame\0on_comboBox_camera_activated\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DistortionCorrectionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   55,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void DistortionCorrectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DistortionCorrectionDialog *_t = static_cast<DistortionCorrectionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDistortionCoeffisient((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->sendUndistortedImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->on_doubleSpinBox_koefisien_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_verticalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_buttonBox_accepted(); break;
        case 5: _t->setFirstFrameImage((*reinterpret_cast< QVector<QImage>(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_camera_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QImage> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DistortionCorrectionDialog::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DistortionCorrectionDialog::sendDistortionCoeffisient)) {
                *result = 0;
            }
        }
        {
            typedef void (DistortionCorrectionDialog::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DistortionCorrectionDialog::sendUndistortedImage)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DistortionCorrectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DistortionCorrectionDialog.data,
      qt_meta_data_DistortionCorrectionDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DistortionCorrectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DistortionCorrectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DistortionCorrectionDialog.stringdata0))
        return static_cast<void*>(const_cast< DistortionCorrectionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DistortionCorrectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DistortionCorrectionDialog::sendDistortionCoeffisient(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DistortionCorrectionDialog::sendUndistortedImage(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
