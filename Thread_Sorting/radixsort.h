#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <atomic>    
#include <iostream>
#include "threading.h"


void counting_sort(std::vector<int>& data, int exp, int max_threads) {
    int n = data.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(data[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(data[i] / exp) % 10] - 1] = data[i];
        count[(data[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        data[i] = output[i];
}

void radix_sort(std::vector<int>& data, int max_threads) 
{

    int max = *std::max_element(data.begin(), data.end());

    for (int exp = 1; max / exp > 0; exp *= 10) 
    {
        if (get_thread_count() < max_threads) {
            auto future = async_execute(counting_sort, std::ref(data), exp, max_threads);
            future.get();
        } else {
            counting_sort(data, exp, max_threads);
        }
    }

}

#endif 
