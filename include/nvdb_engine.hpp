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
            using vector_chunk = std::vector<nvdb::road_object>;

            NVDBEngine();

            //overloaded methods
            void download_road_objects(const std::size_t amount = 5);
            void set_object_type(const std::size_t);
            void set_object_type(const std::string &);

            std::string get_endpoint_env() const;
            std::size_t road_object_total_amount() const;
            
            void set_env(_env env);
            vector_chunk chunk() const noexcept;
            void init();

        private: //private methods
            std::size_t convert_type_name_to_value(const std::string &);
            void parse_nvdb_object_road(const std::string &);
            void load_nvdb_objecttype_fromJson();
            void populate_core_chunk_container();
            void config_fetching();
            std::size_t find_object_type_index(std::size_t);
            
            //std::vector<core_next_chunk> core_chunk() const;

              //overloaded private methods
            bool init_type_n(const std::string &);
            bool init_type_v(const std::size_t);

        signals:
            void status_download(const std::size_t);
            void done_populating_core_chunk();
            void done_parsing_nvdb_obj();
            void next_chunk_is_ready();
            void last_fetched_object();
            void object_types_ready();
            void done_downloading();
            void fetching_ended();
            void ready();

        private:
            Rest::RestHttpHandler httpHandler_objectTypes; // only for object types
            Rest::RestHttpHandler httpHandler_config; // only for configuration, before start fetching
            Rest::RestHttpHandler httpHandler_general; // only for road objects parsing
            
            //this container will hold all road objects name, id type and nvdbid
            std::vector<nvdb::RoadObjectType> road_objects_type;

            /*
                this container will contain all the road objects parsed,
                with it's geometry, nvdbid and properties, for later uses
            */
            vector_chunk _chunk_nvdb_object_;
            
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

            _env current_env;

            std::string next_chunck_endpoint;
            std::string next_chunk_endpoint_internal;
            std::size_t amount_returned;
            std::size_t total_objects;

            std::size_t counter;
            std::size_t __counter_next;

            std::size_t __next__object_counter_parse;
            std::size_t road_objects_to_fetch;

            std::size_t type_v;
            std::string type_n;
    };
}
#endif