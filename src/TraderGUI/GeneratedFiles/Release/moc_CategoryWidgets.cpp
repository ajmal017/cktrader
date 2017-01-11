/****************************************************************************
** Meta object code from reading C++ file 'CategoryWidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CategoryWidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CategoryWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AbstractCategory_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractCategory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractCategory_t qt_meta_stringdata_AbstractCategory = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AbstractCategory"
QT_MOC_LITERAL(1, 17, 12), // "pageExpanded"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "expanded"
QT_MOC_LITERAL(4, 40, 8), // "setTitle"
QT_MOC_LITERAL(5, 49, 5), // "title"
QT_MOC_LITERAL(6, 55, 11), // "setExpanded"
QT_MOC_LITERAL(7, 67, 13), // "onButtonPress"
QT_MOC_LITERAL(8, 81, 12) // "onPageExpand"

    },
    "AbstractCategory\0pageExpanded\0\0expanded\0"
    "setTitle\0title\0setExpanded\0onButtonPress\0"
    "onPageExpand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractCategory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       6,    1,   50,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x09 /* Protected */,
       8,    1,   54,    2, 0x09 /* Protected */,
       8,    0,   57,    2, 0x29 /* Protected | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void AbstractCategory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractCategory *_t = static_cast<AbstractCategory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pageExpanded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setExpanded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onButtonPress(); break;
        case 4: _t->onPageExpand((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onPageExpand(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractCategory::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractCategory::pageExpanded)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AbstractCategory::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AbstractCategory.data,
      qt_meta_data_AbstractCategory,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AbstractCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractCategory.stringdata0))
        return static_cast<void*>(const_cast< AbstractCategory*>(this));
    return QWidget::qt_metacast(_clname);
}

int AbstractCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AbstractCategory::pageExpanded(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ButtonCategory_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ButtonCategory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ButtonCategory_t qt_meta_stringdata_ButtonCategory = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ButtonCategory"
QT_MOC_LITERAL(1, 15, 8), // "setTitle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "title"
QT_MOC_LITERAL(4, 31, 13) // "onButtonPress"

    },
    "ButtonCategory\0setTitle\0\0title\0"
    "onButtonPress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ButtonCategory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void ButtonCategory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ButtonCategory *_t = static_cast<ButtonCategory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onButtonPress(); break;
        default: ;
        }
    }
}

const QMetaObject ButtonCategory::staticMetaObject = {
    { &AbstractCategory::staticMetaObject, qt_meta_stringdata_ButtonCategory.data,
      qt_meta_data_ButtonCategory,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ButtonCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ButtonCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ButtonCategory.stringdata0))
        return static_cast<void*>(const_cast< ButtonCategory*>(this));
    return AbstractCategory::qt_metacast(_clname);
}

int ButtonCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCategory::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_LineCategory_t {
    QByteArrayData data[6];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineCategory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineCategory_t qt_meta_stringdata_LineCategory = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LineCategory"
QT_MOC_LITERAL(1, 13, 8), // "setTitle"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "title"
QT_MOC_LITERAL(4, 29, 11), // "setExpanded"
QT_MOC_LITERAL(5, 41, 8) // "expanded"

    },
    "LineCategory\0setTitle\0\0title\0setExpanded\0"
    "expanded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineCategory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void LineCategory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineCategory *_t = static_cast<LineCategory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setExpanded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LineCategory::staticMetaObject = {
    { &AbstractCategory::staticMetaObject, qt_meta_stringdata_LineCategory.data,
      qt_meta_data_LineCategory,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LineCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LineCategory.stringdata0))
        return static_cast<void*>(const_cast< LineCategory*>(this));
    return AbstractCategory::qt_metacast(_clname);
}

int LineCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCategory::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
