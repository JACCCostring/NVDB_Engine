#ifndef __NVDB_ENGINE__

#define __NVDB_ENGINE__

#include <QJsonDocument>    //Qt libs
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>   
#include <QObject>

#include <vector>   //std libs
#include <map>

#include "road_object_type.hpp" //user defined libs
#include "rest_http_handler.hpp"
#include "road_object.hpp"

namespace nvdb
{
    enum class _env{PROD, DEV, TEST};

    struct core_next_chunk{
        std::string href;
        std::size_t id;
    };

    class NVDBEngine: public QObject
    {
            Q_OBJECT

        public:
            NVDBEngine();
            
            void set_env(_env env);

            //overloaded methods
            void set_object_type(const std::size_t);
            void set_object_type(const std::string &);

            std::string get_endpoint_env() const;
            std::size_t road_objects_amount() const;
            
            void next(const std::size_t amount = 5);

            void init();

        private: //private methods
            void config_fetching();
            void load_nvdb_objecttype_fromJson();
            void populate_core_chunk_container();
            void parse_nvdb_object_road(const std::string &);
            
            //std::vector<core_next_chunk> core_chunk() const;

              //overloaded private methods
            void init_type_v(const std::size_t);
            void init_type_n(const std::string &);

        signals:
            void object_types_ready();
            void next_chunk_is_ready();
            void last_fetched_object();
            void fetching_ended();
            void done_populating_core_chunk();
            void ready();
            void done_parsing_nvdb_obj();

        private:
            // QJsonDocument document;

            // nvdb::road_object road_objects_core;

            Rest::RestHttpHandler httpHandler_objectTypes;
            Rest::RestHttpHandler httpHandler_config;
            Rest::RestHttpHandler httpHandler_general;
            
            /*
                this container will hold all road objects properties and geometry
            */
            std::vector<nvdb::RoadObjectType> road_objects_type;

            /*
                this container will hold all nvdb ids and href per object but in chunks
                so later in the code we can substract what it need to be substract from, and its easier
            */
            std::vector<core_next_chunk> container_next_chunk;

            /*
                this container will hold all nvdb ids and it's assigned href per object
                so href can be substract using nvdb id.
            */
            std::map<std::size_t, std::string> nvdbids;

            core_next_chunk current_core_chunck;

            _env current_env;

            std::string next_chunck_endpoint;
            std::string next_chunk_endpoint_internal;
            std::size_t current_objects_amount_returned;
            std::size_t current_objs_amount;

            std::size_t counter;
            std::size_t __counter_next;

            std::size_t __next__object_counter_parse;
            std::size_t road_objects_to_fetch;

            std::size_t type_v;
            std::string type_n;
    };
}
#endif