/****************************************************************************
** Meta object code from reading C++ file 'datawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datawindow.h"
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
    QByteArrayData data[17];
    char stringdata0[408];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataWindow_t qt_meta_stringdata_DataWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DataWindow"
QT_MOC_LITERAL(1, 11, 11), // "processData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "QList<Player>"
QT_MOC_LITERAL(4, 38, 21), // "processDataAssociated"
QT_MOC_LITERAL(5, 60, 35), // "on_pushButton_display_data_re..."
QT_MOC_LITERAL(6, 96, 27), // "on_pushButton_load_released"
QT_MOC_LITERAL(7, 124, 27), // "on_pushButton_save_released"
QT_MOC_LITERAL(8, 152, 25), // "on_pushButton_cut_clicked"
QT_MOC_LITERAL(9, 178, 27), // "on_pushButton_paste_clicked"
QT_MOC_LITERAL(10, 206, 29), // "on_pushButton_refresh_clicked"
QT_MOC_LITERAL(11, 236, 35), // "on_pushButton_playbackStart_c..."
QT_MOC_LITERAL(12, 272, 31), // "on_slider_playback_valueChanged"
QT_MOC_LITERAL(13, 304, 5), // "value"
QT_MOC_LITERAL(14, 310, 33), // "on_pushButton_reconstruct_cli..."
QT_MOC_LITERAL(15, 344, 31), // "on_pushButton_save_raw_released"
QT_MOC_LITERAL(16, 376, 31) // "on_pushButton_load_raw_released"

    },
    "DataWindow\0processData\0\0QList<Player>\0"
    "processDataAssociated\0"
    "on_pushButton_display_data_released\0"
    "on_pushButton_load_released\0"
    "on_pushButton_save_released\0"
    "on_pushButton_cut_clicked\0"
    "on_pushButton_paste_clicked\0"
    "on_pushButton_refresh_clicked\0"
    "on_pushButton_playbackStart_clicked\0"
    "on_slider_playback_valueChanged\0value\0"
    "on_pushButton_reconstruct_clicked\0"
    "on_pushButton_save_raw_released\0"
    "on_pushButton_load_raw_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       5,    0,   85,    2, 0x08 /* Private */,
       6,    0,   86,    2, 0x08 /* Private */,
       7,    0,   87,    2, 0x08 /* Private */,
       8,    0,   88,    2, 0x08 /* Private */,
       9,    0,   89,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    1,   92,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
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
        case 0: _t->processData((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 1: _t->processDataAssociated((*reinterpret_cast< QList<Player>(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_display_data_released(); break;
        case 3: _t->on_pushButton_load_released(); break;
        case 4: _t->on_pushButton_save_released(); break;
        case 5: _t->on_pushButton_cut_clicked(); break;
        case 6: _t->on_pushButton_paste_clicked(); break;
        case 7: _t->on_pushButton_refresh_clicked(); break;
        case 8: _t->on_pushButton_playbackStart_clicked(); break;
        case 9: _t->on_slider_playback_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_reconstruct_clicked(); break;
        case 11: _t->on_pushButton_save_raw_released(); break;
        case 12: _t->on_pushButton_load_raw_released(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
