#pragma once
#include "version.h"

class OS {
    public: std::string name = "";
    std::vector < Version > Versions = {};
    Version longest;
    Version shortest;

    OS(std::string n) {
        name = n;
    }

    void print() {
        std::cout << name << " " << longest.cycle << " " << longest.diffDays << std::endl;
    }
    static bool comparerAscending(const Version & a, const Version & b) {
        return a.diffDays < b.diffDays;
    }
    static bool comparerDescending(const Version & a, const Version & b) {
        return a.diffDays > b.diffDays;
    }
    void load(json product) {
        for (const auto & version: product) {
            Version ver = Version();
            ver.load(version);
            if (ver.check_load()) {
                Versions.push_back(ver);
            }
        }
        sort(Versions.begin(), Versions.end(), comparerDescending);
        if (!Versions.empty()) {
            longest = Versions.front();
            shortest = Versions.back();
        }
    }
};