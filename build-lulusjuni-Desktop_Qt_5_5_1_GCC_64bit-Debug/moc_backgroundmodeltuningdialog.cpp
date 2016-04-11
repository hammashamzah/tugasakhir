/****************************************************************************
** Meta object code from reading C++ file 'backgroundmodeltuningdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lulusjuni/backgroundmodeltuningdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backgroundmodeltuningdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BackgroundModelTuningDialog_t {
    QByteArrayData data[14];
    char stringdata0[404];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackgroundModelTuningDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackgroundModelTuningDialog_t qt_meta_stringdata_BackgroundModelTuningDialog = {
    {
QT_MOC_LITERAL(0, 0, 27), // "BackgroundModelTuningDialog"
QT_MOC_LITERAL(1, 28, 17), // "setValueParameter"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 22), // "QVector<QVector<int> >"
QT_MOC_LITERAL(4, 70, 42), // "on_slider_morp_element_size_1..."
QT_MOC_LITERAL(5, 113, 5), // "value"
QT_MOC_LITERAL(6, 119, 38), // "on_slider_gaussian_size_1_val..."
QT_MOC_LITERAL(7, 158, 33), // "on_slider_min_area_2_valueCha..."
QT_MOC_LITERAL(8, 192, 33), // "on_slider_max_area_2_valueCha..."
QT_MOC_LITERAL(9, 226, 42), // "on_slider_morp_element_size_2..."
QT_MOC_LITERAL(10, 269, 38), // "on_slider_gaussian_size_2_val..."
QT_MOC_LITERAL(11, 308, 27), // "on_pushButton_load_released"
QT_MOC_LITERAL(12, 336, 33), // "on_slider_min_area_1_valueCha..."
QT_MOC_LITERAL(13, 370, 33) // "on_slider_max_area_1_valueCha..."

    },
    "BackgroundModelTuningDialog\0"
    "setValueParameter\0\0QVector<QVector<int> >\0"
    "on_slider_morp_element_size_1_valueChanged\0"
    "value\0on_slider_gaussian_size_1_valueChanged\0"
    "on_slider_min_area_2_valueChanged\0"
    "on_slider_max_area_2_valueChanged\0"
    "on_slider_morp_element_size_2_valueChanged\0"
    "on_slider_gaussian_size_2_valueChanged\0"
    "on_pushButton_load_released\0"
    "on_slider_min_area_1_valueChanged\0"
    "on_slider_max_area_1_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackgroundModelTuningDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   67,    2, 0x0a /* Public */,
       6,    1,   70,    2, 0x0a /* Public */,
       7,    1,   73,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
       9,    1,   79,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void BackgroundModelTuningDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackgroundModelTuningDialog *_t = static_cast<BackgroundModelTuningDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setValueParameter((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1]))); break;
        case 1: _t->on_slider_morp_element_size_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_slider_gaussian_size_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_slider_min_area_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_slider_max_area_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_slider_morp_element_size_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_slider_gaussian_size_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_load_released(); break;
        case 8: _t->on_slider_min_area_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_slider_max_area_1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BackgroundModelTuningDialog::*_t)(QVector<QVector<int> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BackgroundModelTuningDialog::setValueParameter)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BackgroundModelTuningDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BackgroundModelTuningDialog.data,
      qt_meta_data_BackgroundModelTuningDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BackgroundModelTuningDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackgroundModelTuningDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundModelTuningDialog.stringdata0))
        return static_cast<void*>(const_cast< BackgroundModelTuningDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BackgroundModelTuningDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void BackgroundModelTuningDialog::setValueParameter(QVector<QVector<int> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
