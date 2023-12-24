#include "road_object.hpp"

namespace nvdb
{
    // nvdb::road_object::road_object(){}

    schema_road_obj road_object::operator[](const std::string &key)
    {
        schema_road_obj obj;

        for (const auto& object: properties) if (object.first == key) obj = object.second;

        return obj;
    }

    void road_object::set_nvdbid(const std::size_t nvdb_id){ _nvdbid = nvdb_id; }

    void road_object::set_geometry(const std::string &geom){ _geometry = geom; }

    std::string road_object::geometry() const
    {
        return _geometry;
    }
    std::size_t road_object::nvdbid() const
    {
        return _nvdbid;
    }
}
