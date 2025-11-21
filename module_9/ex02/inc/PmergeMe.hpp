#pragma once

#include "UserInput.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

// Define DEBUG to enable verbose logging
// #define DEBUG 1

// clang-format off
#ifdef DEBUG
#define DEBUG_PRINT(expr) do { expr; } while (0)
#else
#define DEBUG_PRINT(expr) do { (void)0; } while (0)
#endif
// clang-format on

template <typename Container>
class PmergeMe {
public:
    typedef typename Container::iterator       iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::value_type     value_type;

public:
    PmergeMe(Container &cnt) : cnt_(cnt), comparisons_(0) {}

    static size_t sort(Container &cnt) {
        PmergeMe pm(cnt);
        pm.sort();
        return pm.comparisons_;
    }

    size_t sort() {
        // Start recursion
        size_t maxPairSize = makePairs();

        // Unwind recursion
        while (maxPairSize > 0) {
            if (cnt_.size() / maxPairSize > 2) {
                DEBUG_PRINT(std::cout
                            << "\n========================================\n");
                DEBUG_PRINT(std::cout << " PHASE: Merge-Insertion (Pair Size: "
                                      << maxPairSize << ")\n");
                DEBUG_PRINT(std::cout
                            << "========================================\n");

                initializeMainPend(maxPairSize);
                movePendMainToCnt(maxPairSize);
                doMergeInserrtion(maxPairSize);
            }
            maxPairSize /= 2;
        }
        return comparisons_;
    }

private:
    // Helper to print specific ranges for debugging
    void printRange(const Container &c, size_t start_pair_idx,
                    size_t end_pair_idx, size_t pair_size) const {
        const_iterator it = c.begin();
        std::advance(it, start_pair_idx * pair_size);

        std::cout << "{ ";
        for (size_t i = start_pair_idx; i <= end_pair_idx && it != c.end();
             ++i) {
            std::cout << "[";
            // Print the value used for comparison (the last element in the pair)
            value_type val = getValueOfPair(c, i, pair_size);
            std::cout << val;
            std::cout << "] ";
            std::advance(it, pair_size);
        }
        std::cout << "}";
    }

