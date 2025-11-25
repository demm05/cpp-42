#include "../inc/BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Provid path to input data as an argument" << std::endl;
        return 1;
    }
    BitcoinExchange *btc = NULL;
    try {
        btc = new BitcoinExchange("data.csv");
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    for (int i = 1; i < argc; i++) {
        try {
            btc->process(argv[i]);
        } catch (std::exception const &e) {
            std::cerr << e.what() << std::endl;
        } catch (...) {
        }
    }
    return 0;
}
