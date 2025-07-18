#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Provide sth to the program" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++) {
        ScalarConverter::convert(argv[i]);
        if (i != argc - 1)
            std::cout << std::endl;
    }
    return 0;
}
