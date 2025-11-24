#include "utils.hpp"
#include <iomanip>

void printFormattedTime(clock_t ticks) {
    if (ticks < 0) {
        std::cout << "Invalid time" << std::endl;
        return;
    }

    double seconds = static_cast<double>(ticks) / CLOCKS_PER_SEC;

    std::cout << std::fixed << std::setprecision(3);

    if (seconds < 0.000001) {
        std::cout << "0 seconds" << std::endl;
    } else if (seconds < 0.001) {
        std::cout << (seconds * 1000000.0) << " microseconds";
    } else if (seconds < 1.0) {
        std::cout << (seconds * 1000.0) << " milliseconds";
    } else {
        std::cout << seconds << " seconds";
    }

    std::cout << " (" << ticks << " ticks)" << std::endl;
}
