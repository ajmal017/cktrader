/****************************************************************************
** Meta object code from reading C++ file 'TickForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TickForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TickForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TickForm_t {
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TickForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TickForm_t qt_meta_stringdata_TickForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TickForm"
QT_MOC_LITERAL(1, 9, 11), // "updateEvent"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "TickData"
QT_MOC_LITERAL(4, 31, 4), // "tick"
QT_MOC_LITERAL(5, 36, 27), // "pushButtonSendOrder_clicked"
QT_MOC_LITERAL(6, 64, 23), // "tableWidget_cellClicked"
QT_MOC_LITERAL(7, 88, 3), // "row"
QT_MOC_LITERAL(8, 92, 6), // "column"
QT_MOC_LITERAL(9, 99, 30), // "contractlineedit_returnPressed"
QT_MOC_LITERAL(10, 130, 13) // "updateContent"

    },
    "TickForm\0updateEvent\0\0TickData\0tick\0"
    "pushButtonSendOrder_clicked\0"
    "tableWidget_cellClicked\0row\0column\0"
    "contractlineedit_returnPressed\0"
    "updateContent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TickForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    2,   43,    2, 0x08 /* Private */,
       9,    0,   48,    2, 0x08 /* Private */,
      10,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void TickForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TickForm *_t = static_cast<TickForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateEvent((*reinterpret_cast< TickData(*)>(_a[1]))); break;
        case 1: _t->pushButtonSendOrder_clicked(); break;
        case 2: _t->tableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->contractlineedit_returnPressed(); break;
        case 4: _t->updateContent((*reinterpret_cast< TickData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TickForm::*_t)(TickData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TickForm::updateEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TickForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TickForm.data,
      qt_meta_data_TickForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TickForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TickForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TickForm.stringdata0))
        return static_cast<void*>(const_cast< TickForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int TickForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void TickForm::updateEvent(TickData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
