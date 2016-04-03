/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[546];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "showMousePosition"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "QPoint&"
QT_MOC_LITERAL(4, 38, 3), // "pos"
QT_MOC_LITERAL(5, 42, 17), // "showClickPosition"
QT_MOC_LITERAL(6, 60, 42), // "on_actionTuning_Background_Mo..."
QT_MOC_LITERAL(7, 103, 38), // "on_actionPer_Camera_Raw_View_..."
QT_MOC_LITERAL(8, 142, 36), // "on_actionError_Calculation_tr..."
QT_MOC_LITERAL(9, 179, 53), // "on_actionSystem_Performance_T..."
QT_MOC_LITERAL(10, 233, 34), // "on_actionField_Selection_trig..."
QT_MOC_LITERAL(11, 268, 32), // "on_actionTracking_View_triggered"
QT_MOC_LITERAL(12, 301, 26), // "on_actionVideo_1_triggered"
QT_MOC_LITERAL(13, 328, 26), // "on_actionVideo_2_triggered"
QT_MOC_LITERAL(14, 355, 26), // "on_actionVideo_3_triggered"
QT_MOC_LITERAL(15, 382, 27), // "on_pushButton_play_released"
QT_MOC_LITERAL(16, 410, 35), // "on_lineEdit_setIDplayer_textC..."
QT_MOC_LITERAL(17, 446, 4), // "arg1"
QT_MOC_LITERAL(18, 451, 34), // "on_lineEdit_setIDplayer_textE..."
QT_MOC_LITERAL(19, 486, 37), // "on_lineEdit_setIDplayer_retur..."
QT_MOC_LITERAL(20, 524, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0showMousePosition\0\0QPoint&\0"
    "pos\0showClickPosition\0"
    "on_actionTuning_Background_Model_triggered\0"
    "on_actionPer_Camera_Raw_View_triggered\0"
    "on_actionError_Calculation_triggered\0"
    "on_actionSystem_Performance_Testing_Metrics_triggered\0"
    "on_actionField_Selection_triggered\0"
    "on_actionTracking_View_triggered\0"
    "on_actionVideo_1_triggered\0"
    "on_actionVideo_2_triggered\0"
    "on_actionVideo_3_triggered\0"
    "on_pushButton_play_released\0"
    "on_lineEdit_setIDplayer_textChanged\0"
    "arg1\0on_lineEdit_setIDplayer_textEdited\0"
    "on_lineEdit_setIDplayer_returnPressed\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x0a /* Public */,
       5,    1,   97,    2, 0x0a /* Public */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    1,  110,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->showClickPosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->on_actionTuning_Background_Model_triggered(); break;
        case 3: _t->on_actionPer_Camera_Raw_View_triggered(); break;
        case 4: _t->on_actionError_Calculation_triggered(); break;
        case 5: _t->on_actionSystem_Performance_Testing_Metrics_triggered(); break;
        case 6: _t->on_actionField_Selection_triggered(); break;
        case 7: _t->on_actionTracking_View_triggered(); break;
        case 8: _t->on_actionVideo_1_triggered(); break;
        case 9: _t->on_actionVideo_2_triggered(); break;
        case 10: _t->on_actionVideo_3_triggered(); break;
        case 11: _t->on_pushButton_play_released(); break;
        case 15: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
