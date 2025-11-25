#include "CSV.hpp"
#include "TimeStamp.hpp"
#include "string.hpp"
#include "types.hpp"
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

CSV::CSV(ssize_t maxValue) : linePos_(1), maxValue_(maxValue) {}

void CSV::processHeader(std::ifstream &file) {
    if (!std::getline(file, line_) || line_.empty())
        throw std::runtime_error("Invalid header: " + line_);
    size_t npos = line_.find(',');
    if (npos != std::string::npos) {
        sep_ = ',';
    } else if ((npos = line_.find('|')) != std::string::npos) {
        sep_ = '|';
    } else {
        throw std::runtime_error("Could not find seperator in header.");
    }
    if (npos != line_.rfind(sep_))
        throw std::runtime_error("Invalid number of separators expected 1.");
}

LineProperties CSV::processLine() {
    LineProperties prop;

    if (line_.empty()) {
        return prop;
    }
    size_t npos = line_.find(sep_);
    if (npos == std::string::npos || npos != line_.rfind(sep_)) {
        std::cerr << "On line(" << linePos_ << ") '" << line_
                  << "' invalid seperator(s)." << std::endl;
        return prop;
    }
    std::string stime = trim(line_.substr(0, npos));
    std::string sprice = trim(line_.substr(npos + 1));
    try {
        prop.time = TimeStamp::get(stime, '-');
    } catch (std::exception const &e) {
        std::cerr << "On line(" << linePos_ << ") '" << stime
                  << "' invalid date." << std::endl;
        return prop;
    }
    prop.price = fromString<double>(sprice);
    if (prop.price < 0) {
        std::cerr << "On line(" << linePos_ << ") '" << sprice
                  << "' invalid price." << std::endl;
        return prop;
    }
    if (maxValue_ != -1 && prop.price > maxValue_) {
        std::cerr << "On line(" << linePos_ << ") '" << sprice
                  << "' invalid price." << std::endl;
        return prop;
    }
    prop.skip = 0;
    return prop;
}

bool CSV::checkLine(std::string const &s, char sep) {
    return !s.empty() && std::count(s.begin(), s.end(), sep) == 1;
}

bool CSV::checkHeader(std::ifstream &file, char sep) {
    std::string line;
    return std::getline(file, line) && checkLine(line, sep);
}

void CSV::insertElement(std::vector<PricePair> &c, LineProperties const &prop) {
    c.push_back(prop.makePair());
}
void CSV::insertElement(PriceMap &c, LineProperties const &prop) {
    if (!c.insert(prop.makePair()).second)
        std::cerr << "Duplicate of entry on line(" + toString(linePos_) +
                         "): '" + line_ + "'."
                  << std::endl;
}

LineProperties::LineProperties() : time(0), price(0), skip(1) {}

PricePair LineProperties::makePair() const {
    return std::make_pair(time, price);
}
