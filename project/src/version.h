#pragma once
#include "headerfile.h"


using json = nlohmann::json;
class Version {
    public: std::string cycle = "";
    date::year_month_day releaseDate;
    date::year_month_day eolDate;
    int diffDays = 0;

    Version() {};

    void load(json version) {
        this->eolDate = extractDateFromJson("eol",version);
        this->releaseDate = extractDateFromJson("releaseDate",version);
        if (eolDate.ok() && releaseDate.ok()) {
            this->diffDays = days_diff(releaseDate, eolDate);
            this->cycle = version["cycle"];
        }
    }
};