    size_t makePairs(size_t pair_size = 1) {
        if (cnt_.size() < pair_size * 2)
            return pair_size / 2;

        size_t const comparisons = cnt_.size() / (pair_size * 2);

        DEBUG_PRINT(std::cout << "Recursion: Pairing elements with pair_size "
                              << pair_size << "...\n");

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

            comparisons_++;

            // Swap if left > right to ensure largest elements are at pair_size
            // intervals
            if (*left_pair_end > *right_pair_end) {
                // DEBUG_PRINT(std::cout << "  > Swap pair " << i << ": " <<
                // *left_pair_end << " > " << *right_pair_end << "\n");
                std::swap_ranges(it, right_start, right_start);
            }
            it = next_pair_start;
        }
        return makePairs(pair_size * 2);
    }

    void initializeMainPend(size_t pair_size) {
        main_.clear();
        pend_.clear();
        size_t const totalPairs = cnt_.size() / pair_size;
        iterator     it = cnt_.begin();
        pendPairs_ = 0;

        for (size_t pair = 0; pair < totalPairs; pair++) {
            iterator pair_end = it;
            std::advance(pair_end, pair_size);

            // a1, b1, a2, b2...
            // In Ford-Johnson: b elements go to Pend, a elements go to Main.
            // Note: The specific indexing logic here (pair % 2) assumes a
            // specific layout from makePairs.
            if (pair % 2 || pair == 0) {
                main_.insert(main_.end(), it, pair_end);
            } else {
                pend_.insert(pend_.end(), it, pair_end);
                pendPairs_++;
            }
            it = pair_end;
        }
        // Handle stragglers
        if (it != cnt_.end())
            pend_.insert(pend_.end(), it, cnt_.end());

        DEBUG_PRINT(std::cout << "Separation:\n");
        DEBUG_PRINT(std::cout << "  Main (a): size " << main_.size() / pair_size
                              << "\n");
        DEBUG_PRINT(std::cout << "  Pend (b): size " << pend_.size() / pair_size
                              << "\n");
    }

    void movePendMainToCnt(size_t pair_size) {
        cnt_.clear();
        // Move 'Main' (a) chain back to container first, as they are already
        // sorted relative to each other
        cnt_.insert(cnt_.begin(), main_.begin(), main_.end());

        size_t const        pendPairs = pend_.size() / pair_size;
        std::vector<size_t> insertPairOrder = makeInsertionsOrder(pendPairs);

        // Move 'Pend' (b) elements to the BACK of the container to prepare for
        // rotation/insertion
        for (std::vector<size_t>::const_iterator it = insertPairOrder.begin();
             it != insertPairOrder.end(); ++it) {
            iterator pair_begin = pend_.begin();
            std::advance(pair_begin, *it * pair_size);
            iterator pair_end = pair_begin;
            std::advance(pair_end, pair_size);
            cnt_.insert(cnt_.end(), pair_begin, pair_end);
        }

        // Move stragglers
        if (pendPairs * pair_size < pend_.size()) {
            iterator pos = pend_.begin();
            std::advance(pos, pendPairs * pair_size);
            cnt_.insert(cnt_.end(), pos, pend_.end());
        }
    }

    void doMergeInserrtion(size_t pair_size) {
        // mainPairs is the count of 'a' elements currently in the sorted portion
        size_t const mainPairs = cnt_.size() / pair_size / 2 + 1;

        // pend_begin points to the start of the 'Pend' elements we just
        // appended to the end of cnt_
        iterator pend_begin = cnt_.begin();
        std::advance(pend_begin, mainPairs * pair_size);

        size_t seed = 1;
        size_t cJacoNum = getJacoNum(seed);
        size_t pJacoNum = getJacoNum(seed - 1);
        size_t insertions = 0;

        DEBUG_PRINT(std::cout << "\n--- Starting Binary Insertion Phase ---\n");

        for (size_t i = 0; i < pendPairs_; i++, insertions++) {
            if (pJacoNum + insertions >= cJacoNum) {
                insertions = 0;
                pJacoNum = cJacoNum;
                cJacoNum = getJacoNum(++seed);
            }

            // The 'b' element to insert
            iterator pend_end = pend_begin;
            std::advance(pend_end, pair_size);

            // Get value for comparison (last element of the chunk)
            iterator val_iter = pend_end;
            --val_iter;
            value_type const &val_b = *val_iter;

            // Calculate the range in Main Chain to search.
            // We can search up to mainPairs + i (since i elements have been
            // added), constrained by Jacobsthal bound (2^seed - 1).
            size_t const search_boundary_idx =
                std::min(mainPairs + i, (1ul << seed) - 1);

            DEBUG_PRINT(std::cout << "\n[Step " << i + 1 << "/" << pendPairs_
                                  << "]\n");
            DEBUG_PRINT(std::cout << "  Inserting Pend Element (b): " << val_b
                                  << "\n");
            DEBUG_PRINT(std::cout
                        << "  Search Range (Main Chain): indices [0 to "
                        << search_boundary_idx << "]\n");
            DEBUG_PRINT(std::cout << "  Current Main Chain values: ");
            DEBUG_PRINT(printRange(cnt_, 0, search_boundary_idx, pair_size));
            DEBUG_PRINT(std::cout << "\n");

            // Perform Binary Search
            size_t idx =
                getInsertPairIndex(val_b, pair_size, search_boundary_idx);

            DEBUG_PRINT(std::cout << "  -> Found insertion index: " << idx
                                  << "\n");

            iterator where_to_insert = cnt_.begin();
            std::advance(where_to_insert, idx * pair_size);

            // Rotate [where_to_insert, pend_begin, pend_end]
            // This physically moves the 'b' chunk from the end of the array
            // into 'idx'
            std::rotate(where_to_insert, pend_begin, pend_end);

            // Update pointer: pend_begin has moved because of rotation?
            // Actually, pend_begin was the start of the chunk we just moved.
            // Since we rotated, the NEXT chunk to process is now sitting where
            // the OLD chunk ended.
            pend_begin = pend_end;
        }
    }

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

    size_t getInsertPairIndex(value_type const &value, size_t pair_size,
                              size_t right) const {
        size_t left = 0;

        // Debugging binary search details
        // DEBUG_PRINT(std::cout << "    Binary Search: target=" << value << "
        // within bounds [0, " << right << "]\n");

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            comparisons_++;

            value_type mid_val = getValueOfPair(cnt_, mid, pair_size);

            if (value < mid_val) {
                // DEBUG_PRINT(std::cout << "      Compare: " << value << " < "
                // << mid_val << " (Main[" << mid << "]) -> Go Left\n");
                right = mid;
            } else {
                // DEBUG_PRINT(std::cout << "      Compare: " << value << " > "
                // << mid_val << " (Main[" << mid << "]) -> Go Right\n");
                left = mid + 1;
            }
        }
        return left;
    }

    value_type const &
    getValueOfPair(Container const &c, size_t pair, size_t pair_size) const {
        size_t target_index = (pair + 1) * pair_size - 1;
        if (target_index >= c.size()) {
            throw std::out_of_range("Pair index is out of range " +
                                    std::to_string(target_index));
        }
        const_iterator it = c.begin();
        std::advance(it, target_index);
        return *it;
    }

    size_t getJacoNum(size_t seed) const {
        return (std::pow(2, (seed + 1)) + std::pow(-1, seed)) / 3;
    }

private:
    Container     &cnt_;
    mutable size_t comparisons_;
    Container      main_, pend_;
    size_t         pendPairs_;
};
