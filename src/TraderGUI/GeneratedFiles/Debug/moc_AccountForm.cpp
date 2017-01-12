/****************************************************************************
** Meta object code from reading C++ file 'AccountForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AccountForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccountForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccountForm_t {
    QByteArrayData data[7];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccountForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccountForm_t qt_meta_stringdata_AccountForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AccountForm"
QT_MOC_LITERAL(1, 12, 11), // "updateEvent"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "AccountData"
QT_MOC_LITERAL(4, 37, 2), // "er"
QT_MOC_LITERAL(5, 40, 13), // "updateContent"
QT_MOC_LITERAL(6, 54, 2) // "ac"

    },
    "AccountForm\0updateEvent\0\0AccountData\0"
    "er\0updateContent\0ac"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,

       0        // eod
};

void AccountForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccountForm *_t = static_cast<AccountForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateEvent((*reinterpret_cast< AccountData(*)>(_a[1]))); break;
        case 1: _t->updateContent((*reinterpret_cast< AccountData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AccountForm::*_t)(AccountData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccountForm::updateEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AccountForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AccountForm.data,
      qt_meta_data_AccountForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AccountForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AccountForm.stringdata0))
        return static_cast<void*>(const_cast< AccountForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int AccountForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AccountForm::updateEvent(AccountData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
