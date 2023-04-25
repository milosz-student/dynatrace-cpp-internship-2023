#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <date/date.h>
#include <nlohmann/json.hpp>
#include "internship.h"
#include "storeos.h"

using json = nlohmann::json;
using namespace date;

namespace internship {
    void task(const std::string & jsonFileName, int elementsCount) {
        std::ifstream f(jsonFileName);
        json data = json::parse(f);

        OSStore store;
        store.load(data); //loading data into OSStore
        store.sortDescending();
        store.print(elementsCount);
    }

    // do not remove this function
    void solution(const std::string & jsonFileName, int elementsCount) {
        task(jsonFileName, elementsCount);
        // put the call to your solution here
    }
}