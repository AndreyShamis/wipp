/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Oct 17 16:55:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      59,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     134,   11,   11,   11, 0x08,
     159,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_btnScanBSS_clicked()\0"
    "on_btnGetBSS_clicked()\0on_btnP2pFind_clicked()\0"
    "on_btnP2pPeers_clicked()\0"
    "on_btnScanBSS_2_clicked()\0"
    "on_btnModprobe_clicked()\0updateCaption()\0"
    "FastTimer()\0on_btnModprobeR_clicked()\0"
    "on_btnPrintBss_clicked()\0"
    "on_pushButton_clicked()\0ReloadDriver()\0"
    "on_btnReloadDriver_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btnScanBSS_clicked(); break;
        case 1: _t->on_btnGetBSS_clicked(); break;
        case 2: _t->on_btnP2pFind_clicked(); break;
        case 3: _t->on_btnP2pPeers_clicked(); break;
        case 4: _t->on_btnScanBSS_2_clicked(); break;
        case 5: _t->on_btnModprobe_clicked(); break;
        case 6: _t->updateCaption(); break;
        case 7: _t->FastTimer(); break;
        case 8: _t->on_btnModprobeR_clicked(); break;
        case 9: _t->on_btnPrintBss_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->ReloadDriver(); break;
        case 12: _t->on_btnReloadDriver_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
