#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <type_traits>
#include <iostream>
#include "quicksort.h"
#include "mergesort.h"
#include "radixsort.h"

enum class SortType {
    QuickSort,
    MergeSort
};

template <typename T>
void sort_data(std::vector<T>& data, SortType sortType, int max_threads) {
    switch (sortType) {
        case SortType::QuickSort:
            quicksort(data, max_threads);
            break;
        case SortType::MergeSort:
            mergesort(data, max_threads);
            break;
        default:
            std::cout << "Invalid sort type." << std::endl;
            break;
    }
}

template <typename T>
void preprocess_data(std::vector<T>& data, int max_threads) {
    // This function is a no-op for non-integer types
}

template <>
void preprocess_data<int>(std::vector<int>& data, int max_threads) {
    radix_sort(data, max_threads);
}

#endif // SORTING_H
