#pragma once
#include "version.h"

class OS {
    public: std::string name = "";
    std::vector < Version > versions = {};
    Version longest;
    Version shortest;

    OS(std::string n) {
        this->name = n;
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
            this->versions.push_back(ver);
        }
        sort(versions.begin(), versions.end(), comparerDescending);
        if (!versions.empty()) {
            this->longest = versions.front();
            this->shortest = versions.back();
        }
    }
};