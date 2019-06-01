/****************************************************************************
** Meta object code from reading C++ file 'testbuilderwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testbuilderwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testbuilderwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_testBuilderwindow_t {
    QByteArrayData data[18];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_testBuilderwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_testBuilderwindow_t qt_meta_stringdata_testBuilderwindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "testBuilderwindow"
QT_MOC_LITERAL(1, 18, 11), // "receiveData"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "name"
QT_MOC_LITERAL(4, 36, 10), // "tabChanged"
QT_MOC_LITERAL(5, 47, 4), // "exit"
QT_MOC_LITERAL(6, 52, 6), // "detect"
QT_MOC_LITERAL(7, 59, 7), // "isExist"
QT_MOC_LITERAL(8, 67, 4), // "word"
QT_MOC_LITERAL(9, 72, 5), // "char*"
QT_MOC_LITERAL(10, 78, 8), // "fileName"
QT_MOC_LITERAL(11, 87, 11), // "writeToFile"
QT_MOC_LITERAL(12, 99, 1), // "n"
QT_MOC_LITERAL(13, 101, 7), // "confirm"
QT_MOC_LITERAL(14, 109, 6), // "search"
QT_MOC_LITERAL(15, 116, 6), // "update"
QT_MOC_LITERAL(16, 123, 11), // "rbtnChanged"
QT_MOC_LITERAL(17, 135, 9) // "displayMy"

    },
    "testBuilderwindow\0receiveData\0\0name\0"
    "tabChanged\0exit\0detect\0isExist\0word\0"
    "char*\0fileName\0writeToFile\0n\0confirm\0"
    "search\0update\0rbtnChanged\0displayMy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_testBuilderwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    0,   75,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    2,   77,    2, 0x08 /* Private */,
      11,    3,   82,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    1,   92,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9, QMetaType::Int,    8,   10,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void testBuilderwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<testBuilderwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->exit(); break;
        case 3: _t->detect(); break;
        case 4: { int _r = _t->isExist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->writeToFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->confirm(); break;
        case 7: _t->search(); break;
        case 8: _t->update(); break;
        case 9: _t->rbtnChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->displayMy(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject testBuilderwindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_testBuilderwindow.data,
    qt_meta_data_testBuilderwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *testBuilderwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *testBuilderwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_testBuilderwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int testBuilderwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
