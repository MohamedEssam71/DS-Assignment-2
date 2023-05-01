#include "Queue.h"
template<class T>
void Queue<T>::enqueue(T val) {
    list.insertAtTail(val);
}

template<class T>
T Queue<T>::dequeue() {
    if(list.getHead() == NULL){
        std::cout << "Queue is Empty Can't Pop" << std::endl;
        exit(0);
    }
    T value = list.removeAtHead();
    return value;
}


template<class T>
T Queue<T>::first() {
    return list.getHead()->value;
}

template<class T>
bool Queue<T>::isEmpty() {
    return list.getSize() == 0;
}

template<class T>
int Queue<T>::queueSize() {
    return list.getSize();
}

template<class T>
void Queue<T>::clear() {
    list.clear();
}

template<class T>
void Queue<T>::print() {
    list.print();
}

//template<class T>
//void Queue<T>::printReverse() {
//    list.backwardTraversal();
//}