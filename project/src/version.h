#pragma once
#include "headerfile.h"


using json = nlohmann::json;
class Version {
    public: std::string cycle = "";
    std::string releaseDate = "";
    std::string eol = "";
    int diffDays = 0;

    Version() {};

    bool check_load() {
        if ((cycle == "") || (releaseDate == "")) return false;
        return true;
    }

    void load(json version) {
        // added this condition because some OS had "eol": false (data.json 508)
        if (!version.contains("eol") || version["eol"].is_boolean()) return; 
       
        std::string eol = version["eol"];

        if (!valid_date(eol)) return; // condition for invalid date

        date::year_month_day eolDate = parse_date(eol);
        date::year_month_day releaseDateFormat;

        if ((version.contains("releaseDate"))&&(valid_date(version["releaseDate"])))
            releaseDate = version["releaseDate"];
        else if ((version.contains("releasedDate"))&&(valid_date(version["releasedDate"])))
            releaseDate = version["releasedDate"];
            // added this condition because some OS had "releasedDate" instead of "releaseDate" (data1.json 22113) 
        releaseDateFormat = parse_date(releaseDate);
        if (releaseDateFormat.ok() && eolDate.ok()) {
            int diff = days_diff(releaseDateFormat, eolDate);
            cycle = version["cycle"];
            diffDays = diff;
        }
    }
};
