#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

template <typename Container> class PmergeMe {
public:
    typedef typename Container::iterator iterator;

public:
    PmergeMe(Container &cnt) : cnt_(cnt) {}

public:
    size_t makePairs(size_t pair_size = 1) {
        size_t units = cnt_.size() / pair_size;
        if (units < 2)
            return pair_size / 2;
        iterator begin = cnt_.begin();
        iterator end = begin;
        std::advance(end, (units * pair_size) - (pair_size * units % 2));
        for (iterator it = begin; it != end;) {
            iterator bx = it;
            iterator ax = it;
            std::advance(bx, pair_size - 1);
            std::advance(ax, pair_size * 2 - 1);
            if (*bx > *ax) {
                std::cout << "Swapping: " << *bx << ", " << *ax << std::endl;
                iterator mid = it;
                std::advance(mid, pair_size);
                std::swap_ranges(it, mid, mid);
            }
            std::advance(it, pair_size * 2);
        }
        return makePairs(pair_size * 2);
    }

private:
private:
    Container cnt_;
};

void printVec(std::vector<int> const &v, std::string const &name,
              int depth = 0) {
    std::cout << depth << ": " << name << ": ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> res = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                            1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
    PmergeMe<std::vector<int> > pm(res);
    pm.makePairs();
    printVec(res, "", 0);
}
