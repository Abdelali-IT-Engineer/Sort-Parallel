#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <algorithm>
#include <future>
#include "threading.h"

template <typename T>
void quicksort(std::vector<T>& data, int left, int right, int max_threads);

template <typename T>
void parallel_quicksort(std::vector<T>& data, int left, int right, int max_threads) {
    if (left < right) {
        int i = left, j = right;
        T pivot = data[(left + right) / 2];
        while (i <= j) {
            while (data[i] < pivot) i++;
            while (data[j] > pivot) j--;
            if (i <= j) {
                std::swap(data[i], data[j]);
                i++;
                j--;
            }
        }

        if (max_threads > 1) {
            auto future_left = async_execute(quicksort<T>, std::ref(data), left, j, max_threads / 2);
            auto future_right = async_execute(quicksort<T>, std::ref(data), i, right, max_threads / 2);
            future_left.wait();
            future_right.wait();
        } else {
            quicksort(data, left, j, max_threads);
            quicksort(data, i, right, max_threads);
        }
    }
}

template <typename T>
void quicksort(std::vector<T>& data, int left, int right, int max_threads) {
    parallel_quicksort(data, left, right, max_threads);
}

template <typename T>
void quicksort(std::vector<T>& data, int max_threads) {
    if (data.empty()) return;
    quicksort(data, 0, data.size() - 1, max_threads);
}

#endif // QUICKSORT_H
