#include "nvdb_engine.hpp"

#include <QDebug>

namespace nvdb
{
    NVDBEngine::NVDBEngine():
    counter{0},
    current_objs_amount{0},
    type_v{0},
    type_n{std::string()},
    __counter_next{0},
    __next__object_counter_parse{0},
    road_objects_to_fetch{0}
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
        // all object contain the amount to fetch
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

            current_objects_amount_returned = metadata["returnert"].toInt(); //not in used yet
            
            httpHandler_config.set_endpoint(next_chunck_endpoint);
            httpHandler_config.produce_data();

            emit next_chunk_is_ready();
        });

        //processing next chunk endpoint to collect nvdb ids and href/urls of nvdbids
        QObject::connect(this, &NVDBEngine::next_chunk_is_ready, [&]{
            auto doc = QJsonDocument::fromJson(httpHandler_config.buffer());

            auto object = doc.object();

            auto objects = object["objekter"].toArray();

            for (auto each_obj: objects){
                auto value = each_obj.toObject();

                nvdbids[value["id"].toInt()] = value["href"].toString().toStdString();
                counter++;
            }

            //if counter == to total object to be fetched, then this will be last chunk
            if (counter >= current_objs_amount) emit last_fetched_object();
        });

        QObject::connect(this, &NVDBEngine::last_fetched_object, [&]{
            httpHandler_config.close();

            emit fetching_ended();
        });

        connect(this, &NVDBEngine::fetching_ended, [&]{ populate_core_chunk_container(); }); //it could be a slot instead a lambda call
        connect(this, &NVDBEngine::done_populating_core_chunk, [&]{ emit ready(); });
    }

    void NVDBEngine::populate_core_chunk_container(){
        //if __counter <= nvdbids container then continue getting next
        if (__counter_next <= nvdbids.size()){
            //if nvdbids container has data then continue, it's valid
            if (nvdbids.size() > 0){
                for (const auto [id, href]: nvdbids){
                    core_next_chunk chunk;

                    chunk.id = id;
                    chunk.href = href;

                    container_next_chunk.push_back(chunk);

                    __counter_next++; //must be watched, dont know where to use it yet
                }

                emit done_populating_core_chunk();
            }
        }
    }

    void NVDBEngine::parse_nvdb_object_road(const std::string& href){
        // 1 get json of any road object already in container
        httpHandler_general.set_endpoint(href);
        httpHandler_general.produce_data();

        // connecting signals
        QObject::connect(&httpHandler_general, &Rest::RestHttpHandler::done, [&]{
            /*
                this metjod will parse especific properties and geometry
                of all or some of the road objects
            */

            QJsonDocument doc = QJsonDocument::fromJson(httpHandler_general.buffer());

            // object that will be returned 
            nvdb::road_object road_object;

            QJsonObject object = doc.object();

            auto geometry = object["geometri"].toObject(); //getting geometry of road object
            auto properties = object["egenskaper"].toArray(); //getting properties of the road object
            auto location = object["lokasjon"].toObject(); //getting location of road object
            
            // from here we know geometri has srid and wkt
            // that is very important for us

            // but as well we want road objects properties
            
            // qDebug() << geometry["srid"];
            // qDebug() << geometry["wkt"];
            // qDebug() << properties;

            road_object.set_nvdbid(container_next_chunk[__next__object_counter_parse].id);
            road_object.set_geometry(geometry["wkt"].toString().toStdString());

            for (const auto& c: properties){
                auto obj = c.toObject(); //inside egenskaper array json object

                /*
                    fix when parsing lista, text, geometri and different
                    type of data from API, to cover more cases, for road objects properties
                */

                if (obj["datatype"] == "Liste"){ //if datatype it's a list then,
                    auto object_array = obj["innhold"].toArray();

                    for (const auto& json_obj: object_array){
                        auto val = json_obj.toObject();

                        auto id = val["id"].toInt();
                        auto name = val["navn"].toString().toStdString();
                        auto value = val["verdi"].toString().toStdString();

                         // add it as a road onject property
                         road_object.add_property(id, name, value);
                    }
                }

                // if not Liste and it's Text for now, then
                if (obj["datatype"] == "FlerverdiAttributt, Tekst"){
                    auto id = obj["id"].toInt();
                    auto name = obj["navn"].toString().toStdString();
                    auto value = obj["verdi"].toString().toStdString();

                    // add it as a road onject property
                    road_object.add_property(id, name, value);
                }
            }

            // object is ready

            std::cout << road_object.nvdbid() << std::endl;

            /*
                the solution will be to iterate throug the rest of
                container next chunk vector, but excluding the first one in index 0
            */

            auto next_href = container_next_chunk[__next__object_counter_parse].href;

            httpHandler_general.set_endpoint(next_href);
            httpHandler_general.produce_data();
            
            // if __next__object_counter_parse >= container_next_chunk then
            // emit a signal that is finished fetching
            if (__next__object_counter_parse >= container_next_chunk.size()) emit done_parsing_nvdb_obj();

            /*
                case when a range of road objects is especified to fetch, from user
                if __next__object_counter_parser == road_objects_to_fetch, then stop fetching
            */

           if (__next__object_counter_parse == road_objects_to_fetch - 1) emit done_parsing_nvdb_obj();

            __next__object_counter_parse++;
        });
        // end of lambda

        //connecting done parsing nvdb objects signal
        QObject::connect(this, &nvdb::NVDBEngine::done_parsing_nvdb_obj, [&]{ httpHandler_general.close(); });
    }

    // std::vector<core_next_chunk> NVDBEngine::core_chunk() const { return container_next_chunk; }

   void NVDBEngine::next(const std::size_t amount){
        /*
            next method will go throug all fetched road objects,
            parse it and return the current parsed road object.

            private method need to be call and this method will return
            a concrete road object with properties and geometry.

            private method: this->parse_nvdb_object_road(const std::string &)
        */

            road_objects_to_fetch = amount; //assigning amount of road objects

            //substract the first object
            auto obj = container_next_chunk[0];

            // calling private method and giving href of each road obj as argument
            this->parse_nvdb_object_road(obj.href);

    //    return {};
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

    std::size_t NVDBEngine::road_objects_amount() const { return nvdbids.size(); }

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