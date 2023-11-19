#include "nvdb_engine.hpp"

#include <QDebug>

namespace nvdb
{
    NVDBEngine::NVDBEngine():
    counter{0},
    current_objs_amount{0},
    type_v{0},
    type_n{std::string()}
    {}

    void NVDBEngine::init(){
        httpHandler_objectTypes.set_endpoint(this->get_endpoint_env() + "vegobjekter.json");

        httpHandler_objectTypes.produce_data();   

        QObject::connect(&httpHandler_objectTypes, &Rest::RestHttpHandler::done, this, &NVDBEngine::load_nvdb_objecttype_fromJson);
        QObject::connect(this, &NVDBEngine::object_types_ready, this, &NVDBEngine::config_fetching);
    }

    void NVDBEngine::load_nvdb_objecttype_fromJson()
    {
        auto data = httpHandler_objectTypes.buffer();

        auto doc = QJsonDocument::fromJson(data);
        
        QJsonArray objects = doc.array();

        for (auto each_one: objects)
        {
            auto object = each_one.toObject();
            
            auto statistics = object["statistikk"].toObject();
            auto amount = statistics["antall"].toInt();

            auto obj_name = object["navn"].toString();
            auto obj_id_type = object["id"].toInt();
            auto obj_href = object["href"].toString();

            RoadObjectType object_type;

            object_type.set_name(obj_name.toStdString());
            object_type.set_type(obj_id_type);
            object_type.set_href(obj_href.toStdString());
            object_type.set_amount(amount);

            road_objects_type.push_back(object_type);
        }

        emit object_types_ready(); //emiting signal when all objecttypes fetch are ready
    }

    void NVDBEngine::config_fetching(){
        
        //setting object type id values
        if (type_v > 0) init_type_v(type_v); // if id type was set
        if (! type_n.empty()) init_type_n(type_n); // if name type was set

        //getting the amount of total objects to fetch
        current_objs_amount = road_objects_type[0].get_amount();

        httpHandler_config.set_endpoint(next_chunck_endpoint);
        httpHandler_config.produce_data();

        //getting endpoint of the next chunk
        QObject::connect(&httpHandler_config, &Rest::RestHttpHandler::done, [&]{
            auto doc = QJsonDocument::fromJson(httpHandler_config.buffer());

            auto object = doc.object();

            auto objects = object["objekter"].toArray();
            auto metadata = object["metadata"].toObject();
            auto next_chunk = metadata["neste"].toObject();

            next_chunck_endpoint = next_chunk["href"].toString().toStdString();

            current_objects_amount_returned = metadata["returnert"].toInt();
            
            httpHandler_config.set_endpoint(next_chunck_endpoint);
            httpHandler_config.produce_data();

            emit next_chunk_is_ready();
        });

        //processing next chunk endpoint to collect nvdb ids and href/urls of nvdbids
        QObject::connect(this, &NVDBEngine::next_chunk_is_ready, [&]{
            auto doc = QJsonDocument::fromJson(httpHandler_config.buffer());

            // qDebug() << next_chunck_endpoint;

            auto object = doc.object();

            auto objects = object["objekter"].toArray();

            for (auto each_obj: objects){
                auto value = each_obj.toObject();

                nvdbids[value["id"].toInt()] = value["href"].toString().toStdString();
                counter++;
            }

            // std::cout << counter << std::endl;
            // std::cout << current_objs_amount << std::endl;

            //if counter == to total object to be fetched, then this will be last chunk
            if (counter >= current_objs_amount) emit last_fetched_object();
        });

        QObject::connect(this, &NVDBEngine::last_fetched_object, [&]{
            httpHandler_config.close();

            emit fetching_ended();
        });

        connect(this, &NVDBEngine::fetching_ended, [&]{
            for (auto& l: nvdbids) std::cout << l.first << ": "<< l.second << std::endl;
        });
    }

    void NVDBEngine::set_object_type(const std::size_t object_type_id){
        type_v = object_type_id;
    }

    void NVDBEngine::set_object_type(const std::string& object_type_name){
        type_n = object_type_name;

    }

    void NVDBEngine::init_type_v(const std::size_t object_type_id){
        for (const auto& type: road_objects_type)
            if (type.get_type() == object_type_id) // getting begining endpoint for first chunk
            next_chunck_endpoint = type.get_href() + ".json";
    }

    void NVDBEngine::init_type_n(const std::string& object_type_name){
        for (const auto& type: road_objects_type)
            if (type.get_name() == object_type_name) // getting begining endpoint for first chunk
            next_chunck_endpoint = type.get_href() + ".json";
    }

    void NVDBEngine::set_env(_env env){ current_env = env; }
    
    std::string NVDBEngine::get_endpoint_env() const {
        switch (current_env)
        {
        case _env::DEV:
            return "https://nvdbapiles-v3.utv.atlas.vegvesen.no/";
            break;
        
        case _env::PROD:
            return "https://nvdbapiles-v3.atlas.vegvesen.no/";
            break;
        
        case _env::TEST:
            return "https://nvdbapiles-v3.test.atlas.vegvesen.no/";
            break;

        default:
            break;
        }
    }
}