#ifndef STACK_H
#define STACK_H
#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    T stackData[1000];
    int length;

public:
    Stack() : length(0) {}
    
    ~Stack() {}
    
    void operator << (T element)
    {
        if (length >= 1000) throw std::runtime_error("Stack overflow");
        
        // Сдвигаем все элементы вправо
        for (int i = length; i > 0; i--) {
            stackData[i] = stackData[i - 1];
        }
        
        // Помещаем новый элемент в начало
        stackData[0] = element;
        length++;
    }
    
    T operator >> (T &element)
    {
        if (length == 0) throw std::runtime_error("Stack underflow");
        
        element = stackData[0];
        
        // Сдвигаем все элементы влево
        for (int i = 0; i < length - 1; i++) {
            stackData[i] = stackData[i + 1];
        }
        length--;
        
        return element;
    }
    
    const T& operator [](int i) const
    {
        if (i < 0 || i >= length) throw std::runtime_error("Stack index out of bounds");
        return stackData[i];
    }
    
    T& operator [](int i)
    {
        if (i < 0 || i >= length) throw std::runtime_error("Stack index out of bounds");
        return stackData[i];
    }
    
    size_t size() const
    {
        return length;
    }
    
    bool operator == (const Stack<T> &otherStack) const
    {
        if (length != otherStack.length) return false;
        for (int i = 0; i < length; i++) {
            if (!(stackData[i] == otherStack.stackData[i])) return false;
        }
        return true;
    }
    
    bool operator < (const Stack<T> &otherStack) const
    {
        return length < otherStack.length;
    }
    
    Stack<T>& operator = (const Stack<T> &otherStack)
    {
        if (this != &otherStack) {
            length = otherStack.length;
            for (int i = 0; i < length; i++) {
                stackData[i] = otherStack.stackData[i];
            }
        }
        return *this;
    }
};

#endif