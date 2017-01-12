/****************************************************************************
** Meta object code from reading C++ file 'widgetbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widgetbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetBox_t {
    QByteArrayData data[28];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetBox_t qt_meta_stringdata_WidgetBox = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WidgetBox"
QT_MOC_LITERAL(1, 10, 19), // "currentIndexChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "index"
QT_MOC_LITERAL(4, 37, 16), // "pageTitleChanged"
QT_MOC_LITERAL(5, 54, 5), // "title"
QT_MOC_LITERAL(6, 60, 15), // "setCurrentIndex"
QT_MOC_LITERAL(7, 76, 7), // "addPage"
QT_MOC_LITERAL(8, 84, 8), // "QWidget*"
QT_MOC_LITERAL(9, 93, 6), // "widget"
QT_MOC_LITERAL(10, 100, 10), // "insertPage"
QT_MOC_LITERAL(11, 111, 10), // "removePage"
QT_MOC_LITERAL(12, 122, 12), // "setPageTitle"
QT_MOC_LITERAL(13, 135, 8), // "newTitle"
QT_MOC_LITERAL(14, 144, 15), // "setPageExpanded"
QT_MOC_LITERAL(15, 160, 8), // "expanded"
QT_MOC_LITERAL(16, 169, 13), // "onItemClicked"
QT_MOC_LITERAL(17, 183, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(18, 200, 4), // "item"
QT_MOC_LITERAL(19, 205, 23), // "setPageExpandedProperty"
QT_MOC_LITERAL(20, 229, 12), // "currentIndex"
QT_MOC_LITERAL(21, 242, 9), // "pageTitle"
QT_MOC_LITERAL(22, 252, 14), // "isPageExpanded"
QT_MOC_LITERAL(23, 267, 12), // "categoryType"
QT_MOC_LITERAL(24, 280, 12), // "CategoryType"
QT_MOC_LITERAL(25, 293, 6), // "Button"
QT_MOC_LITERAL(26, 300, 4), // "Line"
QT_MOC_LITERAL(27, 305, 5) // "Frame"

    },
    "WidgetBox\0currentIndexChanged\0\0index\0"
    "pageTitleChanged\0title\0setCurrentIndex\0"
    "addPage\0QWidget*\0widget\0insertPage\0"
    "removePage\0setPageTitle\0newTitle\0"
    "setPageExpanded\0expanded\0onItemClicked\0"
    "QTreeWidgetItem*\0item\0setPageExpandedProperty\0"
    "currentIndex\0pageTitle\0isPageExpanded\0"
    "categoryType\0CategoryType\0Button\0Line\0"
    "Frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       4,  106, // properties
       1,  118, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   75,    2, 0x0a /* Public */,
       7,    1,   78,    2, 0x0a /* Public */,
      10,    2,   81,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x0a /* Public */,
      14,    2,   95,    2, 0x0a /* Public */,
      16,    2,  100,    2, 0x09 /* Protected */,
      19,    0,  105,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    3,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   15,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Int,   18,    2,
    QMetaType::Void,

 // properties: name, type, flags
      20, QMetaType::Int, 0x00095103,
      21, QMetaType::QString, 0x00095103,
      22, QMetaType::Bool, 0x00095003,
      23, 0x80000000 | 24, 0x0009510b,

 // enums: name, flags, count, data
      24, 0x0,    3,  122,

 // enum data: key, value
      25, uint(WidgetBox::Button),
      26, uint(WidgetBox::Line),
      27, uint(WidgetBox::Frame),

       0        // eod
};

void WidgetBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetBox *_t = static_cast<WidgetBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pageTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addPage((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->insertPage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 5: _t->removePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setPageTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setPageExpanded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setPageExpanded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->onItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->setPageExpandedProperty(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WidgetBox::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetBox::currentIndexChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WidgetBox::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetBox::pageTitleChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WidgetBox *_t = static_cast<WidgetBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentIndex(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->pageTitle(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isPageExpanded(); break;
        case 3: *reinterpret_cast< CategoryType*>(_v) = _t->categoryType(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WidgetBox *_t = static_cast<WidgetBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setPageTitle(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setPageExpanded(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setCategoryType(*reinterpret_cast< CategoryType*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject WidgetBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetBox.data,
      qt_meta_data_WidgetBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WidgetBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetBox.stringdata0))
        return static_cast<void*>(const_cast< WidgetBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WidgetBox::currentIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetBox::pageTitleChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
