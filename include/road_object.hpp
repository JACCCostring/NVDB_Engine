#ifndef __ROAD_OBJECT__

#define __ROAD_OBJECT__

#include <string>
#include <utility>
#include <vector>
#include <map>

namespace nvdb
{
        struct schema_road_obj{
            std::size_t id;
            std::string property_name;
            std::string value;
        };

    class road_object
    {
    public:
        using vect_location = std::vector<std::size_t>;

        road_object() = default;
        
        void add_property(const std::size_t , const std::string&, const std::string&);

        std::map<std::string, schema_road_obj> properties() const noexcept;

        // schema_road_obj operator[] (const std::string &);
        
        void set_geometry(const std::string &);
        void set_nvdbid(const std::size_t);
        void set_version(const std::size_t &);
        void set_last_modified(const std::string &);
        void add_municipality(const std::size_t);
        void add_county(const std::size_t);

        std::string geometry() const;
        std::size_t nvdbid() const;
        std::size_t version() const;
        std::string last_modified() const;
        vect_location municipalities() const ;
        vect_location counties() const;

    private:
        std::map<std::string, schema_road_obj> props;
        std::vector<std::size_t> _municipalities;
        std::vector<std::size_t> _counties;

        std::string _geometry;
        std::size_t _version;
        std::string _last_modified;
        std::size_t _nvdbid;
    };
}
#endif