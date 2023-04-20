#pragma once
#include "SingleLinkedList.cpp"
template<class T>
class Queue {
private:
    SingleLinkedList<T>list;
public:
    void enqueue(T val);
    T dequeue();
    T first();
    bool isEmpty();
    int queueSize();
    void clear();
    void print();
//    void printReverse();
};




