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

namespace nvdb
{
    enum class _env{PROD, DEV, TEST};

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

            void init();

        private: //private methods
            void config_fetching();
            void load_nvdb_objecttype_fromJson();

              //overloaded methods
            void init_type_v(const std::size_t);
            void init_type_n(const std::string &);

        signals:
            void object_types_ready();
            void next_chunk_is_ready();
            void last_fetched_object();
            void fetching_ended();

        private:
            QJsonDocument document;

            Rest::RestHttpHandler httpHandler_objectTypes;
            Rest::RestHttpHandler httpHandler_config;

            std::vector<nvdb::RoadObjectType> road_objects_type;
            std::map<std::size_t, std::string> nvdbids;

            _env current_env;

            std::string next_chunck_endpoint;
            std::size_t current_objects_amount_returned;
            std::size_t current_objs_amount;

            std::size_t counter;

            std::size_t type_v;
            std::string type_n;
    };
}
#endif