#include <QCoreApplication>

#include "../include/nvdb_engine.hpp"

int main(int argc, char** argv){
    QCoreApplication a(argc, argv);

    nvdb::NVDBEngine engine;
    
    engine.set_env(nvdb::_env::TEST);

    engine.set_object_type(3);

    engine.init();

    QObject::connect(&engine, &nvdb::NVDBEngine::ready, [&]{
        for (auto c: engine.core_chunk()) 
            if (c.id == 83730093)
                engine.next(c.href);
    });

    return a.exec();
}