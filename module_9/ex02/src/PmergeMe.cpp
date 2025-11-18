#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <stdexcept>

template <typename Container>
class PmergeMe {
public:
    typedef typename Container::iterator       iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::value_type     value_type;

public:
    PmergeMe(Container &cnt) : cnt_(cnt), swapCount_(0) {}

public:
    void sort() {
        size_t maxPairSize = makePairs();
        printContainer(cnt_);
        while (maxPairSize > 0) {
            doMergeInsertion(maxPairSize);
            maxPairSize /= 2;
            std::cout << std::endl;
        }
        printContainer(cnt_);
    }

    size_t comparisons() const { return swapCount_; }

private:
    void doMergeInsertion(size_t pair_size) {
        size_t const totalPairs = cnt_.size() / pair_size;
        size_t       seed = 1;
        if (totalPairs <= 2)
            return;
        std::cout << pair_size << std::endl;

        initializeMainPend(pair_size);

        size_t const pendPairs = pend_.size() / pair_size;
        std::cout << "pendPairs: " << pendPairs << std::endl;
        // iterator     it = pend_.begin();
        for (size_t i = 0; i < pendPairs; i++) {
            iterator pair_begin = pend_.begin();
            std::advance(pair_begin, i * pair_size);
            // iterator pair_begin = it;
            iterator pair_end = pair_begin;
            std::advance(pair_end, pair_size);
            // it = pair_end;
            // --pair_end;

            value_type const &invalue = getValueOfPair(pend_, i, pair_size);
            std::cout << "Inserting from pend ax: " << invalue << std::endl;
            size_t idx = getInsertPairIndex(getValueOfPair(pend_, i, pair_size),
                                            pair_size);
            iterator pos = main_.begin();
            std::advance(pos, idx * pair_size);
            main_.insert(pos, pair_begin, pair_end);
            std::cout << "Iserting: (" << *pair_begin << " - " << *--pair_end
                      << ") at index: " << idx << std::endl;
            std::cout << "main: ";
            printContainer(main_);
        }
        if (pendPairs * pair_size < pend_.size()) {
            iterator pos = pend_.begin();
            std::advance(pos, pendPairs * pair_size);
            main_.insert(main_.end(), pos, pend_.end());
        }
        std::cout << "main: ";
        printContainer(main_);
        cnt_ = main_;
    }

    size_t getInsertPairIndex(value_type const &value, size_t pair_size) const {
        size_t const totalPairs = main_.size() / pair_size;
        size_t       left = 0, right = totalPairs;

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            swapCount_++;
            if (value < getValueOfPair(main_, mid, pair_size))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    value_type const &
    getValueOfPair(Container const &c, size_t pair, size_t pair_size) const {
        size_t target_index = (pair + 1) * pair_size - 1;
        if (target_index >= c.size()) {
            throw std::out_of_range("Pair index is out of range");
        }
        const_iterator it = c.begin();
        std::advance(it, target_index);
        return *it;
    }

    void initializeMainPend(size_t pair_size) {
        main_.clear();
        pend_.clear();
        size_t const totalPairs = cnt_.size() / pair_size;
        iterator     it = cnt_.begin();
        for (size_t pair = 0; pair < totalPairs; pair++) {
            iterator pair_end = it;
            std::advance(pair_end, pair_size);

            if (pair % 2 || pair == 0) {  // ax
                main_.insert(main_.end(), it, pair_end);
            } else {  // bx
                pend_.insert(pend_.end(), it, pair_end);
            }

            it = pair_end;
        }
        if (it != cnt_.end())
            pend_.insert(pend_.end(), it, cnt_.end());
        std::cout << "main: ";
        printContainer(main_);
        std::cout << "pend: ";
        printContainer(pend_);
    }

    size_t makePairs(size_t pair_size = 1) {
        if (cnt_.size() < pair_size * 2)
            return pair_size / 2;
        size_t const comparisons = cnt_.size() / (pair_size * 2);
        iterator     it = cnt_.begin();
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

    void printContainer(Container &c) const {
        iterator it = c.begin();
        while (it != c.end())
            std::cout << *it++ << " ";
        std::cout << std::endl;
    }

    size_t getJacoNum(size_t seed) const {
        return (std::pow(2, (seed + 1)) + std::pow(-1, seed)) / 3;
    }

private:
    Container     &cnt_;
    mutable size_t swapCount_;
    Container      main_, pend_;
};

int main() {
    std::list<int>            res = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                                     1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
    PmergeMe<std::list<int> > pm(res);
    pm.sort();
    std::cout << "Comparisons in total: " << pm.comparisons() << std::endl;
}
