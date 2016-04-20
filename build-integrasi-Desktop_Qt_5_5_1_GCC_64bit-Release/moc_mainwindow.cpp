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
    QByteArrayData data[44];
    char stringdata0[1106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "sendAllIdAssigned"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 23), // "QVector<QList<Player> >"
QT_MOC_LITERAL(4, 54, 26), // "displayTransformedPosition"
QT_MOC_LITERAL(5, 81, 14), // "initListPlayer"
QT_MOC_LITERAL(6, 96, 28), // "setCameraViewFirstFrameImage"
QT_MOC_LITERAL(7, 125, 15), // "QVector<QImage>"
QT_MOC_LITERAL(8, 141, 26), // "updateCameraViewFrameImage"
QT_MOC_LITERAL(9, 168, 25), // "QVector<QVector<QImage> >"
QT_MOC_LITERAL(10, 194, 5), // "image"
QT_MOC_LITERAL(11, 200, 17), // "setValueParameter"
QT_MOC_LITERAL(12, 218, 22), // "QVector<QVector<int> >"
QT_MOC_LITERAL(13, 241, 14), // "valueParameter"
QT_MOC_LITERAL(14, 256, 23), // "setTrapeziumCoordinates"
QT_MOC_LITERAL(15, 280, 23), // "QVector<QList<QPoint> >"
QT_MOC_LITERAL(16, 304, 20), // "trapeziumCoordinates"
QT_MOC_LITERAL(17, 325, 34), // "displayAssignedTransformedPos..."
QT_MOC_LITERAL(18, 360, 27), // "assignedTransformedPosition"
QT_MOC_LITERAL(19, 388, 42), // "on_actionTuning_Background_Mo..."
QT_MOC_LITERAL(20, 431, 38), // "on_actionPer_Camera_Raw_View_..."
QT_MOC_LITERAL(21, 470, 36), // "on_actionError_Calculation_tr..."
QT_MOC_LITERAL(22, 507, 53), // "on_actionSystem_Performance_T..."
QT_MOC_LITERAL(23, 561, 34), // "on_actionField_Selection_trig..."
QT_MOC_LITERAL(24, 596, 32), // "on_actionTracking_View_triggered"
QT_MOC_LITERAL(25, 629, 26), // "on_actionVideo_1_triggered"
QT_MOC_LITERAL(26, 656, 26), // "on_actionVideo_2_triggered"
QT_MOC_LITERAL(27, 683, 28), // "on_actionData_View_triggered"
QT_MOC_LITERAL(28, 712, 27), // "on_pushButton_play_released"
QT_MOC_LITERAL(29, 740, 34), // "on_pushButton_single_play_rel..."
QT_MOC_LITERAL(30, 775, 16), // "assignIdFromList"
QT_MOC_LITERAL(31, 792, 7), // "QPoint&"
QT_MOC_LITERAL(32, 800, 3), // "pos"
QT_MOC_LITERAL(33, 804, 24), // "on_listTeamA_itemClicked"
QT_MOC_LITERAL(34, 829, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(35, 846, 4), // "item"
QT_MOC_LITERAL(36, 851, 24), // "on_listTeamB_itemClicked"
QT_MOC_LITERAL(37, 876, 40), // "on_pushButton_initialize_obje..."
QT_MOC_LITERAL(38, 917, 36), // "on_slider_global_frame_slider..."
QT_MOC_LITERAL(39, 954, 37), // "on_slider_global_frame_slider..."
QT_MOC_LITERAL(40, 992, 35), // "on_slider_global_frame_valueC..."
QT_MOC_LITERAL(41, 1028, 5), // "value"
QT_MOC_LITERAL(42, 1034, 29), // "on_pushButton_send_id_clicked"
QT_MOC_LITERAL(43, 1064, 41) // "on_pushButton_load_default_vi..."

    },
    "MainWindow\0sendAllIdAssigned\0\0"
    "QVector<QList<Player> >\0"
    "displayTransformedPosition\0initListPlayer\0"
    "setCameraViewFirstFrameImage\0"
    "QVector<QImage>\0updateCameraViewFrameImage\0"
    "QVector<QVector<QImage> >\0image\0"
    "setValueParameter\0QVector<QVector<int> >\0"
    "valueParameter\0setTrapeziumCoordinates\0"
    "QVector<QList<QPoint> >\0trapeziumCoordinates\0"
    "displayAssignedTransformedPosition\0"
    "assignedTransformedPosition\0"
    "on_actionTuning_Background_Model_triggered\0"
    "on_actionPer_Camera_Raw_View_triggered\0"
    "on_actionError_Calculation_triggered\0"
    "on_actionSystem_Performance_Testing_Metrics_triggered\0"
    "on_actionField_Selection_triggered\0"
    "on_actionTracking_View_triggered\0"
    "on_actionVideo_1_triggered\0"
    "on_actionVideo_2_triggered\0"
    "on_actionData_View_triggered\0"
    "on_pushButton_play_released\0"
    "on_pushButton_single_play_released\0"
    "assignIdFromList\0QPoint&\0pos\0"
    "on_listTeamA_itemClicked\0QListWidgetItem*\0"
    "item\0on_listTeamB_itemClicked\0"
    "on_pushButton_initialize_object_released\0"
    "on_slider_global_frame_sliderPressed\0"
    "on_slider_global_frame_sliderReleased\0"
    "on_slider_global_frame_valueChanged\0"
    "value\0on_pushButton_send_id_clicked\0"
    "on_pushButton_load_default_video_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  157,    2, 0x0a /* Public */,
       5,    0,  160,    2, 0x0a /* Public */,
       6,    1,  161,    2, 0x0a /* Public */,
       8,    1,  164,    2, 0x0a /* Public */,
      11,    1,  167,    2, 0x0a /* Public */,
      14,    1,  170,    2, 0x0a /* Public */,
      17,    1,  173,    2, 0x0a /* Public */,
      19,    0,  176,    2, 0x08 /* Private */,
      20,    0,  177,    2, 0x08 /* Private */,
      21,    0,  178,    2, 0x08 /* Private */,
      22,    0,  179,    2, 0x08 /* Private */,
      23,    0,  180,    2, 0x08 /* Private */,
      24,    0,  181,    2, 0x08 /* Private */,
      25,    0,  182,    2, 0x08 /* Private */,
      26,    0,  183,    2, 0x08 /* Private */,
      27,    0,  184,    2, 0x08 /* Private */,
      28,    0,  185,    2, 0x08 /* Private */,
      29,    0,  186,    2, 0x08 /* Private */,
      30,    1,  187,    2, 0x08 /* Private */,
      33,    1,  190,    2, 0x08 /* Private */,
      36,    1,  193,    2, 0x08 /* Private */,
      37,    0,  196,    2, 0x08 /* Private */,
      38,    0,  197,    2, 0x08 /* Private */,
      39,    0,  198,    2, 0x08 /* Private */,
      40,    1,  199,    2, 0x08 /* Private */,
      42,    0,  202,    2, 0x08 /* Private */,
      43,    0,  203,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 3,   18,
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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   41,
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
        case 0: _t->sendAllIdAssigned((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 1: _t->displayTransformedPosition((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 2: _t->initListPlayer(); break;
        case 3: _t->setCameraViewFirstFrameImage((*reinterpret_cast< QVector<QImage>(*)>(_a[1]))); break;
        case 4: _t->updateCameraViewFrameImage((*reinterpret_cast< QVector<QVector<QImage> >(*)>(_a[1]))); break;
        case 5: _t->setValueParameter((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1]))); break;
        case 6: _t->setTrapeziumCoordinates((*reinterpret_cast< QVector<QList<QPoint> >(*)>(_a[1]))); break;
        case 7: _t->displayAssignedTransformedPosition((*reinterpret_cast< QVector<QList<Player> >(*)>(_a[1]))); break;
        case 8: _t->on_actionTuning_Background_Model_triggered(); break;
        case 9: _t->on_actionPer_Camera_Raw_View_triggered(); break;
        case 10: _t->on_actionError_Calculation_triggered(); break;
        case 11: _t->on_actionSystem_Performance_Testing_Metrics_triggered(); break;
        case 12: _t->on_actionField_Selection_triggered(); break;
        case 13: _t->on_actionTracking_View_triggered(); break;
        case 14: _t->on_actionVideo_1_triggered(); break;
        case 15: _t->on_actionVideo_2_triggered(); break;
        case 16: _t->on_actionData_View_triggered(); break;
        case 17: _t->on_pushButton_play_released(); break;
        case 18: _t->on_pushButton_single_play_released(); break;
        case 19: _t->assignIdFromList((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 20: _t->on_listTeamA_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 21: _t->on_listTeamB_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 22: _t->on_pushButton_initialize_object_released(); break;
        case 23: _t->on_slider_global_frame_sliderPressed(); break;
        case 24: _t->on_slider_global_frame_sliderReleased(); break;
        case 25: _t->on_slider_global_frame_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_pushButton_send_id_clicked(); break;
        case 27: _t->on_pushButton_load_default_video_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QImage> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QImage> > >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QList<QPoint> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QVector<QList<Player> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendAllIdAssigned)) {
                *result = 0;
            }
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
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendAllIdAssigned(QVector<QList<Player> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
