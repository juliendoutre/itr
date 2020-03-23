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
void Fifo<T>::push() {}

template <typename T>
T Fifo<T>::pop()
{
    return nullptr;
}

template <typename T>
T Fifo<T>::pop(double timeout_ms)
{
    return nullptr;
}
