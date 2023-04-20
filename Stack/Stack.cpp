#pragma once
#include "Stack.h"
template<class T>
void Stack<T>::push(T val) {
    list.insertAtHead(val);
}

template<class T>
T Stack<T>::pop() {
    T value = list.removeAtHead();
    if(!(~value)){
        std::cout << "Stack is Empty Can't Pop" << std::endl;
        exit(0);
    }
    return value;
}

template<class T>
T Stack<T>::top() {
    return list.getHead()->value;
}

template<class T>
bool Stack<T>::isEmpty() {
    return list.getSize() == 0;
}

template<class T>
int Stack<T>::stackSize() {
    return list.getSize();
}

template<class T>
void Stack<T>::clear() {
    list.clear();
}

template<class T>
void Stack<T>::print() {
    list.print();
}
