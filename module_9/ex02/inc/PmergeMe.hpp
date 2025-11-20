#pragma once

#include "UserInput.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

#ifdef DEBUG
#define DEBUG_PRINT(expr)                                                      \
    do {                                                                       \
        (expr);                                                                \
    } while (0)
#else
#define DEBUG_PRINT(expr)                                                      \
    do {                                                                       \
        (void)0;                                                               \
    } while (0)
#endif

template <typename Container> class PmergeMe {
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::value_type value_type;

public:
    PmergeMe(Container &cnt) : cnt_(cnt), swapCount_(0) {}

public:
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
            DEBUG_PRINT(std::cout << std::endl);
        }
        return swapCount_;
    }

private:
    std::vector<size_t> makeInsertionsOrder(size_t pairs) {
        std::vector<size_t> res;

        if (pairs == 0)
            return res;
        res.reserve(pairs);
        size_t seed = 2;
        size_t i = 0;
        while (i < pairs) {
            size_t jacoNum = getJacoNum(seed);
            size_t pJacoNum = getJacoNum(seed - 1);
            if (jacoNum > pairs)
                jacoNum = pairs + 1;
            if (jacoNum <= pJacoNum)
                break;
            for (; jacoNum > pJacoNum; jacoNum--) {
                res.push_back(jacoNum - 2);
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
        size_t const pendPairs = pend_.size() / pair_size;
        size_t const mainPairs = main_.size() / pair_size;
        movePendMainToCnt(pair_size);
        // This may work
        // iterator pend_begin = main_.end();
        iterator pend_begin = cnt_.begin();
        std::advance(pend_begin, mainPairs * pair_size);
        DEBUG_PRINT(std::cout << "Advanced by: " << mainPairs * pair_size
                              << " and begins on: " << *pend_begin
                              << std::endl);
        for (size_t i = 0; i < pendPairs; i++) {
            DEBUG_PRINT(std::cout << i << "; ");
            DEBUG_PRINT(std::cout << "pbegin: " << *pend_begin << "; ");
            size_t end = mainPairs + i;
            DEBUG_PRINT(std::cout << "end: " << end << "; ");
            iterator pend_end = pend_begin;
            std::advance(pend_end, pair_size);

            --pend_end;
            value_type const &v = *pend_end;
            ++pend_end;

            DEBUG_PRINT(std::cout << "inserting: " << v << "; ");

            size_t idx = getInsertPairIndex(v, pair_size, end);

            DEBUG_PRINT(std::cout << "idx: " << idx << "; ");

            DEBUG_PRINT(std::cout << "into: "
                                  << getValueOfPair(cnt_, idx, pair_size));

            iterator where_to_insert = cnt_.begin();
            std::advance(where_to_insert, idx * pair_size);

            std::rotate(where_to_insert, pend_begin, pend_end);

            pend_begin = pend_end;
            DEBUG_PRINT(std::cout << std::endl);
        }
    }

    size_t getInsertPairIndex(value_type const &value, size_t pair_size,
                              size_t right) const {
        size_t left = 0;

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            swapCount_++;
            if (value < getValueOfPair(cnt_, mid, pair_size))
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
            throw std::out_of_range("Pair index is out of range" +
                                    std::to_string(target_index));
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
#if DEBUG
        std::cout << "initialized main: ";
        printContainer(main_);
        std::cout << "initialized pend: ";
        printContainer(pend_);
#endif
    }

    void movePendMainToCnt(size_t pair_size) {
        cnt_.clear();
        cnt_.insert(cnt_.begin(), main_.begin(), main_.end());
        size_t const pendPairs = pend_.size() / pair_size;
        std::vector<size_t> insertPairOrder = makeInsertionsOrder(pendPairs);
#if DEBUG
        {
            std::cout << "Inserting order: ";
            for (std::vector<size_t>::const_iterator it =
                     insertPairOrder.begin();
                 it != insertPairOrder.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
#endif
        for (std::vector<size_t>::const_iterator it = insertPairOrder.begin();
             it != insertPairOrder.end(); ++it) {
            iterator pair_begin = pend_.begin();
            std::advance(pair_begin, *it * pair_size);
            iterator pair_end = pair_begin;
            std::advance(pair_end, pair_size);
            cnt_.insert(cnt_.end(), pair_begin, pair_end);
        }
        if (pendPairs * pair_size < pend_.size()) {
            iterator pos = pend_.begin();
            std::advance(pos, pendPairs * pair_size);
            cnt_.insert(cnt_.end(), pos, pend_.end());
        }
#if DEBUG
        std::cout << "Current cnt_ state: ";
        printContainer(cnt_);
#endif
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
