#pragma once

#include "types.hpp"
#include <TimeStamp.hpp>
#include <fstream>
#include <string>

struct LineProperties {
    time_t time;
    double price;
    bool skip;

    LineProperties();
    PricePair makePair() const;
};

class CSV {
public:
    template <typename T>
    static void parseFile(T &container, std::ifstream &file, ssize_t maxValue) {
        CSV inst(maxValue);
        inst.parse(container, file);
    }

private:
    std::string line_;
    size_t linePos_;
    char sep_;
    ssize_t maxValue_;

private:
    CSV(ssize_t maxValue);
    void processHeader(std::ifstream &file);
    LineProperties processLine();

    bool checkLine(std::string const &, char sep);
    bool checkHeader(std::ifstream &file, char sep);

    void insertElement(PriceMap &, LineProperties const &);
    void insertElement(std::vector<PricePair> &, LineProperties const &);

    template <typename T> void parse(T &container, std::ifstream &file) {
        if (!file.is_open() || !file.good())
            throw std::runtime_error("File is not opened");
        line_.clear();
        linePos_ = 1;
        processHeader(file);
        line_.clear();
        while (std::getline(file, line_)) {
            linePos_++;
            LineProperties prop = processLine();
            if (prop.skip)
                continue;
            insertElement(container, prop);
            line_.clear();
        }
    }
};
