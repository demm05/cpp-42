#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            for (int c = 0; argv[i][c]; c++)
                argv[i][c] = (char)std::toupper(argv[i][c]);
            if (argv[i] != NULL)
                std::cout << argv[i] << " ";
        }
    } else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
