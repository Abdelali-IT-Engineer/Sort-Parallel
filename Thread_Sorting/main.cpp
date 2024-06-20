#include "sorting.h"
#include "threading.h"
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <vector>



/*
// Mutual exclusion mechanisms
extern std::mutex mutex;
extern std::atomic_flag spinlock;

void enter_critical_section() {
    while (spinlock.test_and_set(std::memory_order_acquire)) {
        // Spin
    }
}

void exit_critical_section() {
    spinlock.clear(std::memory_order_release);
}

void enter_critical_section_mutex() {
    mutex.lock();
}

void exit_critical_section_mutex() {
    mutex.unlock();
}
*/



void display_sort_menu() {
  std::cout << "Choose sorting algorithm:" << std::endl;
  std::cout << "1. Quick Sort" << std::endl;
  std::cout << "2. Merge Sort" << std::endl;
}

SortType get_sort_type(int choice) {
  switch (choice) {
  case 1:
    return SortType::QuickSort;
  case 2:
    return SortType::MergeSort;
  default:
    std::cout << "Invalid choice. Using Quick Sort by default." << std::endl;
    return SortType::QuickSort;
  }
}

void display_data_type_menu() {
  std::cout << "Choose data type:" << std::endl;
  std::cout << "1. Integer" << std::endl;
  std::cout << "2. Float" << std::endl;
  std::cout << "3. String" << std::endl;
}

template <typename T> void input_data(std::vector<T> &data) {
  std::cout << "Enter data (type 'done' to finish):" << std::endl;
  T value;
  while (std::cin >> value) {
    data.push_back(value);
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void input_data(std::vector<std::string> &data) {
  std::cout << "Enter data (type 'done' to finish):" << std::endl;
  std::string value;
  while (std::cin >> value && value != "done") {
    data.push_back(value);
  }
}

template <typename T>
void sort_and_display(std::vector<T> &data, SortType sortType,
                      int sort_threads) {
  auto start = std::chrono::high_resolution_clock::now();
  sort_data(data, sortType, sort_threads);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;

  std::cout << "Quick/Merge Sorted data:" << std::endl;
  for (const auto &item : data) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  std::cout << "Time taken for quicksort/merge sort: " << duration.count()
            << " seconds" << std::endl;
}

template <typename T>
void radix_sort_and_display(std::vector<T> &data, int radix_threads) {
  auto start = std::chrono::high_resolution_clock::now();
  radix_sort(data, radix_threads);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;

  std::cout << "Time spent for radix sort: " << duration.count() << " seconds"
            << std::endl;
  std::cout << "Radix Sorted data:" << std::endl;
  for (const auto &item : data) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main() {
  display_data_type_menu();
  int dataTypeChoice;
  std::cin >> dataTypeChoice;

  display_sort_menu();
  int sortChoice;
  std::cin >> sortChoice;
  SortType sortType = get_sort_type(sortChoice);

  std::cout << "Enter the number of threads for quicksort/mergesort: ";
  int sort_threads;
  std::cin >> sort_threads;

  std::vector<int> int_data;
  std::vector<float> float_data;
  std::vector<std::string> string_data;

  switch (dataTypeChoice) {
  case 1: {
    input_data(int_data);

    sort_and_display(int_data, sortType, sort_threads);

    if (sortType == SortType::QuickSort || sortType == SortType::MergeSort) {
      std::cout << "Enter the number of threads for radix sort: ";
      int radix_threads;
      std::cin >> radix_threads;

      radix_sort_and_display(int_data, radix_threads);
    }

    break;
  }
  case 2: {
    input_data(float_data);
    sort_and_display(float_data, sortType, sort_threads);
    break;
  }
  case 3: {
    input_data(string_data);
    sort_and_display(string_data, sortType, sort_threads);
    break;
  }
  default:
    std::cout << "Invalid data type choice." << std::endl;
    break;
  }

  return 0;
}











