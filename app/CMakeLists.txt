set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_library(nvdb STATIC ../sources/nvdb_engine.cpp ../sources/road_object_type.cpp ../sources/rest_http_handler.cpp)
target_include_directories(nvdb PUBLIC "../include")

find_package(Qt6 CONFIG REQUIRED COMPONENTS core)
find_package(Qt6 CONFIG REQUIRED COMPONENTS network)

target_link_libraries(nvdb Qt6::Core)
target_link_libraries(nvdb Qt6::Network)

add_executable(example_cpp main.cpp "../include/rest_http_handler.hpp" "../include/nvdb_engine.hpp")
# add_executable(example_cpp main.cpp "../include/nvdb_engine.hpp")

# target_link_libraries(example_cpp http nvdb)
target_link_libraries(example_cpp nvdb)