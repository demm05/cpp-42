#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

int depth = 0;

// template <typename T> class PmergeMe {
// public:
// #if 0
//     template <typename Container> static void sort(Container &container) {
//         std::cout << "Hello2" << std::endl;
//     };
// #endif
//     static void sort(std::vector<T> &container) {
//         PmergeMe<T> pm;
//         pm.doMergeInsertion(container);
//     }
//
// private:

// 0; 1 2 3 4 5 6
// i = 0; i1 = 0; i2 = 1
// i = 1; i2 = 2; i3 = 3;
// i = 2; i4 = 4; i5 = 5;

// i = 0; i1 = 0; i2 = 1
// i = 2; i2 = 2; i3 = 3;
// i = 4; i4 = 4; i5 = 5;

// i1 = i * level
// i2 = (i + 1) * level
// 1;
// i = 0; i1 = 1; i2 = 3

template <typename T>
size_t getNumOfPairs(std::vector<T> &container, size_t level) {
    return (level ? container.size() / (level * 2) : container.size());
}
size_t getPairStartIdx(size_t pair, size_t level) { return pair * level * 2; }

template <typename T>
void doMergeInsertion(std::vector<T> &container, size_t level = 1) {
    depth++;
    size_t numOfPairs = getNumOfPairs(container, level);
    if (numOfPairs < 2) {
        depth--;
        return;
    }
    std::cout << depth << ", " << numOfPairs << std::endl;
    if (numOfPairs % 2) {
        size_t start = getPairStartIdx(--numOfPairs, level);
        while (start < container.size()) {
            container.pop_back();
        }
    }
    for (size_t i = 0; i < numOfPairs; i++) {
        size_t start = getPairStartIdx(i + 1, level);
        std::cout << "[" << container[start - level - 1] << ","
                  << container[start - 1] << "] ";
    }
    doMergeInsertion(container, level + 1);
    depth--;
}

static size_t getjacobsthal(int n) {
    // return ((1UL << (n + 1)) + std::pow(-1, n)) / 3;
    return (std::pow(2, (n + 1)) + std::pow(-1, n)) / 3;
}
// };

int main(int argc, char const **argv) {
    std::vector<int> res = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                            1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
    doMergeInsertion(res);
    // PmergeMe<int>::sort(res);
    // merge_insert_sort(res);
    // for (size_t i = 0; i < res.size(); i++) {
    //     std::cout << res[i] << " ";
    // }
    std::cout << std::endl;
}

#if 0

    ssize_t getNextInsertionIndexElement() { jictx.getNextIdx(); }

    class JacoInsertionCTX {
    public:
        JacoInsertionCTX()
            : jacoIndex(1), cJacoNumber(getjacobsthal(jacoIndex)) {}

        void update() {
            pJacoNumber = cJacoNumber;
            cJacoNumber = getjacobsthal(++jacoIndex);
        }
        size_t getNextIdx() {
            if (pJacoNumber + numOfInsertionsForCJ >= cJacoNumber) {
                update();
            }
            return cJacoNumber - numOfInsertionsForCJ - 1;
        }

    private:
        size_t numOfInsertionsForCJ;
        size_t jacoIndex;
        size_t cJacoNumber;
        size_t pJacoNumber;
    };
    JacoInsertionCTX jictx;
#endif
