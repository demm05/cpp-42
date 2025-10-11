#include "TimeStamp.hpp"
#include "primitive.hpp"
#include "string.hpp"
#include <cstring>

time_t TimeStamp::get(std::string const &time, char sep) {
    struct tm dt = parse(time, sep);
    struct tm copy = dt;
    time_t t = mktime(&dt);
    if (t == -1 || dt.tm_year != copy.tm_year || dt.tm_mon != copy.tm_mon ||
        dt.tm_mday != copy.tm_mday) {
        std::runtime_error("Invalid date: '" + time + "'");
    }
    return mktime(&dt);
}

tm TimeStamp::parse(std::string const &time, char sep) {
    struct tm dt;
    std::memset(&dt, 0, sizeof(dt));
    dt.tm_isdst = -1;
    std::istringstream ss(time);
    std::string year, month, day;
    if (!std::getline(ss, year, sep) || !std::getline(ss, month, sep) ||
        !std::getline(ss, day, sep))
        throw std::runtime_error("Invalid time: '" + time + "'");
    dt.tm_year = checkYear(year) - 1900;
    dt.tm_mon = checkMonth(month) - 1;
    dt.tm_mday = checkDay(day);
    return dt;
}

int TimeStamp::checkYear(std::string const &s) {
    if (!isAllDigit(s))
        throw std::runtime_error("Invalid year: '" + s + "'");
    int res = fromString<int>(s);
    if (res < 1900)
        throw std::runtime_error("Invalid year: '" + s + "'");
    return res;
}

int TimeStamp::checkMonth(std::string const &s) {
    if (!isAllDigit(s))
        throw std::runtime_error("Invalid month: '" + s + "'");
    int res = fromString<int>(s);
    if (res > 12 || res < 1)
        throw std::runtime_error("Invalid month: '" + s + "'");
    return res;
}

int TimeStamp::checkDay(std::string const &s) {
    if (!isAllDigit(s))
        throw std::runtime_error("Invalid day: '" + s + "'");
    int res = fromString<int>(s);
    if (res > 31 || res < 1)
        throw std::runtime_error("Invalid day: '" + s + "'");
    return res;
}
