/****************************************************************************
** Meta object code from reading C++ file 'TraderSpi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/TraderSpi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TraderSpi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainTraderSpi_t {
    QByteArrayData data[15];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainTraderSpi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainTraderSpi_t qt_meta_stringdata_MainTraderSpi = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainTraderSpi"
QT_MOC_LITERAL(1, 14, 14), // "FrontConnected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "UserLogined"
QT_MOC_LITERAL(4, 42, 8), // "front_id"
QT_MOC_LITERAL(5, 51, 10), // "session_id"
QT_MOC_LITERAL(6, 62, 13), // "iNextOrderRef"
QT_MOC_LITERAL(7, 76, 23), // "SettlementInfoConfirmed"
QT_MOC_LITERAL(8, 100, 20), // "TraderBalanceUpdated"
QT_MOC_LITERAL(9, 121, 7), // "balance"
QT_MOC_LITERAL(10, 129, 11), // "closeProfit"
QT_MOC_LITERAL(11, 141, 14), // "positionProfit"
QT_MOC_LITERAL(12, 156, 13), // "RtnTradeEvent"
QT_MOC_LITERAL(13, 170, 20), // "CThostFtdcTradeField"
QT_MOC_LITERAL(14, 191, 10) // "tradeField"

    },
    "MainTraderSpi\0FrontConnected\0\0UserLogined\0"
    "front_id\0session_id\0iNextOrderRef\0"
    "SettlementInfoConfirmed\0TraderBalanceUpdated\0"
    "balance\0closeProfit\0positionProfit\0"
    "RtnTradeEvent\0CThostFtdcTradeField\0"
    "tradeField"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainTraderSpi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    3,   40,    2, 0x06 /* Public */,
       7,    0,   47,    2, 0x06 /* Public */,
       8,    3,   48,    2, 0x06 /* Public */,
      12,    1,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    9,   10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void MainTraderSpi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainTraderSpi *_t = static_cast<MainTraderSpi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->FrontConnected(); break;
        case 1: _t->UserLogined((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->SettlementInfoConfirmed(); break;
        case 3: _t->TraderBalanceUpdated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 4: _t->RtnTradeEvent((*reinterpret_cast< CThostFtdcTradeField(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainTraderSpi::FrontConnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainTraderSpi::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainTraderSpi::UserLogined)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainTraderSpi::SettlementInfoConfirmed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainTraderSpi::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainTraderSpi::TraderBalanceUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainTraderSpi::*_t)(CThostFtdcTradeField );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainTraderSpi::RtnTradeEvent)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainTraderSpi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainTraderSpi.data,
      qt_meta_data_MainTraderSpi,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainTraderSpi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainTraderSpi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainTraderSpi.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CThostFtdcTraderSpi"))
        return static_cast< CThostFtdcTraderSpi*>(this);
    return QObject::qt_metacast(_clname);
}

int MainTraderSpi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void MainTraderSpi::FrontConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainTraderSpi::UserLogined(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainTraderSpi::SettlementInfoConfirmed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainTraderSpi::TraderBalanceUpdated(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainTraderSpi::RtnTradeEvent(CThostFtdcTradeField _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_FollowTraderSpi_t {
    QByteArrayData data[16];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FollowTraderSpi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FollowTraderSpi_t qt_meta_stringdata_FollowTraderSpi = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FollowTraderSpi"
QT_MOC_LITERAL(1, 16, 20), // "TraderBalanceUpdated"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "index"
QT_MOC_LITERAL(4, 44, 7), // "balance"
QT_MOC_LITERAL(5, 52, 11), // "closeProfit"
QT_MOC_LITERAL(6, 64, 14), // "positionProfit"
QT_MOC_LITERAL(7, 79, 19), // "TraderStatusUpdated"
QT_MOC_LITERAL(8, 99, 7), // "message"
QT_MOC_LITERAL(9, 107, 17), // "EventTableUpdated"
QT_MOC_LITERAL(10, 125, 13), // "TraderLogined"
QT_MOC_LITERAL(11, 139, 13), // "RtnTradeEvent"
QT_MOC_LITERAL(12, 153, 20), // "CThostFtdcTradeField"
QT_MOC_LITERAL(13, 174, 10), // "tradeField"
QT_MOC_LITERAL(14, 185, 12), // "RspErrorInfo"
QT_MOC_LITERAL(15, 198, 10) // "ReqConnect"

    },
    "FollowTraderSpi\0TraderBalanceUpdated\0"
    "\0index\0balance\0closeProfit\0positionProfit\0"
    "TraderStatusUpdated\0message\0"
    "EventTableUpdated\0TraderLogined\0"
    "RtnTradeEvent\0CThostFtdcTradeField\0"
    "tradeField\0RspErrorInfo\0ReqConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FollowTraderSpi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,
       7,    2,   58,    2, 0x06 /* Public */,
       9,    1,   63,    2, 0x06 /* Public */,
      10,    1,   66,    2, 0x06 /* Public */,
      11,    1,   69,    2, 0x06 /* Public */,
      14,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FollowTraderSpi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FollowTraderSpi *_t = static_cast<FollowTraderSpi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TraderBalanceUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->TraderStatusUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->EventTableUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->TraderLogined((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->RtnTradeEvent((*reinterpret_cast< CThostFtdcTradeField(*)>(_a[1]))); break;
        case 5: _t->RspErrorInfo(); break;
        case 6: _t->ReqConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FollowTraderSpi::*_t)(int , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FollowTraderSpi::TraderBalanceUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FollowTraderSpi::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FollowTraderSpi::TraderStatusUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FollowTraderSpi::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FollowTraderSpi::EventTableUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FollowTraderSpi::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FollowTraderSpi::TraderLogined)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FollowTraderSpi::*_t)(CThostFtdcTradeField );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FollowTraderSpi::RtnTradeEvent)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (FollowTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FollowTraderSpi::RspErrorInfo)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject FollowTraderSpi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FollowTraderSpi.data,
      qt_meta_data_FollowTraderSpi,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FollowTraderSpi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FollowTraderSpi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FollowTraderSpi.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CThostFtdcTraderSpi"))
        return static_cast< CThostFtdcTraderSpi*>(this);
    return QObject::qt_metacast(_clname);
}

int FollowTraderSpi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FollowTraderSpi::TraderBalanceUpdated(int _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FollowTraderSpi::TraderStatusUpdated(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FollowTraderSpi::EventTableUpdated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FollowTraderSpi::TraderLogined(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FollowTraderSpi::RtnTradeEvent(CThostFtdcTradeField _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FollowTraderSpi::RspErrorInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
