cmake_minimum_required(VERSION 3.5)

project(SerializeBoostJson LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_JSON_STANDALONE on)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/boostjson ${CMAKE_CURRENT_BINARY_DIR}/3rdparty/boostjson)

include_directories(../)

add_executable(TestSerializeBoostJson
    main.cpp)

target_link_libraries(TestSerializeBoostJson
    boost_json
    )
