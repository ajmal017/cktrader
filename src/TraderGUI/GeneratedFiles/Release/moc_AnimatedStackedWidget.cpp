/****************************************************************************
** Meta object code from reading C++ file 'AnimatedStackedWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnimatedStackedWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimatedStackedWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimatedStackedWidget_t {
    QByteArrayData data[10];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimatedStackedWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimatedStackedWidget_t qt_meta_stringdata_AnimatedStackedWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AnimatedStackedWidget"
QT_MOC_LITERAL(1, 22, 17), // "transitionStarted"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 14), // "currentChanged"
QT_MOC_LITERAL(4, 56, 1), // "x"
QT_MOC_LITERAL(5, 58, 18), // "transitionFinished"
QT_MOC_LITERAL(6, 77, 17), // "__transitionStart"
QT_MOC_LITERAL(7, 95, 22), // "__onTransitionFinished"
QT_MOC_LITERAL(8, 118, 24), // "__onLayoutCurrentChanged"
QT_MOC_LITERAL(9, 143, 5) // "index"

    },
    "AnimatedStackedWidget\0transitionStarted\0"
    "\0currentChanged\0x\0transitionFinished\0"
    "__transitionStart\0__onTransitionFinished\0"
    "__onLayoutCurrentChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimatedStackedWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void AnimatedStackedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimatedStackedWidget *_t = static_cast<AnimatedStackedWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->transitionStarted(); break;
        case 1: _t->currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->transitionFinished(); break;
        case 3: _t->__transitionStart(); break;
        case 4: _t->__onTransitionFinished(); break;
        case 5: _t->__onLayoutCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AnimatedStackedWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimatedStackedWidget::transitionStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AnimatedStackedWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimatedStackedWidget::currentChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AnimatedStackedWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimatedStackedWidget::transitionFinished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AnimatedStackedWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_AnimatedStackedWidget.data,
      qt_meta_data_AnimatedStackedWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnimatedStackedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimatedStackedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnimatedStackedWidget.stringdata0))
        return static_cast<void*>(const_cast< AnimatedStackedWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int AnimatedStackedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void AnimatedStackedWidget::transitionStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AnimatedStackedWidget::currentChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AnimatedStackedWidget::transitionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
