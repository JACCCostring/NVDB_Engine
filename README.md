<h1>C++ NVDB OOP Library</h1>

This is a easy and oriented object library for fetching road objects fo the Norwegian Road Database (NVDB)

```C++

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
```

Explanation:

```C++
nvdb::NVDBEngine engine;
    
    engine.set_env(nvdb::_env::TEST);

    engine.set_object_type(30);

    engine.init();

    QObject::connect(&engine, &nvdb::NVDBEngine::ready, [&]{
        // do things here ...
        engine.download_road_objects(engine.road_object_total_amount());
        std::cout << "Donwload started!" << std::endl;
    });
```
```
Here the signal ready is captured and then the download start with the call to engine.download_road_objects(),
that received an argument of type std::size_t that is the amount of road objects to fetched, in this case we passed the
total amount of this type of object in this case 30 = veganlegg in NVDB.

Note: that we especified the object type on line 56 and environment as Test environment in line 54.
```


```C++
QObject::connect(&engine, &nvdb::NVDBEngine::done_downloading, [&]{
        auto chunk = engine.chunk();

        std::cout << "done downloading!" << std::endl;

        for (const auto& c: chunk)
            for (const auto& m: c.municipalities())
                if (m == 1106)
                    std::cout << c.nvdbid() << std::endl;
    });
```
```
Here the signal done_downloading is captured and a chunk is gotten from the engine.chunk() method
then it loop through the chunk and then loop through municipalities that is a std::vector<std::size_t>
that contains all municipalities from the current object.

Note: municipalities in NVDB are expresed as id numbers like 1106 for haugesund and 3 for Oslo
```

Restul of all road objects that are located in the municipalicty of Haugesund

![image](https://github.com/JACCCostring/NVDB_Engine/assets/93591202/ece6bfb9-182f-4b27-ad6f-1f023eacf814)

results from vegkart.no with same search criteria
![image](https://github.com/JACCCostring/NVDB_Engine/assets/93591202/341d9eca-8b7b-4852-b4ca-dd4973790cc0)

