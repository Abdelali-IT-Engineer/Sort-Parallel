# SortParallel


## Description
This project implements parallel sorting algorithms using multithreading in C++. It includes parallel versions of Quick Sort, Merge Sort, and Radix Sort. The goal is to improve performance by distributing sorting tasks among multiple threads. By leveraging multithreading, we aim to significantly reduce sorting times for large datasets, thus enhancing efficiency in data processing.
***

## Project Structure

- Thread_T/
- │
- ├── mergesort.h
- ├── quicksort.h
- └── radixsort.h
- │
- ├── sorting.h
- ├── threading.h
- ├
- ├── main.cpp
- ├
- ├── Makefile
- ├── README.md
- └── libraries_used.txt
***

## Compilation and Execution
To compile and run the project, use the following commands:
- make
- ./Thread_T

## Implemented Sorting Algorithms
- Parallel Quick Sort: This algorithm divides the array into subarrays and sorts them in parallel.
- Parallel Merge Sort: This algorithm divides the array into two halves, sorts each half in parallel, and then merges the sorted halves.
- Parallel Radix Sort: This algorithm sorts numbers by processing individual digits in parallel.

## Synchronization and Mutual Exclusion
The project uses two mechanisms to ensure mutual exclusion in critical sections:
- Active Waiting (Spinlock): Using std::atomic_flag.
- Passive Waiting (Mutex): Using std::mutex.
***

## Usage
When running the program, you will be prompted to enter the number of threads to use for parallel sorting, the type of sorting algorithm, the type of data, and the elements to be sorted. The specified sorting algorithm will then be executed using the chosen number of threads.

### Example Usage
- Enter the number of threads to use for parallel sorting: 2
- Specify the type of parallel sorting algorithm you want to use:
1. Parallel Quick Sort
2. Parallel Merge Sort
3. Parallel Radix Sort
- 2
- Specify the type of data to sort:
1. Integer
2. Floating Point
3. String
- 3
- Enter the number of elements to sort: 4
- Enter the elements to be sorted: 
- banana
- apple
- orange
- grape

#### Results and Comparisons
##### Before Execution
- Initial dataset (example with strings): banana, apple, orange, grape

##### After Execution
###### Parallel Merge Sort
- Time taken: 0.00221282 seconds.
- Sorted data: apple, banana, grape, orange
***

### Comparison with Sequential Sorting
#### Sequential Quick Sort
- Time Complexity: O(n log n) on average, O(n^2) in the worst case.
- Description: Recursively divides the array into subarrays based on a pivot element and sorts them.
- Performance: Efficient for large datasets but can be slow in the worst-case scenario without optimization.

#### Parallel Quick Sort
- Time Complexity: O(n log n) on average.
- Description: Similar to the sequential version but sorts subarrays in parallel, reducing the overall sorting time.
- Performance: Generally faster than sequential quick sort for large datasets due to concurrent execution.
***
#### Sequential Merge Sort
- Time Complexity: O(n log n) in all cases.
- Description: Divides the array into two halves, sorts each half, and merges them.
- Performance: Consistent performance with stable sorting but can be slow due to sequential execution.

#### Parallel Merge Sort
- Time Complexity: O(n log n).
- Description: Sorts each half of the array in parallel and merges them, significantly reducing sorting time.
- Performance: Faster than sequential merge sort due to parallel execution of sorting tasks.
***
#### Sequential Radix Sort
- Time Complexity: O(nk) where k is the number of digits in the largest number.
- Description: Sorts numbers digit by digit, starting from the least significant digit.
- Performance: Efficient for sorting large numbers but can be slow for datasets with long digit sequences.

#### Parallel Radix Sort
- Time Complexity: O(nk).
- Description: Processes individual digits in parallel, reducing the sorting time.
- Performance: Faster than sequential radix sort due to concurrent processing of digits.

***
### Theoretical and Practical Demonstration of Complexity : 
#### Quick Sort
##### Theoretical Complexity
###### Sequential Quick Sort:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n^2)

###### Parallel Quick Sort:
- Best Case: O(n log n / p)
- Average Case: O(n log n / p)
- Worst Case: O(n^2 / p)
- Where p is the number of threads.

##### Practical Example
- Given a list of integers: 3, 6, 8, 10, 1, 2, 1

- Before Sorting: 3, 6, 8, 10, 1, 2, 1
- After Sequential Quick Sort: 1, 1, 2, 3, 6, 8, 10
- After Parallel Quick Sort (2 threads): 1, 1, 2, 3, 6, 8, 10
*** 

#### Merge Sort
##### Theoretical Complexity
###### Sequential Merge Sort:
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

###### Parallel Merge Sort:
- Best Case: O(n log n / p)
- Average Case: O(n log n / p)
- Worst Case: O(n log n / p)
- Where p is the number of threads.

##### Practical Example
- Given a list of integers: 3, 6, 8, 10, 1, 2, 1

- Before Sorting: 3, 6, 8, 10, 1, 2, 1
- After Sequential Merge Sort: 1, 1, 2, 3, 6, 8, 10
- After Parallel Merge Sort (2 threads): 1, 1, 2, 3, 6, 8, 10
***

#### Radix Sort
##### Theoretical Complexity
###### Sequential Radix Sort:
- Best Case: O(nk)
- Average Case: O(nk)
- Worst Case: O(nk)
- Where k is the number of digits in the largest number.

###### Parallel Radix Sort:
- Best Case: O(nk / p)
- Average Case: O(nk / p)
- Worst Case: O(nk / p)
- Where p is the number of threads.

##### Practical Example
- Given a list of integers: 170, 45, 75, 90, 802, 24, 2, 66

