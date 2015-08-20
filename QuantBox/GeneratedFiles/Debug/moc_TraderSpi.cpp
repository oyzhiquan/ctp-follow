/****************************************************************************
** Meta object code from reading C++ file 'TraderSpi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/TraderSpi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TraderSpi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTraderSpi_t {
    QByteArrayData data[17];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CTraderSpi_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CTraderSpi_t qt_meta_stringdata_CTraderSpi = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 17),
QT_MOC_LITERAL(4, 45, 12),
QT_MOC_LITERAL(5, 58, 8),
QT_MOC_LITERAL(6, 67, 10),
QT_MOC_LITERAL(7, 78, 13),
QT_MOC_LITERAL(8, 92, 24),
QT_MOC_LITERAL(9, 117, 20),
QT_MOC_LITERAL(10, 138, 7),
QT_MOC_LITERAL(11, 146, 11),
QT_MOC_LITERAL(12, 158, 14),
QT_MOC_LITERAL(13, 173, 13),
QT_MOC_LITERAL(14, 187, 20),
QT_MOC_LITERAL(15, 208, 10),
QT_MOC_LITERAL(16, 219, 12)
    },
    "CTraderSpi\0frontConnected\0\0frontDisconnected\0"
    "rspUserLogin\0front_id\0session_id\0"
    "iNextOrderRef\0rspSettlementInfoConfirm\0"
    "rspQryTradingAccount\0balance\0closeProfit\0"
    "positionProfit\0RtnTradeEvent\0"
    "CThostFtdcTradeField\0tradeField\0"
    "rspErrorInfo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTraderSpi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06,
       3,    0,   50,    2, 0x06,
       4,    3,   51,    2, 0x06,
       8,    0,   58,    2, 0x06,
       9,    3,   59,    2, 0x06,
      13,    1,   66,    2, 0x06,
      16,    0,   69,    2, 0x06,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,

       0        // eod
};

void CTraderSpi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTraderSpi *_t = static_cast<CTraderSpi *>(_o);
        switch (_id) {
        case 0: _t->frontConnected(); break;
        case 1: _t->frontDisconnected(); break;
        case 2: _t->rspUserLogin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->rspSettlementInfoConfirm(); break;
        case 4: _t->rspQryTradingAccount((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 5: _t->RtnTradeEvent((*reinterpret_cast< CThostFtdcTradeField(*)>(_a[1]))); break;
        case 6: _t->rspErrorInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::frontConnected)) {
                *result = 0;
            }
        }
        {
            typedef void (CTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::frontDisconnected)) {
                *result = 1;
            }
        }
        {
            typedef void (CTraderSpi::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::rspUserLogin)) {
                *result = 2;
            }
        }
        {
            typedef void (CTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::rspSettlementInfoConfirm)) {
                *result = 3;
            }
        }
        {
            typedef void (CTraderSpi::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::rspQryTradingAccount)) {
                *result = 4;
            }
        }
        {
            typedef void (CTraderSpi::*_t)(CThostFtdcTradeField );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::RtnTradeEvent)) {
                *result = 5;
            }
        }
        {
            typedef void (CTraderSpi::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTraderSpi::rspErrorInfo)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject CTraderSpi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CTraderSpi.data,
      qt_meta_data_CTraderSpi,  qt_static_metacall, 0, 0}
};


const QMetaObject *CTraderSpi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTraderSpi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CTraderSpi.stringdata))
        return static_cast<void*>(const_cast< CTraderSpi*>(this));
    if (!strcmp(_clname, "CThostFtdcTraderSpi"))
        return static_cast< CThostFtdcTraderSpi*>(const_cast< CTraderSpi*>(this));
    return QObject::qt_metacast(_clname);
}

int CTraderSpi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CTraderSpi::frontConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CTraderSpi::frontDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CTraderSpi::rspUserLogin(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CTraderSpi::rspSettlementInfoConfirm()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CTraderSpi::rspQryTradingAccount(double _t1, double _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CTraderSpi::RtnTradeEvent(CThostFtdcTradeField _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CTraderSpi::rspErrorInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
