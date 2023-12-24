#include <QCoreApplication>

#include "../include/nvdb_engine.hpp"

int main(int argc, char** argv){
    QCoreApplication a(argc, argv);

    nvdb::NVDBEngine engine;
    
    engine.set_env(nvdb::_env::TEST);

    engine.set_object_type(3);

    engine.init();

    QObject::connect(&engine, &nvdb::NVDBEngine::ready, [&]{
        // do things here ...
        engine.next(2);
        // engine.next();
        // engine.next();
        // engine.next();
    });

    return a.exec();
}