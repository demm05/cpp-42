#include "BitcoinExchange.hpp"
#include "CSV.hpp"
#include "types.hpp"
#include <ctime>
#include <iostream>
#include <ostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(std::string const &path_to_data_file) {
    std::ifstream file(path_to_data_file.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open '" + path_to_data_file + "'.");
    CSV::parseFile(data_, file);
};

void BitcoinExchange::process(std::string const &path_to_input) {
    std::ifstream file(path_to_input.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open '" + path_to_input + "'.");
    PriceVector entries;
    CSV::parseFile(entries, file);
    for (PriceVector::const_iterator it = entries.begin(); it != entries.end();
         ++it) {
        processEntry(*it);
    }
}

char const *pprint(time_t t) {
    static char buffer[256];
    struct tm *tm = localtime(&t);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);
    return buffer;
}

void BitcoinExchange::processEntry(PricePair const &el) {
    time_t target_date = el.first;

    PriceMap::const_iterator it = data_.upper_bound(target_date);

    if (it == data_.begin()) {
        std::cerr << "Error: No data available on or before "
                  << pprint(target_date) << std::endl;
        return;
    }
    --it;
    std::cout << pprint(target_date) << " => " << pprint(it->first) << " => "
              << el.second << " = " << it->second * el.second << std::endl;
}
