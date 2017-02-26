/****************************************************************************
** Meta object code from reading C++ file 'ClassifyWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ClassifyWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClassifyWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CClassifyWin_t {
    QByteArrayData data[13];
    char stringdata[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CClassifyWin_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CClassifyWin_t qt_meta_stringdata_CClassifyWin = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 9),
QT_MOC_LITERAL(4, 40, 9),
QT_MOC_LITERAL(5, 50, 20),
QT_MOC_LITERAL(6, 71, 20),
QT_MOC_LITERAL(7, 92, 20),
QT_MOC_LITERAL(8, 113, 18),
QT_MOC_LITERAL(9, 132, 18),
QT_MOC_LITERAL(10, 151, 20),
QT_MOC_LITERAL(11, 172, 12),
QT_MOC_LITERAL(12, 185, 5)
    },
    "CClassifyWin\0signal_SendData\0\0SDataPack\0"
    "aDataPack\0slot_clickedCheckBox\0"
    "slot_openTrainingSet\0slot_openClassifySet\0"
    "slot_beginClassify\0slot_beginTraining\0"
    "slot_operateFinished\0EOperateFlag\0"
    "aFlag\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CClassifyWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a,
       6,    1,   53,    2, 0x0a,
       7,    1,   56,    2, 0x0a,
       8,    1,   59,    2, 0x0a,
       9,    1,   62,    2, 0x0a,
      10,    1,   65,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void CClassifyWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CClassifyWin *_t = static_cast<CClassifyWin *>(_o);
        switch (_id) {
        case 0: _t->signal_SendData((*reinterpret_cast< SDataPack(*)>(_a[1]))); break;
        case 1: _t->slot_clickedCheckBox(); break;
        case 2: _t->slot_openTrainingSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slot_openClassifySet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slot_beginClassify((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slot_beginTraining((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slot_operateFinished((*reinterpret_cast< EOperateFlag(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CClassifyWin::*_t)(SDataPack );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CClassifyWin::signal_SendData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CClassifyWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CClassifyWin.data,
      qt_meta_data_CClassifyWin,  qt_static_metacall, 0, 0}
};


const QMetaObject *CClassifyWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CClassifyWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CClassifyWin.stringdata))
        return static_cast<void*>(const_cast< CClassifyWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int CClassifyWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CClassifyWin::signal_SendData(SDataPack _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
