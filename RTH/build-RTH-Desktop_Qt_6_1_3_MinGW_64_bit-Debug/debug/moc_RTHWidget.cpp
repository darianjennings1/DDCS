/****************************************************************************
** Meta object code from reading C++ file 'RTHWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RTH/RTHWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RTHWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RTHMainWindow_t {
    const uint offsetsAndSize[10];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RTHMainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RTHMainWindow_t qt_meta_stringdata_RTHMainWindow = {
    {
QT_MOC_LITERAL(0, 13), // "RTHMainWindow"
QT_MOC_LITERAL(14, 17), // "on_pb_RTH_clicked"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 17), // "on_pb_RTH_pressed"
QT_MOC_LITERAL(51, 18) // "on_pb_RTH_released"

    },
    "RTHMainWindow\0on_pb_RTH_clicked\0\0"
    "on_pb_RTH_pressed\0on_pb_RTH_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RTHMainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    0 /* Private */,
       3,    0,   33,    2, 0x08,    1 /* Private */,
       4,    0,   34,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RTHMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RTHMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pb_RTH_clicked(); break;
        case 1: _t->on_pb_RTH_pressed(); break;
        case 2: _t->on_pb_RTH_released(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject RTHMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_RTHMainWindow.offsetsAndSize,
    qt_meta_data_RTHMainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RTHMainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RTHMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RTHMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RTHMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RTHMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
