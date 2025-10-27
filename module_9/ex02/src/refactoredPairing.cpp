#include <cmath>
#include <cstring>
#include <vector>

int depth = 0;

template <typename T> struct PmergeMe {
    std::vector<T> &items;
    std::vector<T> pairs;
    std::vector<T> pend;

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
    pm.doPairing();
    merge_insert_sort(pm.pairs);
}
