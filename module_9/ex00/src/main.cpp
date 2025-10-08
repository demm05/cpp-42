#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/types.h>

bool isAllDigit(std::string const &s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!::isdigit(*it))
            return false;
    }
    return true;
}

template <typename T> T fromString(std::string const &str) {
    std::istringstream ss(str);
    T ret;
    ss >> ret;
    return ret;
}

class TimeStamp {
public:
    static time_t get(std::string const &time) {
        struct tm datetime = parse(time);
        return mktime(&datetime);
    }

private:
    static tm parse(std::string const &time) {
        struct tm dt;
        std::memset(&dt, 0, sizeof(dt));
        std::istringstream ss(time);
        std::string year, month, day;
        if (!std::getline(ss, year, '-') || !std::getline(ss, month, '-') ||
            !std::getline(ss, day, '-'))
            throw std::runtime_error("Invalid time: '" + time + "'");
        dt.tm_year = checkYear(year);
        dt.tm_mon = checkMonth(month);
        dt.tm_mday = checkDay(day);
        return dt;
    }

    static int checkYear(std::string const &s) {
        if (!isAllDigit(s))
            throw std::runtime_error("Invalid year: '" + s + "'");
        return fromString<int>(s);
    }

    static int checkMonth(std::string const &s) {
        if (!isAllDigit(s))
            throw std::runtime_error("Invalid month: '" + s + "'");
        int res = fromString<int>(s);
        if (res > 12 || res < 1)
            throw std::runtime_error("Invalid month: '" + s + "'");
        return res;
    }

    static int checkDay(std::string const &s) {
        if (!isAllDigit(s))
            throw std::runtime_error("Invalid day: '" + s + "'");
        int res = fromString<int>(s);
        if (res > 31 || res < 1)
            throw std::runtime_error("Invalid day: '" + s + "'");
        return res;
    }
};

int main(int argc, char **argv) {
    (void)argc;
    std::cout << TimeStamp::get(argv[1]) << std::endl;
}
