/****************************************************************************
** Meta object code from reading C++ file 'Trader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/Trader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Trader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainTrader_t {
    QByteArrayData data[40];
    char stringdata[604];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainTrader_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainTrader_t qt_meta_stringdata_MainTrader = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 7),
QT_MOC_LITERAL(4, 40, 20),
QT_MOC_LITERAL(5, 61, 7),
QT_MOC_LITERAL(6, 69, 11),
QT_MOC_LITERAL(7, 81, 14),
QT_MOC_LITERAL(8, 96, 17),
QT_MOC_LITERAL(9, 114, 13),
QT_MOC_LITERAL(10, 128, 10),
QT_MOC_LITERAL(11, 139, 13),
QT_MOC_LITERAL(12, 153, 12),
QT_MOC_LITERAL(13, 166, 12),
QT_MOC_LITERAL(14, 179, 8),
QT_MOC_LITERAL(15, 188, 10),
QT_MOC_LITERAL(16, 199, 13),
QT_MOC_LITERAL(17, 213, 24),
QT_MOC_LITERAL(18, 238, 20),
QT_MOC_LITERAL(19, 259, 20),
QT_MOC_LITERAL(20, 280, 14),
QT_MOC_LITERAL(21, 295, 26),
QT_MOC_LITERAL(22, 322, 13),
QT_MOC_LITERAL(23, 336, 23),
QT_MOC_LITERAL(24, 360, 9),
QT_MOC_LITERAL(25, 370, 20),
QT_MOC_LITERAL(26, 391, 6),
QT_MOC_LITERAL(27, 398, 19),
QT_MOC_LITERAL(28, 418, 11),
QT_MOC_LITERAL(29, 430, 24),
QT_MOC_LITERAL(30, 455, 11),
QT_MOC_LITERAL(31, 467, 14),
QT_MOC_LITERAL(32, 482, 21),
QT_MOC_LITERAL(33, 504, 6),
QT_MOC_LITERAL(34, 511, 9),
QT_MOC_LITERAL(35, 521, 16),
QT_MOC_LITERAL(36, 538, 14),
QT_MOC_LITERAL(37, 553, 20),
QT_MOC_LITERAL(38, 574, 10),
QT_MOC_LITERAL(39, 585, 17)
    },
    "MainTrader\0TraderStatusUpdated\0\0message\0"
    "TraderBalanceUpdated\0balance\0closeProfit\0"
    "positionProfit\0EventTableUpdated\0"
    "TraderLogined\0ReqConnect\0ReqDisconnect\0"
    "ReqUserLogin\0RspUserLogin\0front_id\0"
    "session_id\0iNextOrderRef\0"
    "ReqSettlementInfoConfirm\0ReqQryTradingAccount\0"
    "RspQryTradingAccount\0ReqOrderInsert\0"
    "TThostFtdcInstrumentIDType\0INSTRUMENT_ID\0"
    "TThostFtdcDirectionType\0DIRECTION\0"
    "TThostFtdcVolumeType\0VOLUME\0"
    "TThostFtdcPriceType\0LIMIT_PRICE\0"
    "TThostFtdcOffsetFlagType\0OFFSET_FLAG\0"
    "ReqOrderAction\0CThostFtdcOrderField*\0"
    "pOrder\0IsMyOrder\0RspTradingAciton\0"
    "FollowRtnTrade\0CThostFtdcTradeField\0"
    "tradeField\0ProcessTradeEvent\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainTrader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06,
       4,    3,  102,    2, 0x06,
       8,    1,  109,    2, 0x06,
       9,    0,  112,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    0,  113,    2, 0x0a,
      11,    0,  114,    2, 0x0a,
      12,    0,  115,    2, 0x0a,
      13,    3,  116,    2, 0x0a,
      17,    0,  123,    2, 0x0a,
      18,    0,  124,    2, 0x0a,
      19,    3,  125,    2, 0x0a,
      20,    5,  132,    2, 0x0a,
      31,    1,  143,    2, 0x0a,
      34,    1,  146,    2, 0x0a,
      35,    0,  149,    2, 0x0a,
      36,    1,  150,    2, 0x0a,
      39,    1,  153,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 23, 0x80000000 | 25, 0x80000000 | 27, 0x80000000 | 29,   22,   24,   26,   28,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Bool, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, 0x80000000 | 37,   38,

       0        // eod
};

void MainTrader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainTrader *_t = static_cast<MainTrader *>(_o);
        switch (_id) {
        case 0: _t->TraderStatusUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->TraderBalanceUpdated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->EventTableUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->TraderLogined(); break;
        case 4: _t->ReqConnect(); break;
        case 5: _t->ReqDisconnect(); break;
        case 6: _t->ReqUserLogin(); break;
        case 7: _t->RspUserLogin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->ReqSettlementInfoConfirm(); break;
        case 9: _t->ReqQryTradingAccount(); break;
        case 10: _t->RspQryTradingAccount((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 11: _t->ReqOrderInsert((*reinterpret_cast< TThostFtdcInstrumentIDType(*)>(_a[1])),(*reinterpret_cast< TThostFtdcDirectionType(*)>(_a[2])),(*reinterpret_cast< TThostFtdcVolumeType(*)>(_a[3])),(*reinterpret_cast< TThostFtdcPriceType(*)>(_a[4])),(*reinterpret_cast< TThostFtdcOffsetFlagType(*)>(_a[5]))); break;
        case 12: _t->ReqOrderAction((*reinterpret_cast< CThostFtdcOrderField*(*)>(_a[1]))); break;
        case 13: { bool _r = _t->IsMyOrder((*reinterpret_cast< CThostFtdcOrderField*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: _t->RspTradingAciton(); break;
        case 15: _t->FollowRtnTrade((*reinterpret_cast< CThostFtdcTradeField(*)>(_a[1]))); break;
        case 16: _t->ProcessTradeEvent((*reinterpret_cast< CThostFtdcTradeField(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainTrader::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainTrader::TraderStatusUpdated)) {
                *result = 0;
            }
        }
        {
            typedef void (MainTrader::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainTrader::TraderBalanceUpdated)) {
                *result = 1;
            }
        }
        {
            typedef void (MainTrader::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainTrader::EventTableUpdated)) {
                *result = 2;
            }
        }
        {
            typedef void (MainTrader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainTrader::TraderLogined)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MainTrader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainTrader.data,
      qt_meta_data_MainTrader,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainTrader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainTrader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainTrader.stringdata))
        return static_cast<void*>(const_cast< MainTrader*>(this));
    return QObject::qt_metacast(_clname);
}

int MainTrader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MainTrader::TraderStatusUpdated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainTrader::TraderBalanceUpdated(double _t1, double _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainTrader::EventTableUpdated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainTrader::TraderLogined()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
