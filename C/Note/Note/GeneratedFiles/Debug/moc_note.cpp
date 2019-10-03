/****************************************************************************
** Meta object code from reading C++ file 'note.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../note.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'note.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Note_t {
    QByteArrayData data[9];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Note_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Note_t qt_meta_stringdata_Note = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Note"
QT_MOC_LITERAL(1, 5, 11), // "TimeOutSelf"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "SetLedNumber"
QT_MOC_LITERAL(4, 31, 15), // "SetTogetherTime"
QT_MOC_LITERAL(5, 47, 14), // "TrayIconAction"
QT_MOC_LITERAL(6, 62, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(7, 96, 6), // "reason"
QT_MOC_LITERAL(8, 103, 11) // "ClickButton"

    },
    "Note\0TimeOutSelf\0\0SetLedNumber\0"
    "SetTogetherTime\0TrayIconAction\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0ClickButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Note[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void Note::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Note *_t = static_cast<Note *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TimeOutSelf(); break;
        case 1: _t->SetLedNumber(); break;
        case 2: _t->SetTogetherTime(); break;
        case 3: _t->TrayIconAction((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 4: _t->ClickButton(); break;
        default: ;
        }
    }
}

const QMetaObject Note::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Note.data,
      qt_meta_data_Note,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Note::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Note::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Note.stringdata0))
        return static_cast<void*>(const_cast< Note*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Note::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
