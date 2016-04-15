/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../integrasi/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[421];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "displayTransformedPosition"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "QVector<QList<Player> >"
QT_MOC_LITERAL(4, 63, 42), // "on_actionTuning_Background_Mo..."
QT_MOC_LITERAL(5, 106, 38), // "on_actionPer_Camera_Raw_View_..."
QT_MOC_LITERAL(6, 145, 36), // "on_actionError_Calculation_tr..."
QT_MOC_LITERAL(7, 182, 53), // "on_actionSystem_Performance_T..."
QT_MOC_LITERAL(8, 236, 34), // "on_actionField_Selection_trig..."
QT_MOC_LITERAL(9, 271, 32), // "on_actionTracking_View_triggered"
QT_MOC_LITERAL(10, 304, 26), // "on_actionVideo_1_triggered"
QT_MOC_LITERAL(11, 331, 26), // "on_actionVideo_2_triggered"
QT_MOC_LITERAL(12, 358, 27), // "on_pushButton_play_released"
QT_MOC_LITERAL(13, 386, 34) // "on_pushButton_single_play_rel..."

    },
    "MainWindow\0displayTransformedPosition\0"
    "\0QVector<QList<Player> >\0"
    "on_actionTuning_Background_Model_triggered\0"
    "on_actionPer_Camera_Raw_View_triggered\0"
    "on_actionError_Calculation_triggered\0"
    "on_actionSystem_Performance_Testing_Metrics_triggered\0"
    "on_actionField_Selection_triggered\0"
    "on_actionTracking_View_triggered\0"
    "on_actionVideo_1_triggered\0"
    "on_actionVideo_2_triggered\0"
    "on_pushButton_play_released\0"
    "on_pushButton_single_play_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    0,   72,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->displayTransformedPosition((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 1: _t->on_actionTuning_Background_Model_triggered(); break;
        case 2: _t->on_actionPer_Camera_Raw_View_triggered(); break;
        case 3: _t->on_actionError_Calculation_triggered(); break;
        case 4: _t->on_actionSystem_Performance_Testing_Metrics_triggered(); break;
        case 5: _t->on_actionField_Selection_triggered(); break;
        case 6: _t->on_actionTracking_View_triggered(); break;
        case 7: _t->on_actionVideo_1_triggered(); break;
        case 8: _t->on_actionVideo_2_triggered(); break;
        case 9: _t->on_pushButton_play_released(); break;
        case 10: _t->on_pushButton_single_play_released(); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
