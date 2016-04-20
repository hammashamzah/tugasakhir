/****************************************************************************
** Meta object code from reading C++ file 'videoprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../integrasi/videoprocessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoProcessor_t {
    QByteArrayData data[10];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoProcessor_t qt_meta_stringdata_VideoProcessor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VideoProcessor"
QT_MOC_LITERAL(1, 15, 25), // "sendSingleCameraViewImage"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 15), // "QVector<QImage>"
QT_MOC_LITERAL(4, 58, 20), // "sendCameraObjectData"
QT_MOC_LITERAL(5, 79, 13), // "QList<Player>"
QT_MOC_LITERAL(6, 93, 17), // "setValueParameter"
QT_MOC_LITERAL(7, 111, 12), // "QVector<int>"
QT_MOC_LITERAL(8, 124, 17), // "getMaskCoordinate"
QT_MOC_LITERAL(9, 142, 13) // "QList<QPoint>"

    },
    "VideoProcessor\0sendSingleCameraViewImage\0"
    "\0QVector<QImage>\0sendCameraObjectData\0"
    "QList<Player>\0setValueParameter\0"
    "QVector<int>\0getMaskCoordinate\0"
    "QList<QPoint>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void VideoProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoProcessor *_t = static_cast<VideoProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSingleCameraViewImage((*reinterpret_cast< const QVector<QImage>(*)>(_a[1]))); break;
        case 1: _t->sendCameraObjectData((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 2: _t->setValueParameter((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 3: _t->getMaskCoordinate((*reinterpret_cast< QList<QPoint>(*)>(_a[1]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoProcessor::*_t)(const QVector<QImage> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoProcessor::sendSingleCameraViewImage)) {
                *result = 0;
            }
        }
        {
            typedef void (VideoProcessor::*_t)(QList<Player> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoProcessor::sendCameraObjectData)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VideoProcessor::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VideoProcessor.data,
      qt_meta_data_VideoProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoProcessor.stringdata0))
        return static_cast<void*>(const_cast< VideoProcessor*>(this));
    return QThread::qt_metacast(_clname);
}

int VideoProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VideoProcessor::sendSingleCameraViewImage(const QVector<QImage> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoProcessor::sendCameraObjectData(QList<Player> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
