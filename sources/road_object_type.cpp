#include "road_object_type.hpp"

namespace nvdb
{
    // setters
    void RoadObjectType::set_name(const std::string& _name){ object_name = _name; }
    void RoadObjectType::set_type(const std::size_t _type){ object_type = _type; }
    void RoadObjectType::set_href(const std::string& _href){ object_href = _href; }
    void RoadObjectType::set_amount(const std::size_t _amount){ object_amount = _amount; }

    // getters

    std::string RoadObjectType::get_name() const { return object_name; }
    std::size_t RoadObjectType::get_type() const { return object_type; }
    std::string RoadObjectType::get_href() const { return object_href; }
    std::size_t RoadObjectType::get_amount() const { return object_amount; }
}