#ifndef THREADING_H
#define THREADING_H

#include <thread>
#include <future>
#include <atomic>
#include <mutex>

int max_threads = std::thread::hardware_concurrency();
std::atomic<int> current_threads{0};

void set_max_threads(int num_threads) {
    max_threads = num_threads;
}

int get_thread_count() {
    return current_threads.load();
}

template <typename Function, typename... Args>
auto async_execute(Function&& func, Args&&... args) -> std::future<decltype(func(args...))> {
    current_threads++;
    auto future = std::async(std::launch::async, std::forward<Function>(func), std::forward<Args>(args)...);
    current_threads--;
    return future;
}

// Mutual exclusion mechanisms
extern std::mutex mutex;
extern std::atomic_flag spinlock;
void enter_critical_section();
void exit_critical_section();
void enter_critical_section_mutex();
void exit_critical_section_mutex();


#endif // THREADING_H
