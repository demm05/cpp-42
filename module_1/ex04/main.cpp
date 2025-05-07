#include <string>
#include <fstream>
#include <iostream>
#include "Sed.hpp"

// TODO: first file should be open for reading if file can't be opened we print
// error Then another file should be created simply by adding .replace to the
// end of filename
int main(int argc, char *argv[]) {
    Sed sed;
    if (argc < 4) {
        std::cout << argv[0]
                  << ": requires 3 arguments to run: filename, str1, str2"
                  << std::endl;
        return (1);
    }
    if (!sed.open(std::string(argv[1])))
        return (1);
    sed.replace(argv[2], argv[3]);
    return 0;
}
