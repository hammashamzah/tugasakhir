/****************************************************************************
** Meta object code from reading C++ file 'processor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lulusjuni/processor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Processor_t {
    QByteArrayData data[18];
    char stringdata0[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Processor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Processor_t qt_meta_stringdata_Processor = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Processor"
QT_MOC_LITERAL(1, 10, 15), // "firstFrameImage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "QVector<QImage>"
QT_MOC_LITERAL(4, 43, 22), // "updateValueParameter_1"
QT_MOC_LITERAL(5, 66, 12), // "QVector<int>"
QT_MOC_LITERAL(6, 79, 22), // "updateValueParameter_2"
QT_MOC_LITERAL(7, 102, 22), // "updateMaskCoordinate_1"
QT_MOC_LITERAL(8, 125, 13), // "QList<QPoint>"
QT_MOC_LITERAL(9, 139, 22), // "updateMaskCoordinate_2"
QT_MOC_LITERAL(10, 162, 18), // "setCameraViewImage"
QT_MOC_LITERAL(11, 181, 25), // "QVector<QVector<QImage> >"
QT_MOC_LITERAL(12, 207, 29), // "updateSingleCameraViewImage_1"
QT_MOC_LITERAL(13, 237, 29), // "updateSingleCameraViewImage_2"
QT_MOC_LITERAL(14, 267, 20), // "updateMaskCoordinate"
QT_MOC_LITERAL(15, 288, 23), // "QVector<QList<QPoint> >"
QT_MOC_LITERAL(16, 312, 20), // "updateValueParameter"
QT_MOC_LITERAL(17, 333, 22) // "QVector<QVector<int> >"

    },
    "Processor\0firstFrameImage\0\0QVector<QImage>\0"
    "updateValueParameter_1\0QVector<int>\0"
    "updateValueParameter_2\0updateMaskCoordinate_1\0"
    "QList<QPoint>\0updateMaskCoordinate_2\0"
    "setCameraViewImage\0QVector<QVector<QImage> >\0"
    "updateSingleCameraViewImage_1\0"
    "updateSingleCameraViewImage_2\0"
    "updateMaskCoordinate\0QVector<QList<QPoint> >\0"
    "updateValueParameter\0QVector<QVector<int> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Processor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       7,    1,   73,    2, 0x06 /* Public */,
       9,    1,   76,    2, 0x06 /* Public */,
      10,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   82,    2, 0x0a /* Public */,
      13,    1,   85,    2, 0x0a /* Public */,
      14,    1,   88,    2, 0x0a /* Public */,
      16,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,

       0        // eod
};

void Processor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Processor *_t = static_cast<Processor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstFrameImage((*reinterpret_cast< QVector<QImage>(*)>(_a[1]))); break;
        case 1: _t->updateValueParameter_1((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 2: _t->updateValueParameter_2((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 3: _t->updateMaskCoordinate_1((*reinterpret_cast< QList<QPoint>(*)>(_a[1]))); break;
        case 4: _t->updateMaskCoordinate_2((*reinterpret_cast< QList<QPoint>(*)>(_a[1]))); break;
        case 5: _t->setCameraViewImage((*reinterpret_cast< QVector<QVector<QImage> >(*)>(_a[1]))); break;
        case 6: _t->updateSingleCameraViewImage_1((*reinterpret_cast< QVector<QImage>(*)>(_a[1]))); break;
        case 7: _t->updateSingleCameraViewImage_2((*reinterpret_cast< QVector<QImage>(*)>(_a[1]))); break;
        case 8: _t->updateMaskCoordinate((*reinterpret_cast< QVector<QList<QPoint> >(*)>(_a[1]))); break;
        case 9: _t->updateValueParameter((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QImage> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPoint> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPoint> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QImage> > >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QImage> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QImage> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QList<QPoint> > >(); break;
            }
            break;
        case 9:
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
            typedef void (Processor::*_t)(QVector<QImage> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::firstFrameImage)) {
                *result = 0;
            }
        }
        {
            typedef void (Processor::*_t)(QVector<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::updateValueParameter_1)) {
                *result = 1;
            }
        }
        {
            typedef void (Processor::*_t)(QVector<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::updateValueParameter_2)) {
                *result = 2;
            }
        }
        {
            typedef void (Processor::*_t)(QList<QPoint> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::updateMaskCoordinate_1)) {
                *result = 3;
            }
        }
        {
            typedef void (Processor::*_t)(QList<QPoint> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::updateMaskCoordinate_2)) {
                *result = 4;
            }
        }
        {
            typedef void (Processor::*_t)(QVector<QVector<QImage> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::setCameraViewImage)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Processor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Processor.data,
      qt_meta_data_Processor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Processor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Processor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Processor.stringdata0))
        return static_cast<void*>(const_cast< Processor*>(this));
    return QObject::qt_metacast(_clname);
}

int Processor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Processor::firstFrameImage(QVector<QImage> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Processor::updateValueParameter_1(QVector<int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Processor::updateValueParameter_2(QVector<int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Processor::updateMaskCoordinate_1(QList<QPoint> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Processor::updateMaskCoordinate_2(QList<QPoint> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Processor::setCameraViewImage(QVector<QVector<QImage> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
