/****************************************************************************
** Meta object code from reading C++ file 'nvdb_engine.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/nvdb_engine.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nvdb_engine.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS = QtMocHelpers::stringData(
    "nvdb::NVDBEngine",
    "object_types_ready",
    "",
    "next_chunk_is_ready",
    "last_fetched_object",
    "fetching_ended",
    "done_populating_core_chunk",
    "ready",
    "done_parsing_nvdb_obj"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[17];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[20];
    char stringdata5[15];
    char stringdata6[27];
    char stringdata7[6];
    char stringdata8[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS_t qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "nvdb::NVDBEngine"
        QT_MOC_LITERAL(17, 18),  // "object_types_ready"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 19),  // "next_chunk_is_ready"
        QT_MOC_LITERAL(57, 19),  // "last_fetched_object"
        QT_MOC_LITERAL(77, 14),  // "fetching_ended"
        QT_MOC_LITERAL(92, 26),  // "done_populating_core_chunk"
        QT_MOC_LITERAL(119, 5),  // "ready"
        QT_MOC_LITERAL(125, 21)   // "done_parsing_nvdb_obj"
    },
    "nvdb::NVDBEngine",
    "object_types_ready",
    "",
    "next_chunk_is_ready",
    "last_fetched_object",
    "fetching_ended",
    "done_populating_core_chunk",
    "ready",
    "done_parsing_nvdb_obj"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSnvdbSCOPENVDBEngineENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    0,   58,    2, 0x06,    3 /* Public */,
       5,    0,   59,    2, 0x06,    4 /* Public */,
       6,    0,   60,    2, 0x06,    5 /* Public */,
       7,    0,   61,    2, 0x06,    6 /* Public */,
       8,    0,   62,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject nvdb::NVDBEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSnvdbSCOPENVDBEngineENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NVDBEngine, std::true_type>,
        // method 'object_types_ready'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'next_chunk_is_ready'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'last_fetched_object'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fetching_ended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'done_populating_core_chunk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ready'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'done_parsing_nvdb_obj'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void nvdb::NVDBEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NVDBEngine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->object_types_ready(); break;
        case 1: _t->next_chunk_is_ready(); break;
        case 2: _t->last_fetched_object(); break;
        case 3: _t->fetching_ended(); break;
        case 4: _t->done_populating_core_chunk(); break;
        case 5: _t->ready(); break;
        case 6: _t->done_parsing_nvdb_obj(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::object_types_ready; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::next_chunk_is_ready; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::last_fetched_object; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::fetching_ended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::done_populating_core_chunk; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::ready; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NVDBEngine::*)();
            if (_t _q_method = &NVDBEngine::done_parsing_nvdb_obj; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *nvdb::NVDBEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nvdb::NVDBEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSnvdbSCOPENVDBEngineENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int nvdb::NVDBEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void nvdb::NVDBEngine::object_types_ready()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void nvdb::NVDBEngine::next_chunk_is_ready()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void nvdb::NVDBEngine::last_fetched_object()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void nvdb::NVDBEngine::fetching_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void nvdb::NVDBEngine::done_populating_core_chunk()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void nvdb::NVDBEngine::ready()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void nvdb::NVDBEngine::done_parsing_nvdb_obj()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
