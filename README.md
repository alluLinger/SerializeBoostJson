# SerializeBoostJson

A simple serialize/deserialize macro tool for boost::json

## Usage

```
#include <iostream>
#include <SerializeBoostJson.hpp>
#include <boost/json.hpp>

struct TestStruct {
    std::string strVal;
    int intVal;
    unsigned int uintVal;
    double doubleVal;
    float floatVal;

    std::vector<int> intVec;

    SERIALIZE_BOOST_JSON(TestStruct, strVal,
                         intVal, uintVal,
                         doubleVal, floatVal, intVec);

    TestStruct() = default;
};

int main()
{
    TestStruct testStruct;
    testStruct.strVal = "Hello Json";
    testStruct.intVal = -1;
    testStruct.uintVal = 0;
    testStruct.doubleVal = 1.1;
    testStruct.floatVal = 1.0;
    std::cout << testStruct.to_json();

    boost::json::object json;
    json["strVal"] = "hello";
    json["intVal"] = -1;
    json["uintVal"] = 0;
    json["doubleVal"] = 1.0;
    json["floatVal"] = 1.1;
    boost::json::array arr;
    for(int i = 0; i < 10; ++i) {
        arr.push_back(boost::json::value(i));
    }
    json["intVec"] = arr;

    TestStruct testFromStruct = TestStruct::from_json(json);
    std::cout << testFromStruct.to_json();

    return 0;
}

```

## Notice
No type check, just boost::json::value_to && value_from, it will cast execption.
