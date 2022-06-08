// Copyright 2022 Balova Elena

#ifndef MODULES_BALOVA_E_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_BALOVA_E_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

#include <vector>
#include <iostream>

template <class T>
class InterpolationSearch {
 public:
    InterpolationSearch() {}
    ~InterpolationSearch() {}

    int search(const T& key, const T* sorted_array, int size) {
        int left = 0;
        int right = size - 1;
        while (sorted_array[left] < key && sorted_array[right] > key) {
            int mid = left + ((key - sorted_array[left]) * (right - left))
                / (sorted_array[right] - sorted_array[left]);
            if (sorted_array[mid] < key) {
                left = mid + 1;
            } else {
                if (sorted_array[mid] > key) {
                    right = mid - 1;
                } else {
                    return mid;
                }
            }
        }
        if (sorted_array[left] == key) {
            return left;
        }
        if (sorted_array[right] == key) {
            return right;
        }
        return -1;
    }

    int search(const T& key,
        const std::vector<T>& sorted_array) {
        return search(key, sorted_array.data(),
                      static_cast<int>(sorted_array.size()));
    }
};

#endif  // MODULES_BALOVA_E_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
