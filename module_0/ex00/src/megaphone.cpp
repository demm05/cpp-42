#include <cctype>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            for (int c = 0; argv[i][c]; c++)
                argv[i][c] = (char) toupper(argv[i][c]);
            if (argv[i] != NULL)
                cout << argv[i] << " ";
        }
    } else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    cout << endl;
    return (0);
}
