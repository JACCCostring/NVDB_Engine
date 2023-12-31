#include <QCoreApplication>

#include "../include/nvdb_engine.hpp"

int main(int argc, char** argv){
    QCoreApplication a(argc, argv);

    nvdb::NVDBEngine engine;
    
    engine.set_env(nvdb::_env::TEST);

    engine.set_object_type(30);

    engine.init();

    QObject::connect(&engine, &nvdb::NVDBEngine::ready, [&]{
        // do things here ...
        engine.download_road_objects(engine.road_object_total_amount());
        std::cout << "Donwload started!" << std::endl;
    });

    QObject::connect(&engine, &nvdb::NVDBEngine::done_downloading, [&]{
        auto chunk = engine.chunk();

        std::cout << "done downloading!" << std::endl;

        for (const auto& c: chunk)
            for (const auto& m: c.municipalities())
                if (m == 1106)
                    std::cout << c.nvdbid() << std::endl;
    });

    QObject::connect(&engine, &nvdb::NVDBEngine::status_download, [&](const std::size_t progress){
        if ((progress % 500 ) == true)
            std::cout << progress << " from " << engine.road_object_total_amount() << " object downloaded ..." << std::endl;
    
    });

    return a.exec();
}