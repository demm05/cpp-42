#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

int depth = 0;

size_t getJacoNum(int n) {
    return (std::pow(2, (n + 1)) + std::pow(-1, n)) / 3;
}

template <typename T> struct PmergeMe {
    std::vector<T> &items;
    std::vector<T> pairs;
    std::vector<T> pend;

    size_t findIndexToInsert(std::vector<T> &v, T target,
                             size_t boundPosition) {
        size_t left = 0, right = boundPosition;
        while (left <= right && right < v.size()) {
            size_t mid = (right + left) / 2;
            if (target > v[mid])
                left = mid + 1;
            else if (target < v[mid])
                right = mid - 1;
            else
                return mid;
        }
        if (left == v.size())
            return left;
        else if (v[left] > target)
            return left;
        else
            return left + 1;
    }

    PmergeMe(std::vector<T> &items) : items(items) {
        pairs.reserve(items.size() / 2);
        pend.reserve(items.size() / 2);
    }

    void doPairing() {
        for (size_t i = 0; i + 1 < items.size(); i += 2) {
            if (items[i] < items[i + 1]) {
                pairs.push_back(items[i + 1]);
                pend.push_back(items[i]);
            } else {
                pairs.push_back(items[i]);
                pend.push_back(items[i + 1]);
            }
        }
    }

    void saveStraggler() {}
    void insertStraggler() {}

    bool assembleMainChain() {
        if (pend.empty())
            return false;
        pairs.insert(pairs.begin(), pend.front());
        return pend.size() > 1;
    }

    void doBinaryInsertion(size_t pendIndex, size_t boundPosition) {
        // std::cout << "at index (" << pendIndex << ") " << pend[pendIndex];
        boundPosition = std::min(boundPosition, pairs.size());
        size_t i = findIndexToInsert(pairs, pendIndex, boundPosition);
        // std::cout << " at the position: " << i << " and between: (0)";
        // if (i > 0) {
        //     std::cout << pairs[i - 1] << ", ";
        // }
        // std::cout << pend[pendIndex];
        // if (i < pairs.size())
        //     std::cout << ", " << pairs[i];
        // std::cout << "(" << boundPosition << ")" << std::endl;
        pairs.insert(pairs.begin(), pend[pendIndex]);
    }

    // clang-format off
    // Q: When jaco index is being increased?
    // A: When we inserted cJacoNumber - pJaconumber elements
    //      3 - 1 = 2 elements to insert once they were we update it (b3 and b2)
    // clang-format on
    void doInsertion() {
        size_t seed = 1;
        size_t cJacoNumber = getJacoNum(seed);
        size_t pJacoNumber = getJacoNum(seed - 1);
        size_t insertions = 0;
        size_t totalInsertions = 0;
        while (totalInsertions < pend.size() - 1) {
            if (pJacoNumber + insertions >= cJacoNumber) {
                pJacoNumber = cJacoNumber;
                cJacoNumber = getJacoNum(++seed);
                // if (cJacoNumber > pend.size())
                //     insertions = pend.size() - cJacoNumber;
                insertions = 0;
                continue;
            }
            size_t bx = cJacoNumber - insertions - 1;
            std::cout << "inserting b" << bx << "(" << pend[bx] << ")"
                      << std::endl;
            size_t axPos = 1 << seed;
            doBinaryInsertion(bx, axPos);
            insertions++;
            totalInsertions++;
        }
        // size_t totalInsertions = 1;
        // size_t jacoIndex = 1;
        // size_t cJacoNumber = getJacoNum(jacoIndex);
        // size_t pJacoNumber = getJacoNum(jacoIndex - 1);
        // size_t countOfInsertedElementForTheCurrentJacoIndex = 0;
        // while (totalInsertions < pend.size()) {
        //     if (pJacoNumber + countOfInsertedElementForTheCurrentJacoIndex >=
        //         cJacoNumber) {
        //         pJacoNumber = cJacoNumber;
        //         cJacoNumber = getJacoNum(++jacoIndex);
        //         countOfInsertedElementForTheCurrentJacoIndex = 0;
        //     }
        //     size_t index =
        //         cJacoNumber - countOfInsertedElementForTheCurrentJacoIndex -
        //         1;
        //     std::cout << "Inserting b("
        //               << cJacoNumber -
        //                      countOfInsertedElementForTheCurrentJacoIndex
        //               << ") ";
        //     size_t boundPosition = 1 << jacoIndex;
        //     doBinaryInsertion(index, boundPosition);
        //     // pairs.insert(pairs.begin(), pend[index]);
        //     countOfInsertedElementForTheCurrentJacoIndex++;
        //     totalInsertions++;
        // }
    }
};

