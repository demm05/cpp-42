#pragma once

#include "types.hpp"

class BitcoinExchange {
public:
    BitcoinExchange(std::string const &path_to_data_file);
    void process(std::string const &path_to_input);

private:
    PriceMap data_;

    void processEntry(PricePair const &);
};
