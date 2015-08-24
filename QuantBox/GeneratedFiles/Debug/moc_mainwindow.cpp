/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 12),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 15),
QT_MOC_LITERAL(4, 41, 17),
QT_MOC_LITERAL(5, 59, 15),
QT_MOC_LITERAL(6, 75, 17),
QT_MOC_LITERAL(7, 93, 18),
QT_MOC_LITERAL(8, 112, 5),
QT_MOC_LITERAL(9, 118, 18),
QT_MOC_LITERAL(10, 137, 20),
QT_MOC_LITERAL(11, 158, 19),
QT_MOC_LITERAL(12, 178, 23),
QT_MOC_LITERAL(13, 202, 21),
QT_MOC_LITERAL(14, 224, 20),
QT_MOC_LITERAL(15, 245, 16),
QT_MOC_LITERAL(16, 262, 7),
QT_MOC_LITERAL(17, 270, 17),
QT_MOC_LITERAL(18, 288, 7),
QT_MOC_LITERAL(19, 296, 14),
QT_MOC_LITERAL(20, 311, 11),
QT_MOC_LITERAL(21, 323, 18),
QT_MOC_LITERAL(22, 342, 19),
QT_MOC_LITERAL(23, 362, 16)
    },
    "MainWindow\0TraderLogout\0\0loadMainAccount\0"
    "loadFollowAccount\0mainTraderLogin\0"
    "FollowTraderLogin\0connectFollow2Main\0"
    "index\0mainSettingClicked\0followSettingClicked\0"
    "brokerManageClicked\0strategySetttingClicked\0"
    "beginFollowBtnClicked\0stopFollowBtnClicked\0"
    "UpdateMainStatus\0message\0UpdateMainBalance\0"
    "balance\0positionProfit\0closeProfit\0"
    "UpdateFollowStatus\0UpdateFollowBalance\0"
    "InsertEventTable\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,  100,    2, 0x08,
       4,    0,  101,    2, 0x08,
       5,    0,  102,    2, 0x08,
       6,    0,  103,    2, 0x08,
       7,    1,  104,    2, 0x08,
       9,    0,  107,    2, 0x08,
      10,    0,  108,    2, 0x08,
      11,    0,  109,    2, 0x08,
      12,    0,  110,    2, 0x08,
      13,    0,  111,    2, 0x08,
      14,    0,  112,    2, 0x08,
      15,    1,  113,    2, 0x08,
      17,    3,  116,    2, 0x08,
      21,    2,  123,    2, 0x08,
      22,    4,  128,    2, 0x08,
      23,    1,  137,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   18,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    8,   18,   19,   20,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->TraderLogout(); break;
        case 1: _t->loadMainAccount(); break;
        case 2: _t->loadFollowAccount(); break;
        case 3: _t->mainTraderLogin(); break;
        case 4: _t->FollowTraderLogin(); break;
        case 5: _t->connectFollow2Main((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->mainSettingClicked(); break;
        case 7: _t->followSettingClicked(); break;
        case 8: _t->brokerManageClicked(); break;
        case 9: _t->strategySetttingClicked(); break;
        case 10: _t->beginFollowBtnClicked(); break;
        case 11: _t->stopFollowBtnClicked(); break;
        case 12: _t->UpdateMainStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->UpdateMainBalance((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 14: _t->UpdateFollowStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->UpdateFollowBalance((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 16: _t->InsertEventTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::TraderLogout)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::TraderLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
