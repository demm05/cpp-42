#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

void read_input(const char *message, string &dest) {
    if (!message)
        return;
    while (1) {
        cout << "Enter " << message << ": ";
        if (!getline(cin, dest)) {
            cout << endl << "^D was pressed, exitining" << endl;
            exit(1);
        }
        if (!dest.empty())
            break;
        dest.clear();
    }
}
