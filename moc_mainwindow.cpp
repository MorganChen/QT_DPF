/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon May 17 23:13:53 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      26,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      53,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     266,   11,   11,   11, 0x08,
     290,   11,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     365,  360,   11,   11, 0x08,
     415,   11,   11,   11, 0x08,
     441,   11,   11,   11, 0x08,
     474,  468,   11,   11, 0x08,
     493,   11,   11,   11, 0x08,
     504,   11,   11,   11, 0x08,
     526,   11,   11,   11, 0x08,
     550,   11,   11,   11, 0x08,
     573,   11,   11,   11, 0x08,
     598,   11,   11,   11, 0x08,
     618,   11,   11,   11, 0x08,
     640,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0ThreadStart()\0ThreadPause()\0"
    "ThreadStop()\0on_Btn_Movie_clicked()\0"
    "on_Btn_Music_clicked()\0on_Btn_MemCard_clicked()\0"
    "on_Btn_MemStk_clicked()\0on_Btn_Picasa_clicked()\0"
    "on_Btn_Alarm_clicked()\0on_Btn_Cal_clicked()\0"
    "on_Btn_PhotoFull_clicked()\0"
    "on_Btn_InMem_clicked()\0on_Btn_ZoomIn_clicked()\0"
    "on_Btn_PhotoSinglePage_L_clicked()\0"
    "on_Btn_PhotoSinglePage_R_clicked()\0"
    "item\0on_listWidget_Photo_itemClicked(QListWidgetItem*)\0"
    "on_Btn_PageLeft_clicked()\0"
    "on_Btn_PageRight_clicked()\0index\0"
    "setItemInList(int)\0finished()\0"
    "on_Btn_Home_clicked()\0on_Btn_PageUp_clicked()\0"
    "on_Btn_Photo_clicked()\0on_Btn_Setting_clicked()\0"
    "on_Btn_Ok_clicked()\0on_Btn_Test_clicked()\0"
    "ShowDigiClock()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ThreadStart(); break;
        case 1: ThreadPause(); break;
        case 2: ThreadStop(); break;
        case 3: on_Btn_Movie_clicked(); break;
        case 4: on_Btn_Music_clicked(); break;
        case 5: on_Btn_MemCard_clicked(); break;
        case 6: on_Btn_MemStk_clicked(); break;
        case 7: on_Btn_Picasa_clicked(); break;
        case 8: on_Btn_Alarm_clicked(); break;
        case 9: on_Btn_Cal_clicked(); break;
        case 10: on_Btn_PhotoFull_clicked(); break;
        case 11: on_Btn_InMem_clicked(); break;
        case 12: on_Btn_ZoomIn_clicked(); break;
        case 13: on_Btn_PhotoSinglePage_L_clicked(); break;
        case 14: on_Btn_PhotoSinglePage_R_clicked(); break;
        case 15: on_listWidget_Photo_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 16: on_Btn_PageLeft_clicked(); break;
        case 17: on_Btn_PageRight_clicked(); break;
        case 18: setItemInList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: finished(); break;
        case 20: on_Btn_Home_clicked(); break;
        case 21: on_Btn_PageUp_clicked(); break;
        case 22: on_Btn_Photo_clicked(); break;
        case 23: on_Btn_Setting_clicked(); break;
        case 24: on_Btn_Ok_clicked(); break;
        case 25: on_Btn_Test_clicked(); break;
        case 26: ShowDigiClock(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