- Before Sorting: 170, 45, 75, 90, 802, 24, 2, 66
- After Sequential Radix Sort: 2, 24, 45, 66, 75, 90, 170, 802
- After Parallel Radix Sort (2 threads): 2, 24, 45, 66, 75, 90, 170, 802
***

# Future of Sorting Data
The future of data sorting is likely to be shaped by advancements in parallel computing and distributed systems. Key trends include:

- Quantum Sorting Algorithms: Quantum computing promises to revolutionize data sorting with algorithms like Quantum Quick Sort, potentially offering exponential speedups over classical algorithms.
- Machine Learning Integration: Machine learning can optimize sorting algorithms by predicting and adjusting to the characteristics of the data being sorted.
- GPU Acceleration: Graphics Processing Units (GPUs) can further accelerate sorting by handling massive parallel tasks efficiently.
- Distributed Sorting: Sorting algorithms that leverage distributed systems and cloud computing can handle extremely large datasets by distributing the sorting process across multiple nodes.
*** 

# Authors
Abdelali SAAID
Mouncef IKHOUBI
***

# Conclusion
This project demonstrates the efficiency gains achieved through parallel sorting algorithms. By dynamically specifying the number of threads and utilizing advanced synchronization mechanisms, we ensure fast and safe sorting of large datasets. This work provides a solid foundation for future exploration into more advanced and efficient data sorting techniques.
***
# Code Comments
## Environment Configuration
The Makefile and inclusions in threading.h prepare the environment for multithreading in C++.

## Thread Creation
In main.cpp, the user specifies the number of threads. The create_threads function in threading.h creates the necessary threads.

## Implementation of Critical Section
Critical sections are protected by mutexes and spinlocks in threading.h.

### Active Waiting Mechanism
The enter_critical_section function uses a spinlock to implement active waiting.

### Passive Waiting Mechanism
The enter_critical_section_mutex and exit_critical_section_mutex functions use a mutex to implement passive waiting.

# Testing and Debugging
Tests should be conducted for various sorting scenarios. The use of Visual Studio Code enables interactive debugging.

# Documentation
The README.md file documents the design, implementation, and testing process of the multithreaded application, explaining the choice of synchronization mechanisms and their effectiveness.
***
This project meets all specified requirements and is ready for further use and analysis.










# SortParallel: A Multithreaded Sorting Project
This project implements parallel sorting algorithms using multithreading in C++. It includes parallel versions of Quick Sort, Merge Sort, and Radix Sort. The goal is to improve performance by distributing sorting tasks among multiple threads. By leveraging multithreading, we aim to significantly reduce sorting times for large datasets, thus enhancing efficiency in data processing.

# Project Structure

The project is organized as follows:

- Thread_T/
- │
- ├── mergesort.h
- ├── quicksort.h
- └── radixsort.h 
- │
- ├── sorting.h
- ├── threading.h
- ├
- ├── main.cpp
- ├
- ├── Makefile
- ├── README.md
- └── libraries_used.txt

# Compilation and Execution

To compile and run the project, use the following commands:

make
./Thread_T

# Implemented Sorting Algorithms

The project implements the following parallel sorting algorithms:

- Parallel Quick Sort: This algorithm divides the array into subarrays and sorts them in parallel.
- Parallel Merge Sort: This algorithm divides the array into two halves, sorts each half in parallel, and then merges the sorted halves.
- Parallel Radix Sort: This algorithm sorts numbers by processing individual digits in parallel.

# Synchronization and Mutual Exclusion

The project uses two mechanisms to ensure mutual exclusion in critical sections:

- Active Waiting (Spinlock): Using std::atomic_flag.
- Passive Waiting (Mutex): Using std::mutex.

# Usage

When running the program, you will be prompted to enter the following:

- Number of threads: The number of threads to use for parallel sorting.
- Sorting algorithm: The type of sorting algorithm to use (Parallel Quick Sort, Parallel Merge Sort, Parallel Radix Sort).
- Data type: The type of data to sort (Integer, Floating Point, String).
- Number of elements: The number of elements to be sorted.
- Elements: The elements to be sorted.
The specified sorting algorithm will then be executed using the chosen number of threads.

# Example Usage

Enter the number of threads to use for parallel sorting: 2
Specify the type of parallel sorting algorithm you want to use:
Parallel Quick Sort
Parallel Merge Sort
Parallel Radix Sort
2
Specify the type of data to sort:
Integer
Floating Point
String
3
Enter the number of elements to sort: 4
Enter the elements to be sorted:
banana
apple
orange
grape

# Results and Comparisons

The program will display the sorted data and the time taken for sorting. It also compares the performance of the parallel sorting algorithms with their sequential counterparts.

## Theoretical and Practical Demonstration of Complexity

The project provides theoretical and practical examples of the time complexity of each sorting algorithm, both sequentially and in parallel.

# Future of Sorting Data

The report discusses the future of data sorting, highlighting trends such as:

- Quantum Sorting Algorithms
- Machine Learning Integration
- GPU Acceleration
- Distributed Sorting

# Authors

Abdelali SAAID
Mouncef IKHOUBI

# Conclusion

This project demonstrates the efficiency gains achieved through parallel sorting algorithms. By dynamically specifying the number of threads and utilizing advanced synchronization mechanisms, we ensure fast and safe sorting of large datasets. This work provides a solid foundation for future exploration into more advanced and efficient data sorting techniques.

# Code Comments

The report includes detailed code comments explaining the environment configuration, thread creation, implementation of critical sections, active and passive waiting mechanisms, testing and debugging, and documentation.

Overall, this project provides a comprehensive analysis of parallel sorting algorithms, their implementation, and their performance compared to sequential sorting methods.