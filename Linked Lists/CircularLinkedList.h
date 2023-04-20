#pragma once
#include <bits/stdc++.h>
template<class T>
class Node{
public:
    T value;
    Node* next = NULL;
};
template<class T>
class CircularLinkedList{
private:
    int size = 0;
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
public:
    void insertAtHead(T val);
    void insertAtTail(T val);
    void insertAt(T val, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T val, int index);
    bool isExist(T val);
    bool isItemAtEqual(T val, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty() const;
    int linkedListSize() const;
    void clear();
    void print();
};



