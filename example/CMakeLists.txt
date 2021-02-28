cmake_minimum_required(VERSION 3.5)

project(SerializeBoostJson LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(..
    ../3rdparty/boostjson/include)

add_compile_definitions(BOOST_JSON_STANDALONE)

add_executable(TestSerializeBoostJson
    ../3rdparty/boostjson/src/src.cpp
    main.cpp)
