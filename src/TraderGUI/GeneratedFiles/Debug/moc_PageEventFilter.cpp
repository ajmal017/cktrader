/****************************************************************************
** Meta object code from reading C++ file 'PageEventFilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PageEventFilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PageEventFilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PageEventFilter_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageEventFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageEventFilter_t qt_meta_stringdata_PageEventFilter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PageEventFilter"
QT_MOC_LITERAL(1, 16, 11), // "itemClicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 46, 4), // "item"
QT_MOC_LITERAL(5, 51, 6) // "column"

    },
    "PageEventFilter\0itemClicked\0\0"
    "QTreeWidgetItem*\0item\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageEventFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

       0        // eod
};

void PageEventFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PageEventFilter *_t = static_cast<PageEventFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PageEventFilter::*_t)(QTreeWidgetItem * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PageEventFilter::itemClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PageEventFilter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PageEventFilter.data,
      qt_meta_data_PageEventFilter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PageEventFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageEventFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PageEventFilter.stringdata0))
        return static_cast<void*>(const_cast< PageEventFilter*>(this));
    return QObject::qt_metacast(_clname);
}

int PageEventFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void PageEventFilter::itemClicked(QTreeWidgetItem * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_PageResizeFilter_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PageResizeFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PageResizeFilter_t qt_meta_stringdata_PageResizeFilter = {
    {
QT_MOC_LITERAL(0, 0, 16) // "PageResizeFilter"

    },
    "PageResizeFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PageResizeFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PageResizeFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PageResizeFilter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PageResizeFilter.data,
      qt_meta_data_PageResizeFilter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PageResizeFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PageResizeFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PageResizeFilter.stringdata0))
        return static_cast<void*>(const_cast< PageResizeFilter*>(this));
    return QObject::qt_metacast(_clname);
}

int PageResizeFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
