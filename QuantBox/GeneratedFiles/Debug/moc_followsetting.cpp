/****************************************************************************
** Meta object code from reading C++ file 'followsetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/followsetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'followsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FollowSetting_t {
    QByteArrayData data[10];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FollowSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FollowSetting_t qt_meta_stringdata_FollowSetting = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FollowSetting"
QT_MOC_LITERAL(1, 14, 17), // "followCellClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "row"
QT_MOC_LITERAL(4, 37, 3), // "col"
QT_MOC_LITERAL(5, 41, 18), // "BrokerNameselected"
QT_MOC_LITERAL(6, 60, 10), // "brokerName"
QT_MOC_LITERAL(7, 71, 16), // "insertBtnClicked"
QT_MOC_LITERAL(8, 88, 16), // "deleteBtnClicked"
QT_MOC_LITERAL(9, 105, 16) // "updateBtnClicked"

    },
    "FollowSetting\0followCellClicked\0\0row\0"
    "col\0BrokerNameselected\0brokerName\0"
    "insertBtnClicked\0deleteBtnClicked\0"
    "updateBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FollowSetting[] = {

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
       1,    2,   39,    2, 0x08 /* Private */,
       5,    1,   44,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FollowSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FollowSetting *_t = static_cast<FollowSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->followCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->BrokerNameselected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->insertBtnClicked(); break;
        case 3: _t->deleteBtnClicked(); break;
        case 4: _t->updateBtnClicked(); break;
        default: ;
        }
    }
}

const QMetaObject FollowSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FollowSetting.data,
      qt_meta_data_FollowSetting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FollowSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FollowSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FollowSetting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FollowSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
