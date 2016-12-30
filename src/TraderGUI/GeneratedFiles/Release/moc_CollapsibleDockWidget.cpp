/****************************************************************************
** Meta object code from reading C++ file 'CollapsibleDockWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CollapsibleDockWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CollapsibleDockWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CollapsibleDockWidget_t {
    QByteArrayData data[12];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CollapsibleDockWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CollapsibleDockWidget_t qt_meta_stringdata_CollapsibleDockWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CollapsibleDockWidget"
QT_MOC_LITERAL(1, 22, 15), // "expandedChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 1), // "s"
QT_MOC_LITERAL(4, 41, 19), // "__onFeaturesChanged"
QT_MOC_LITERAL(5, 61, 31), // "QDockWidget::DockWidgetFeatures"
QT_MOC_LITERAL(6, 93, 8), // "features"
QT_MOC_LITERAL(7, 102, 23), // "__onDockLocationChanged"
QT_MOC_LITERAL(8, 126, 18), // "Qt::DockWidgetArea"
QT_MOC_LITERAL(9, 145, 4), // "area"
QT_MOC_LITERAL(10, 150, 21), // "__onTransitionStarted"
QT_MOC_LITERAL(11, 172, 22) // "__onTransitionFinished"

    },
    "CollapsibleDockWidget\0expandedChanged\0"
    "\0s\0__onFeaturesChanged\0"
    "QDockWidget::DockWidgetFeatures\0"
    "features\0__onDockLocationChanged\0"
    "Qt::DockWidgetArea\0area\0__onTransitionStarted\0"
    "__onTransitionFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollapsibleDockWidget[] = {

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
       4,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,
      10,    0,   48,    2, 0x0a /* Public */,
      11,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CollapsibleDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CollapsibleDockWidget *_t = static_cast<CollapsibleDockWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->expandedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->__onFeaturesChanged((*reinterpret_cast< QDockWidget::DockWidgetFeatures(*)>(_a[1]))); break;
        case 2: _t->__onDockLocationChanged((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 3: _t->__onTransitionStarted(); break;
        case 4: _t->__onTransitionFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CollapsibleDockWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CollapsibleDockWidget::expandedChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CollapsibleDockWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_CollapsibleDockWidget.data,
      qt_meta_data_CollapsibleDockWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CollapsibleDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollapsibleDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CollapsibleDockWidget.stringdata0))
        return static_cast<void*>(const_cast< CollapsibleDockWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int CollapsibleDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
void CollapsibleDockWidget::expandedChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
