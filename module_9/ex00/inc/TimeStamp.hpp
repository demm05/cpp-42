#pragma once

#include <string>
#include <sys/types.h>

class TimeStamp {
public:
    static time_t get(std::string const &time, char sep);

private:
    static tm parse(std::string const &time, char sep);
    static int checkYear(std::string const &s);
    static int checkMonth(std::string const &s);
    static int checkDay(std::string const &s);
};
