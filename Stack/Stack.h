#pragma once
#include "SingleLinkedList.cpp"
template<class T>
class Stack {
private:
    SingleLinkedList<T> list;
public:
    void push(T val);
    T pop();
    T top();
    bool isEmpty();
    int stackSize();
    void clear();
    void print();
};

