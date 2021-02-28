#ifndef SERIALIZEBOOSTJSON_HPP
#define SERIALIZEBOOSTJSON_HPP

#include <string>
#include <type_traits>
#include <boost/json.hpp>

#define TO_STR(x) #x
// https://stackoverflow.com/a/5134656
#define EXPAND(...) __VA_ARGS__

#define TO_JSON(value) json[TO_STR(value)] = boost::json::value_from(value);

#define TO_VALUE(value) if(json.contains(#value)) { \
                            newClass.value = boost::json::value_to<decltype(value)>(json[#value]); \
                        } else { \
                            newClass.value = decltype(value)(); \
                        } \


#define CONCATENATE(arg1, arg2)   CONCATENATE1(arg1, arg2)
#define CONCATENATE1(arg1, arg2) arg1##_##arg2

#define FOR_EACH_1(what, x, ...) what(x)
#define FOR_EACH_2(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_1(what, __VA_ARGS__))
#define FOR_EACH_3(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_2(what,  __VA_ARGS__))
#define FOR_EACH_4(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_3(what,  __VA_ARGS__))
#define FOR_EACH_5(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_4(what,  __VA_ARGS__))
#define FOR_EACH_6(what, x, ...)\
  what(x);\
  EXPAND(FOR_EACH_5(what,  __VA_ARGS__))
#define FOR_EACH_7(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_6(what,  __VA_ARGS__))
#define FOR_EACH_8(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_7(what,  __VA_ARGS__))
#define FOR_EACH_9(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_8(what,  __VA_ARGS__))
#define FOR_EACH_10(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_9(what,  __VA_ARGS__))
#define FOR_EACH_11(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_10(what,  __VA_ARGS__))
#define FOR_EACH_12(what, x, ...)\
  what(x)\
  EXPAND(FOR_EACH_11(what,  __VA_ARGS__))

// https://stackoverflow.com/a/36015150
#ifdef _MSC_VER // Microsoft compilers
#   define GET_ARG_COUNT(...)  INTERNAL_EXPAND_ARGS_PRIVATE(INTERNAL_ARGS_AUGMENTER(__VA_ARGS__))
#   define INTERNAL_ARGS_AUGMENTER(...) unused, __VA_ARGS__
#   define INTERNAL_EXPAND(x) x
#   define INTERNAL_EXPAND_ARGS_PRIVATE(...) INTERNAL_EXPAND(INTERNAL_GET_ARG_COUNT_PRIVATE(__VA_ARGS__, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#   define INTERNAL_GET_ARG_COUNT_PRIVATE(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count
#else // Non-Microsoft compilers
#   define GET_ARG_COUNT(...) INTERNAL_GET_ARG_COUNT_PRIVATE(0, ## __VA_ARGS__, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#   define INTERNAL_GET_ARG_COUNT_PRIVATE(_0, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count
#endif


#define FOR_EACH_FUN(what, N, ...) EXPAND(CONCATENATE(FOR_EACH, N)(what, __VA_ARGS__))


#define BEGIN_DEFINE_TO_JSON_FUN boost::json::object to_json() { \
    boost::json::object json;

#define END_DEFINE_TO_JSON_FUN return json; }

#define BEGIN_DEFINE_FROM_JSON(ClassName) static ClassName from_json(boost::json::object& json) { \
    ClassName newClass;

#define END_DEFINE_FROM_JSON return newClass; }


#define BEGIN_DEFINE_FROM_JSON_STRING(ClassName) static ClassName from_json(const std::string& jsonStr) { \
    auto jsonVal = boost::json::parse(jsonStr); \
    if(!jsonVal.is_object()) return ClassName(); \
    boost::json::object json = jsonVal.as_object(); \
    ClassName newClass;

#define END_DEFINE_FROM_JSON_STRING return newClass; }


#define SERIALIZE_BOOST_JSON(ClassName, ...) BEGIN_DEFINE_TO_JSON_FUN \
    FOR_EACH_FUN(TO_JSON, GET_ARG_COUNT(__VA_ARGS__), __VA_ARGS__) \
    END_DEFINE_TO_JSON_FUN \
    BEGIN_DEFINE_FROM_JSON(ClassName) \
    FOR_EACH_FUN(TO_VALUE, GET_ARG_COUNT(__VA_ARGS__), __VA_ARGS__) \
    END_DEFINE_FROM_JSON \
    BEGIN_DEFINE_FROM_JSON_STRING(ClassName) \
    FOR_EACH_FUN(TO_VALUE, GET_ARG_COUNT(__VA_ARGS__), __VA_ARGS__) \
    END_DEFINE_FROM_JSON_STRING


#endif // SERIALIZEBOOSTJSON_HPP
