#pragma once
#include "os.h"

using json = nlohmann::json;

class OSStore {
    public: std::vector < OS > listOS = {};

    static bool comparerOSAscending(const OS & a, const OS & b) {
        return a.longest.diffDays < b.longest.diffDays;
    }
    static bool comparerOSDescending(const OS & a, const OS & b) {
        return a.longest.diffDays > b.longest.diffDays;
    }

    void load(json data) {
        for (const auto & [id, product]: data.items()) {
            if (!product["os"]) continue;

            OS os = OS(product["name"]);
            os.load(product["versions"]);
            listOS.push_back(os);
        }

    }
    void sortAscending() {
        std::sort(listOS.begin(), listOS.end(), comparerOSAscending);
    }
    void sortDescending() {
        std::sort(listOS.begin(), listOS.end(), comparerOSDescending);
    }

    void print(int elementsCount) {
        int i = 0;
        for (OS os: listOS) {
            os.print();
            i++;
            if (i == elementsCount) break;
        }
    }

};