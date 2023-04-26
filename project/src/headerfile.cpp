#include "headerfile.h"

date::year_month_day parse_date(const std::string & date_str) {
    int year;
    unsigned int month, day;
    sscanf(date_str.c_str(), "%d-%d-%d", & year, & month, & day);
    return date::year_month_day {date::year {year}, date::month {month}, date::day {day}};
}

int days_diff(date::year_month_day date1, date::year_month_day date2) {
    auto time1 = date::sys_days {date1};
    auto time2 = date::sys_days {date2};
    auto diff = (time2 - time1).count() + 1; // including end day

    return diff;
}

bool valid_date(const std::string & date_str) {
    unsigned int tmp;
    int output = sscanf(date_str.c_str(), "%d-%d-%d", & tmp, & tmp, & tmp);
    return output == 3;
}

date::year_month_day extractDateFromJson(std::string date_str,json file){
    date::year_month_day date;
    if ((file.contains(date_str))&&(!file[date_str].is_boolean())&&(valid_date(file[date_str])))
        date = parse_date(file[date_str]);
    return date;
}