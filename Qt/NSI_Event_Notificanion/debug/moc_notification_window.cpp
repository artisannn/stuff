/****************************************************************************
** Meta object code from reading C++ file 'notification_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notification_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notification_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Notification_window_t {
    QByteArrayData data[17];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notification_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notification_window_t qt_meta_stringdata_Notification_window = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Notification_window"
QT_MOC_LITERAL(1, 20, 21), // "add_ntbx_by_btn_click"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 18), // "open_settings_form"
QT_MOC_LITERAL(4, 62, 17), // "refresh_ntfs_list"
QT_MOC_LITERAL(5, 80, 7), // "hide_me"
QT_MOC_LITERAL(6, 88, 7), // "show_me"
QT_MOC_LITERAL(7, 96, 14), // "close_this_app"
QT_MOC_LITERAL(8, 111, 13), // "iconActivated"
QT_MOC_LITERAL(9, 125, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(10, 159, 6), // "reason"
QT_MOC_LITERAL(11, 166, 11), // "remove_item"
QT_MOC_LITERAL(12, 178, 17), // "Notification_Box*"
QT_MOC_LITERAL(13, 196, 8), // "add_item"
QT_MOC_LITERAL(14, 205, 11), // "new_item_id"
QT_MOC_LITERAL(15, 217, 19), // "open_event_doc_form"
QT_MOC_LITERAL(16, 237, 4) // "ntbx"

    },
    "Notification_window\0add_ntbx_by_btn_click\0"
    "\0open_settings_form\0refresh_ntfs_list\0"
    "hide_me\0show_me\0close_this_app\0"
    "iconActivated\0QSystemTrayIcon::ActivationReason\0"
    "reason\0remove_item\0Notification_Box*\0"
    "add_item\0new_item_id\0open_event_doc_form\0"
    "ntbx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notification_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      15,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void, 0x80000000 | 12,   16,

 // enums: name, flags, count, data

 // enum data: key, value

       0        // eod
};

void Notification_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notification_window *_t = static_cast<Notification_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_ntbx_by_btn_click(); break;
        case 1: _t->open_settings_form(); break;
        case 2: _t->refresh_ntfs_list(); break;
        case 3: _t->hide_me(); break;
        case 4: _t->show_me(); break;
        case 5: _t->close_this_app(); break;
        case 6: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 7: _t->remove_item((*reinterpret_cast< Notification_Box*(*)>(_a[1]))); break;
        case 8: _t->add_item((*reinterpret_cast< long long(*)>(_a[1]))); break;
        case 9: _t->open_event_doc_form((*reinterpret_cast< Notification_Box*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Notification_Box* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Notification_Box* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Notification_window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Notification_window.data,
      qt_meta_data_Notification_window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Notification_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notification_window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Notification_window.stringdata0))
        return static_cast<void*>(const_cast< Notification_window*>(this));
    return QWidget::qt_metacast(_clname);
}

int Notification_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
struct qt_meta_stringdata_New_ntfns_monitor_t {
    QByteArrayData data[4];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_New_ntfns_monitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_New_ntfns_monitor_t qt_meta_stringdata_New_ntfns_monitor = {
    {
QT_MOC_LITERAL(0, 0, 17), // "New_ntfns_monitor"
QT_MOC_LITERAL(1, 18, 16), // "new_notification"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7) // "process"

    },
    "New_ntfns_monitor\0new_notification\0\0"
    "process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_New_ntfns_monitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void New_ntfns_monitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        New_ntfns_monitor *_t = static_cast<New_ntfns_monitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->new_notification((*reinterpret_cast< long long(*)>(_a[1]))); break;
        case 1: _t->process(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (New_ntfns_monitor::*_t)(long long );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&New_ntfns_monitor::new_notification)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject New_ntfns_monitor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_New_ntfns_monitor.data,
      qt_meta_data_New_ntfns_monitor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *New_ntfns_monitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *New_ntfns_monitor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_New_ntfns_monitor.stringdata0))
        return static_cast<void*>(const_cast< New_ntfns_monitor*>(this));
    return QObject::qt_metacast(_clname);
}

int New_ntfns_monitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void New_ntfns_monitor::new_notification(long long _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
