#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

template <typename Container>
class PmergeMe {
public:
    typedef typename Container::iterator iterator;

public:
    PmergeMe(Container &cnt) : cnt_(cnt), swapCount_(0) {}

public:
    size_t makePairs(size_t pair_size = 1) {
        if (cnt_.size() < pair_size * 2)
            return pair_size / 2;
        size_t   comparisons = cnt_.size() / (pair_size * 2);
        iterator it = cnt_.begin();
        for (size_t i = 0; i < comparisons; i++) {
            iterator right_start = it;
            std::advance(right_start, pair_size);

            iterator next_pair_start = right_start;
            std::advance(next_pair_start, pair_size);

            iterator left_pair_end = right_start;
            --left_pair_end;

            iterator right_pair_end = next_pair_start;
            --right_pair_end;

            swapCount_++;
            if (*left_pair_end > *right_pair_end) {
#if DEBUG
                std::cout << "Swapping: " << *it << " - " << *left_pair_end
                          << " with " << *right_start << " - "
                          << *right_pair_end << std::endl;
#endif
                std::swap_ranges(it, right_start, right_start);
            }
            it = next_pair_start;
        }
        return makePairs(pair_size * 2);
    }

private:
private:
    Container &cnt_;
    size_t     swapCount_;
};

int main() {
    std::vector<int> res = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                            1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
    PmergeMe<std::vector<int> > pm(res);
    pm.makePairs();
}
