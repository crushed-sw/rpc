#ifndef __LOCK_QUEUE_HPP
#define __LOCK_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class LockQueue {
public:
    void push(const T& t);
    void push(T&& t);

    std::string pop();
    
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cond_;
};

template <typename T>
void LockQueue<T>::push(const T& t) {
    std::lock_guard<std::mutex> locker(mutex_);
    queue_.emplace(t);
    cond_.notify_all();
}

template <typename T>
void LockQueue<T>::push(T&& t) {
    std::lock_guard<std::mutex> locker(mutex_);
    queue_.emplace(std::forward<T>(t));
    cond_.notify_all();
}

template <typename T>
std::string LockQueue<T>::pop() {
    std::unique_lock<std::mutex> locker(mutex_);
    cond_.wait(locker, [&](){ return !queue_.empty(); });

    T data = queue_.front();
    queue_.pop();

    return data;
}

#endif //__LOCK_QUEUE_HPP
