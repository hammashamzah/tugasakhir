/****************************************************************************
** Meta object code from reading C++ file 'fieldselectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../integrasi/fieldselectiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fieldselectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FieldSelectionDialog_t {
    QByteArrayData data[16];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FieldSelectionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FieldSelectionDialog_t qt_meta_stringdata_FieldSelectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FieldSelectionDialog"
QT_MOC_LITERAL(1, 21, 19), // "sendMaskCoordinates"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 23), // "QVector<QList<QPoint> >"
QT_MOC_LITERAL(4, 66, 24), // "sendTrapeziumCoordinates"
QT_MOC_LITERAL(5, 91, 29), // "sendTransformationCoordinates"
QT_MOC_LITERAL(6, 121, 12), // "processMouse"
QT_MOC_LITERAL(7, 134, 7), // "QPoint&"
QT_MOC_LITERAL(8, 142, 3), // "pos"
QT_MOC_LITERAL(9, 146, 12), // "processClick"
QT_MOC_LITERAL(10, 159, 18), // "setFirstFrameImage"
QT_MOC_LITERAL(11, 178, 15), // "QVector<QImage>"
QT_MOC_LITERAL(12, 194, 40), // "on_cameraSelectCombo_currentI..."
QT_MOC_LITERAL(13, 235, 5), // "index"
QT_MOC_LITERAL(14, 241, 26), // "on_pushButton_set_released"
QT_MOC_LITERAL(15, 268, 28) // "on_pushButton_apply_released"

    },
    "FieldSelectionDialog\0sendMaskCoordinates\0"
    "\0QVector<QList<QPoint> >\0"
    "sendTrapeziumCoordinates\0"
    "sendTransformationCoordinates\0"
    "processMouse\0QPoint&\0pos\0processClick\0"
    "setFirstFrameImage\0QVector<QImage>\0"
    "on_cameraSelectCombo_currentIndexChanged\0"
    "index\0on_pushButton_set_released\0"
    "on_pushButton_apply_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldSelectionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   68,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      10,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x08 /* Private */,
      14,    0,   80,    2, 0x08 /* Private */,
      15,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FieldSelectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FieldSelectionDialog *_t = static_cast<FieldSelectionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMaskCoordinates((*reinterpret_cast< QVector<QList<QPoint> >(*)>(_a[1]))); break;
        case 1: _t->sendTrapeziumCoordinates((*reinterpret_cast< QVector<QList<QPoint> >(*)>(_a[1]))); break;
        case 2: _t->sendTransformationCoordinates((*reinterpret_cast< QVector<QList<QPoint> >(*)>(_a[1]))); break;
        case 3: _t->processMouse((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->processClick((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->setFirstFrameImage((*reinterpret_cast< QVector<QImage>(*)>(_a[1]))); break;
        case 6: _t->on_cameraSelectCombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_set_released(); break;
        case 8: _t->on_pushButton_apply_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QList<QPoint> > >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QList<QPoint> > >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QList<QPoint> > >(); break;
            }
            break;
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
            typedef void (FieldSelectionDialog::*_t)(QVector<QList<QPoint> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldSelectionDialog::sendMaskCoordinates)) {
                *result = 0;
            }
        }
        {
            typedef void (FieldSelectionDialog::*_t)(QVector<QList<QPoint> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldSelectionDialog::sendTrapeziumCoordinates)) {
                *result = 1;
            }
        }
        {
            typedef void (FieldSelectionDialog::*_t)(QVector<QList<QPoint> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FieldSelectionDialog::sendTransformationCoordinates)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject FieldSelectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FieldSelectionDialog.data,
      qt_meta_data_FieldSelectionDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FieldSelectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldSelectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FieldSelectionDialog.stringdata0))
        return static_cast<void*>(const_cast< FieldSelectionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FieldSelectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FieldSelectionDialog::sendMaskCoordinates(QVector<QList<QPoint> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FieldSelectionDialog::sendTrapeziumCoordinates(QVector<QList<QPoint> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FieldSelectionDialog::sendTransformationCoordinates(QVector<QList<QPoint> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
