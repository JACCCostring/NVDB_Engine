#ifndef __ROAD_OBJECT__

#define __ROAD_OBJECT__

#include <any>
#include <map>
#include <string>
#include <utility>

namespace nvdb
{
        struct schema_road_obj{
            std::size_t id;
            std::string property_name;
            std::any value;
        };

    class road_object
    {
    public:
        road_object() = default;
        
        template<typename T>
        void add_property(const std::size_t id, const std::string& property_name, const T& value){
                
                // code here
                // make sure to cast T<> value to the correspon type, it can be any thing

                schema_road_obj obj;

                obj.id = id;
                obj.property_name = property_name;
                obj.value = std::any_cast<decltype(value)>(value); // casting to the type of T

                properties[obj.property_name] = obj; //adding property to container
        }

        schema_road_obj operator[] (const std::string &);
        
        void set_nvdbid(const std::size_t);
        void set_geometry(const std::string &);
        std::string geometry() const;
        std::size_t nvdbid() const;

    private:
        std::map<std::string, schema_road_obj> properties;
        
        std::string _geometry;
        std::size_t _nvdbid;
    };
}
#endif