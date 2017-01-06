/****************************************************************************
** Meta object code from reading C++ file 'TraderGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TraderGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TraderGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TraderGUI_t {
    QByteArrayData data[15];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TraderGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TraderGUI_t qt_meta_stringdata_TraderGUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TraderGUI"
QT_MOC_LITERAL(1, 10, 14), // "slotClickedBtn"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "slotSplitterMoved"
QT_MOC_LITERAL(4, 44, 3), // "pos"
QT_MOC_LITERAL(5, 48, 5), // "index"
QT_MOC_LITERAL(6, 54, 24), // "ctpActionLogin_triggered"
QT_MOC_LITERAL(7, 79, 25), // "ctpActionLogout_triggered"
QT_MOC_LITERAL(8, 105, 25), // "ctpActionConfig_triggered"
QT_MOC_LITERAL(9, 131, 24), // "ltsActionLogin_triggered"
QT_MOC_LITERAL(10, 156, 25), // "ltsActionLogout_triggered"
QT_MOC_LITERAL(11, 182, 25), // "ltsActionConfig_triggered"
QT_MOC_LITERAL(12, 208, 23), // "ibActionLogin_triggered"
QT_MOC_LITERAL(13, 232, 24), // "ibActionLogout_triggered"
QT_MOC_LITERAL(14, 257, 24) // "ibActionConfig_triggered"

    },
    "TraderGUI\0slotClickedBtn\0\0slotSplitterMoved\0"
    "pos\0index\0ctpActionLogin_triggered\0"
    "ctpActionLogout_triggered\0"
    "ctpActionConfig_triggered\0"
    "ltsActionLogin_triggered\0"
    "ltsActionLogout_triggered\0"
    "ltsActionConfig_triggered\0"
    "ibActionLogin_triggered\0"
    "ibActionLogout_triggered\0"
    "ibActionConfig_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TraderGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    2,   70,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TraderGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TraderGUI *_t = static_cast<TraderGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotClickedBtn(); break;
        case 1: _t->slotSplitterMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ctpActionLogin_triggered(); break;
        case 3: _t->ctpActionLogout_triggered(); break;
        case 4: _t->ctpActionConfig_triggered(); break;
        case 5: _t->ltsActionLogin_triggered(); break;
        case 6: _t->ltsActionLogout_triggered(); break;
        case 7: _t->ltsActionConfig_triggered(); break;
        case 8: _t->ibActionLogin_triggered(); break;
        case 9: _t->ibActionLogout_triggered(); break;
        case 10: _t->ibActionConfig_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject TraderGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TraderGUI.data,
      qt_meta_data_TraderGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TraderGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TraderGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TraderGUI.stringdata0))
        return static_cast<void*>(const_cast< TraderGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TraderGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
