#include <string>
#include <vector>
#include <iostream>
#include <date/date.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <fstream>

using json = nlohmann::json;


bool valid_date(const std::string & date_str);

int days_diff(date::year_month_day date1, date::year_month_day date2);

date::year_month_day parse_date(const std::string & date_str);

date::year_month_day extractDateFromJson(std::string date_str,json file);