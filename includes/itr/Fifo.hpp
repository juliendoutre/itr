#pragma once
#include "Mutex.hpp"
#include <queue>
#include <exception>

template <typename T>
class Fifo
{
private:
    Mutex mutex;
    std::queue<T> elements;

public:
    class EmptyException;

public:
    void push(T element);
    T pop();
    T pop(double timeout_ms);
};

template <typename T>
class Fifo<T>::EmptyException : public std::exception
{
    const char *what() const throw()
    {
        return "The fifo is empty";
    }
};

template <typename T>
void Fifo<T>::push(T element)
{
    Mutex::Lock lock = Mutex::Lock(this->mutex);
    this->elements.push_back(element);
    lock.notify();
}

template <typename T>
T Fifo<T>::pop()
{
    Mutex::Lock lock = Mutex::Lock(this->mutex);
    while (this->elements.size() == 0)
    {
        lock.wait();
    }

    return this->elements.pop_front();
}

template <typename T>
T Fifo<T>::pop(double timeout_ms)
{
    Mutex::Lock lock = Mutex::Lock(this->mutex, timeout_ms);
    if (!lock.wait(timeout_ms) || this->elements.size() == 0)
    {
        throw Fifo<T>::EmptyException()
    }

    return this->elements.pop_front();
}
