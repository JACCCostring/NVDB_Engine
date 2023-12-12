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
            // std::string name;
            std::string property_name;
            std::any value;
        };

    class road_object
    {
    public:
        road_object();
        
        template<typename T>
        void add_property(const std::size_t id, const std::string& name, 
                                            const std::string& property, const T& value){
                
                // code here
                // make sure to cast T<> value to the correspon type, it can be any thing

                schema_road_obj obj;

                obj.id = id;
                // obj.name = name;
                obj.property_name = name;
                obj.value = std::any_cast<decltype(value)>(value); // casting to the type of T

                properties[obj.name] = obj; //adding property to container
        }

    private:
        std::map<std::string, schema_road_obj> properties;
    };
}
#endif