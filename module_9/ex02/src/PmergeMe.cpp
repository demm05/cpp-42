#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <stdexcept>

template <typename Container> class PmergeMe {
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::value_type value_type;

public:
    PmergeMe(Container &cnt) : cnt_(cnt), swapCount_(0) {}

public:
    static void printContainer(Container &c) {
        iterator it = c.begin();
        while (it != c.end())
            std::cout << *it++ << " ";
        std::cout << std::endl;
    }

    static size_t sort(Container &cnt) {
        PmergeMe pm(cnt);
        pm.sort();
        return pm.swapCount_;
    }

public:
    size_t sort() {
        size_t maxPairSize = makePairs();
        while (maxPairSize > 0) {
            doMergeInserrtion(maxPairSize);
            maxPairSize /= 2;
            std::cout << std::endl;
        }
        return swapCount_;
    }

    size_t comparisons() const { return swapCount_; }

private:
    std::vector<size_t> makeInsertionsOrder(size_t pair_size) {
        std::vector<size_t> res;

        size_t const pairs = pend_.size() / pair_size - 1;
        if (pairs == 0)
            return res;
        res.reserve(pairs);
        size_t seed = 2;
        size_t i = 0;
        while (i < pairs) {
            size_t jacoNum = getJacoNum(seed);
            size_t pJacoNum = getJacoNum(seed - 1);
            if (jacoNum > pairs + 1)
                jacoNum = pairs;
            if (jacoNum <= pJacoNum)
                break;
            for (; jacoNum > pJacoNum; jacoNum--) {
                res.push_back(jacoNum - 1);
                i++;
            }
            seed++;
        }
        return res;
    }

    void doMergeInserrtion(size_t pair_size) {
        size_t const totalPairs = cnt_.size() / pair_size;
        if (totalPairs <= 2)
            return;
        initializeMainPend(pair_size);
        std::vector<size_t> insertPairOrder = makeInsertionsOrder(pair_size);
        size_t seed = 1;
        for (std::vector<size_t>::const_iterator it = insertPairOrder.begin();
             it != insertPairOrder.end(); ++it) {
            size_t rangeInsertion = std::min((1ul << seed) - 1, totalPairs / 2);

            iterator pair_begin = pend_.begin();
            std::advance(pair_begin, *it * pair_size);
            iterator pair_end = pair_begin;
            std::advance(pair_end, pair_size);

            size_t idx = getInsertPairIndex(
                getValueOfPair(pend_, *it, pair_size), pair_size);
            iterator pos = main_.begin();
            std::advance(pos, idx * pair_size);
            main_.insert(pos, pair_begin, pair_end);
        }
        if ((totalPairs / 2) * pair_size < pend_.size()) {
            iterator pos = pend_.begin();
            std::advance(pos, (totalPairs / 2) * pair_size);
            main_.insert(main_.end(), pos, pend_.end());
        }
        ssize_t pairToInsert = -1;
    }

    size_t getInsertPairIndex(value_type const &value, size_t pair_size) const {
        size_t const totalPairs = main_.size() / pair_size;
        size_t left = 0, right = totalPairs;

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

    value_type const &getValueOfPair(Container const &c, size_t pair,
                                     size_t pair_size) const {
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
        iterator it = cnt_.begin();
        for (size_t pair = 0; pair < totalPairs; pair++) {
            iterator pair_end = it;
            std::advance(pair_end, pair_size);

            if (pair % 2 || pair == 0) { // ax
                main_.insert(main_.end(), it, pair_end);
            } else { // bx
                pend_.insert(pend_.end(), it, pair_end);
            }

            it = pair_end;
        }
        if (it != cnt_.end())
            pend_.insert(pend_.end(), it, cnt_.end());
    }

    size_t makePairs(size_t pair_size = 1) {
        if (cnt_.size() < pair_size * 2)
            return pair_size / 2;
        size_t const comparisons = cnt_.size() / (pair_size * 2);
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
                std::swap_ranges(it, right_start, right_start);
            }
            it = next_pair_start;
        }
        return makePairs(pair_size * 2);
    }

    size_t getJacoNum(size_t seed) const {
        return (std::pow(2, (seed + 1)) + std::pow(-1, seed)) / 3;
    }

private:
    Container &cnt_;
    mutable size_t swapCount_;
    Container main_, pend_;
};

int main() {
    std::vector<int> res = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                            1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
    PmergeMe<std::vector<int> > pm(res);
    pm.sort();
    std::cout << "Comparisons in total: " << pm.comparisons() << std::endl;
}
