/****************************************************************************
** Meta object code from reading C++ file 'datawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../integrasi/datawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataWindow_t {
    QByteArrayData data[9];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataWindow_t qt_meta_stringdata_DataWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DataWindow"
QT_MOC_LITERAL(1, 11, 17), // "dataEntryFinished"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "addData"
QT_MOC_LITERAL(4, 38, 13), // "QList<Player>"
QT_MOC_LITERAL(5, 52, 7), // "newData"
QT_MOC_LITERAL(6, 60, 35), // "on_pushButton_display_data_re..."
QT_MOC_LITERAL(7, 96, 27), // "on_pushButton_load_released"
QT_MOC_LITERAL(8, 124, 27) // "on_pushButton_save_released"

    },
    "DataWindow\0dataEntryFinished\0\0addData\0"
    "QList<Player>\0newData\0"
    "on_pushButton_display_data_released\0"
    "on_pushButton_load_released\0"
    "on_pushButton_save_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DataWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataWindow *_t = static_cast<DataWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataEntryFinished(); break;
        case 1: _t->addData((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_display_data_released(); break;
        case 3: _t->on_pushButton_load_released(); break;
        case 4: _t->on_pushButton_save_released(); break;
        default: ;
        }
    }
}

const QMetaObject DataWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DataWindow.data,
      qt_meta_data_DataWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataWindow.stringdata0))
        return static_cast<void*>(const_cast< DataWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int DataWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
