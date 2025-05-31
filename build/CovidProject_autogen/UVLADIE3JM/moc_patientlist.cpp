/****************************************************************************
** Meta object code from reading C++ file 'patientlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/patientlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PatientList_t {
    QByteArrayData data[10];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PatientList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PatientList_t qt_meta_stringdata_PatientList = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PatientList"
QT_MOC_LITERAL(1, 12, 22), // "onPatientDoubleClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 48, 6), // "_index"
QT_MOC_LITERAL(5, 55, 27), // "on_addpatientButton_clicked"
QT_MOC_LITERAL(6, 83, 30), // "on_removepatientButton_clicked"
QT_MOC_LITERAL(7, 114, 16), // "addPatientToList"
QT_MOC_LITERAL(8, 131, 8), // "Patient*"
QT_MOC_LITERAL(9, 140, 12) // "_new_patient"

    },
    "PatientList\0onPatientDoubleClicked\0\0"
    "QModelIndex\0_index\0on_addpatientButton_clicked\0"
    "on_removepatientButton_clicked\0"
    "addPatientToList\0Patient*\0_new_patient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PatientList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void PatientList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PatientList *_t = static_cast<PatientList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPatientDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_addpatientButton_clicked(); break;
        case 2: _t->on_removepatientButton_clicked(); break;
        case 3: _t->addPatientToList((*reinterpret_cast< Patient*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PatientList::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_PatientList.data,
    qt_meta_data_PatientList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PatientList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PatientList.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PatientList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
