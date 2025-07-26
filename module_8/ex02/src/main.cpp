#include "../../ex00/inc/easyfind.hpp"
#include "MutantStack.hpp"

int main() {
    MutantStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    easyfind(s, 1);
    return 0;
}
