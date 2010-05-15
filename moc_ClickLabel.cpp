/****************************************************************************
** Meta object code from reading C++ file 'ClickLabel.h'
**
** Created: Mon May 10 15:32:05 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ClickLabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClickLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClickLabel[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      22,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClickLabel[] = {
    "ClickLabel\0\0clicked()\0slotClicked()\0"
};

const QMetaObject ClickLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_ClickLabel,
      qt_meta_data_ClickLabel, 0 }
};

const QMetaObject *ClickLabel::metaObject() const
{
    return &staticMetaObject;
}

void *ClickLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClickLabel))
        return static_cast<void*>(const_cast< ClickLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int ClickLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: slotClicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ClickLabel::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