template <typename T> void merge_insert_sort(std::vector<T> &items) {
    {
        // TODO: To delete depth before evalution
        depth++;
        if (items.size() <= 1) {
            depth--;
            return;
        }
    }
    PmergeMe<T> pm(items);
    pm.saveStraggler();
    pm.doPairing();
    std::cout << depth << "before: main: ";
    for (size_t i = 0; i < pm.pairs.size(); i++) {
        std::cout << pm.pairs[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "pend: ";
    for (size_t i = 0; i < pm.pend.size(); i++) {
        std::cout << pm.pend[i] << " ";
    }
    std::cout << std::endl;
    merge_insert_sort(pm.pairs);
    std::cout << depth << "after: main: ";
    for (size_t i = 0; i < pm.pairs.size(); i++) {
        std::cout << pm.pairs[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "pend: ";
    for (size_t i = 0; i < pm.pend.size(); i++) {
        std::cout << pm.pend[i] << " ";
    }
    std::cout << std::endl;
    if (!pm.assembleMainChain())
        return;
    pm.doInsertion();
    pm.insertStraggler();
}

int main(int argc, char const **argv) {
    std::vector<int> res = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                            1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
    merge_insert_sort(res);
    for (size_t i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}
/*


CI = 1 + (Jaco Index) + (Total number of insertions)

Recursion level: 2
main chain: 15 16 17 19 20 21
pend chain: 11 18 12 10 13

// TI = 0; IN = 0; JN = 3; IX = b3; CN = a3; CNEND = 4; AS = 6
// TI = 1; IN = 1; JN = 3; IX = b2; CN = a2; CNEND = 3; AS = 7
// TI = 2; IN = 0; JN = 5; IX = b5; CN = a5; CNEND = 7; AS = 8
// TI = 3; IN = 1; JN = 5; IX = b4; CN = a5; CNEND = 7; AS = 9
// Now only one element left and we have to compare with the whole array

I Guess the formula is: CNEND = JN + TI + 1
*/
/*

Recursion level: 1
main chain: 3 10 11 12 13 15 16 17 18 19 20 21
pend chain: 2 5 7 6 8 0 9 14 4 1

// TI = 0; IN = 0; JN = 3; IX = b3; CN = a3; CNEND = 4; AS = 12
// TI = 1; IN = 1; JN = 3; IX = b2; CN = a2; CNEND = 4; AS = 13
// TI = 2; IN = 0; JN = 5; IX = b5; CN = a5; CNEND = 8; AS = 14
// TI = 3; IN = 1; JN = 5; IX = b4; CN = a4; CNEND = 8; AS = 15
// TI = 4; IN = 0; JN = 11; IX = b11; CN = a11; CNEND = 16; AS = 16;
// TI = 5; IN = 1; JN = 11; IX = b10; CN = a10; CNEND = 16; AS = 17;
// TI = 6; IN = 1; JN = 11; IX = b9; CN = a9; CNEND = 16; AS = 18;
// TI = 7; IN = 1; JN = 11; IX = b8; CN = a8; CNEND = 16; AS = 19;
// TI = 8; IN = 1; JN = 11; IX = b7; CN = a7; CNEND = 16; AS = 20;
// TI = 9; IN = 1; JN = 11; IX = b6; CN = a6; CNEND = 16; AS = 20;

*/
