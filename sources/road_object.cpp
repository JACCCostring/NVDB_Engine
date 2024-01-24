#include "road_object.hpp"

namespace nvdb
{
    // nvdb::road_object::road_object(){}

    void road_object::add_property(const std::size_t id, const std::string &property_name, const std::string &value){
        // code here
        // make sure to cast T<> value to the correspon type, it can be any thing

        schema_road_obj obj;

        obj.id = id;
        obj.property_name = property_name;
        obj.value = value; // casting to the type of T
                
        props[obj.property_name] = obj; //adding property to container
    }

    std::map<std::string, schema_road_obj> road_object::properties() const noexcept
    {
        return props;
    }

    // schema_road_obj road_object::operator[](const std::string &key)
    // {
    //     schema_road_obj obj;

    //     for (const auto& object: properties) if (object.first == key) obj = object.second;

    //     return obj;
    // }

    void road_object::set_nvdbid(const std::size_t nvdb_id){ _nvdbid = nvdb_id; }
    void road_object::set_version(const std::size_t &v){ _version = v; }
    void road_object::set_last_modified(const std::string &lm){ _last_modified = lm; }
    void road_object::add_municipality(const std::size_t m){ _municipalities.push_back(m); }
    void road_object::add_county(const std::size_t c){ _counties.push_back(c); }
    void road_object::set_geometry(const std::string &geom) { _geometry = geom; }

    std::string road_object::geometry() const{ return _geometry; }
    std::size_t road_object::nvdbid() const{ return _nvdbid; }
    std::size_t road_object::version() const{ return _version; }
    std::string road_object::last_modified() const{ return _last_modified; }
    road_object::vect_location road_object::municipalities() const { return _municipalities; }
    road_object::vect_location road_object::counties() const{ return _counties; }
}
