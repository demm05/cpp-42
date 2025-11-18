#include <aio.h>
#include <iostream>
#include <vector>

size_t findIndexToInsert(std::vector<size_t> &v, size_t target) {
    size_t left = 0, right = v.size() - 1;
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

int main(void) {
    std::vector<size_t> v = {1, 2, 3, 4, 5, 7, 8, 10, 12, 15, 18};
    size_t el = 6;
    size_t i = findIndexToInsert(v, el);
    std::cout << i << std::endl;
    if (i > 0) {
        std::cout << v[i - 1] << ", ";
    }
    std::cout << el;
    if (i < v.size())
        std::cout << ", " << v[i];
    std::cout << std::endl;
}
