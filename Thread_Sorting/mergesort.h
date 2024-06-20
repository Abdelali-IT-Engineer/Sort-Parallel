#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <algorithm>
#include <future>
#include "threading.h"

template <typename T>
void mergesort(std::vector<T>& data, int left, int right, int max_threads);

template <typename T>
void parallel_mergesort(std::vector<T>& data, int left, int right, int max_threads) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        if (max_threads > 1) {
            auto future_left = async_execute(mergesort<T>, std::ref(data), left, mid, max_threads / 2);
            auto future_right = async_execute(mergesort<T>, std::ref(data), mid + 1, right, max_threads / 2);
            future_left.wait();
            future_right.wait();
        } else {
            mergesort(data, left, mid, max_threads);
            mergesort(data, mid + 1, right, max_threads);
        }

        std::inplace_merge(data.begin() + left, data.begin() + mid + 1, data.begin() + right + 1);
    }
}

template <typename T>
void mergesort(std::vector<T>& data, int left, int right, int max_threads) {
    parallel_mergesort(data, left, right, max_threads);
}

template <typename T>
void mergesort(std::vector<T>& data, int max_threads) {
    if (data.empty()) return;
    mergesort(data, 0, data.size() - 1, max_threads);
}

#endif // MERGESORT_H
