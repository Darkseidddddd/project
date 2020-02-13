/****************************************************************************
** Meta object code from reading C++ file 'playerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../playerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_playerwindow_t {
    QByteArrayData data[25];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_playerwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_playerwindow_t qt_meta_stringdata_playerwindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "playerwindow"
QT_MOC_LITERAL(1, 13, 10), // "sendsignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "exit"
QT_MOC_LITERAL(4, 30, 11), // "receiveData"
QT_MOC_LITERAL(5, 42, 4), // "name"
QT_MOC_LITERAL(6, 47, 7), // "getword"
QT_MOC_LITERAL(7, 55, 5), // "char*"
QT_MOC_LITERAL(8, 61, 8), // "fileName"
QT_MOC_LITERAL(9, 70, 5), // "start"
QT_MOC_LITERAL(10, 76, 7), // "start_1"
QT_MOC_LITERAL(11, 84, 7), // "start_2"
QT_MOC_LITERAL(12, 92, 7), // "start_3"
QT_MOC_LITERAL(13, 100, 4), // "play"
QT_MOC_LITERAL(14, 105, 5), // "check"
QT_MOC_LITERAL(15, 111, 7), // "restart"
QT_MOC_LITERAL(16, 119, 13), // "changePattern"
QT_MOC_LITERAL(17, 133, 5), // "index"
QT_MOC_LITERAL(18, 139, 9), // "multiplay"
QT_MOC_LITERAL(19, 149, 6), // "reshow"
QT_MOC_LITERAL(20, 156, 10), // "tabChanged"
QT_MOC_LITERAL(21, 167, 6), // "search"
QT_MOC_LITERAL(22, 174, 6), // "update"
QT_MOC_LITERAL(23, 181, 11), // "rbtnChanged"
QT_MOC_LITERAL(24, 193, 9) // "displayMy"

    },
    "playerwindow\0sendsignal\0\0exit\0receiveData\0"
    "name\0getword\0char*\0fileName\0start\0"
    "start_1\0start_2\0start_3\0play\0check\0"
    "restart\0changePattern\0index\0multiplay\0"
    "reshow\0tabChanged\0search\0update\0"
    "rbtnChanged\0displayMy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_playerwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  110,    2, 0x08 /* Private */,
       4,    1,  111,    2, 0x08 /* Private */,
       6,    1,  114,    2, 0x08 /* Private */,
       9,    0,  117,    2, 0x08 /* Private */,
      10,    0,  118,    2, 0x08 /* Private */,
      11,    0,  119,    2, 0x08 /* Private */,
      12,    0,  120,    2, 0x08 /* Private */,
      13,    0,  121,    2, 0x08 /* Private */,
      14,    0,  122,    2, 0x08 /* Private */,
      15,    0,  123,    2, 0x08 /* Private */,
      16,    1,  124,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    1,  129,    2, 0x08 /* Private */,
      21,    0,  132,    2, 0x08 /* Private */,
      22,    0,  133,    2, 0x08 /* Private */,
      23,    1,  134,    2, 0x08 /* Private */,
      24,    0,  137,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    0x80000000 | 7, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void playerwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<playerwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendsignal(); break;
        case 1: _t->exit(); break;
        case 2: _t->receiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: { char* _r = _t->getword((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = std::move(_r); }  break;
        case 4: _t->start(); break;
        case 5: _t->start_1(); break;
        case 6: _t->start_2(); break;
        case 7: _t->start_3(); break;
        case 8: _t->play(); break;
        case 9: _t->check(); break;
        case 10: _t->restart(); break;
        case 11: _t->changePattern((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->multiplay(); break;
        case 13: _t->reshow(); break;
        case 14: _t->tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->search(); break;
        case 16: _t->update(); break;
        case 17: _t->rbtnChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->displayMy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (playerwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playerwindow::sendsignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject playerwindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_playerwindow.data,
    qt_meta_data_playerwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *playerwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *playerwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_playerwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int playerwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void playerwindow::sendsignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
