#include <string>
// #include <iostream>

namespace nvdb
{
    class RoadObjectType
    {
        public:

            RoadObjectType() = default;

            void set_name(const std::string &);
            void set_type(const std::size_t);
            void set_href(const std::string &);
            void set_amount(const std::size_t);

            std::string get_name() const;
            std::size_t get_type() const;
            std::string get_href() const;
            std::size_t get_amount() const;

        private:
            std::string object_name;
            std::size_t object_type;
            std::string object_href;
            std::size_t object_amount;
    };
}