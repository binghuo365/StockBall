/****************************************************************************
** Meta object code from reading C++ file 'stockball.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../stockball.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockball.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StockBall_t {
    QByteArrayData data[7];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockBall_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockBall_t qt_meta_stringdata_StockBall = {
    {
QT_MOC_LITERAL(0, 0, 9), // "StockBall"
QT_MOC_LITERAL(1, 10, 10), // "DisplayMsg"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "iconIsActived"
QT_MOC_LITERAL(4, 36, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(5, 70, 6), // "reason"
QT_MOC_LITERAL(6, 77, 7) // "timeOut"

    },
    "StockBall\0DisplayMsg\0\0iconIsActived\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0timeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockBall[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       3,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void StockBall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockBall *_t = static_cast<StockBall *>(_o);
        switch (_id) {
        case 0: _t->DisplayMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->iconIsActived((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 2: _t->timeOut(); break;
        default: ;
        }
    }
}

const QMetaObject StockBall::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StockBall.data,
      qt_meta_data_StockBall,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockBall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockBall::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockBall.stringdata))
        return static_cast<void*>(const_cast< StockBall*>(this));
    return QWidget::qt_metacast(_clname);
}

int StockBall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
