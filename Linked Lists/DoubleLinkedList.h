#pragma once
#include <bits/stdc++.h>
template<class T>
class Node{
public:
    T value;
    Node* next = NULL;
    Node* prev = NULL;
};

template<class T>
class DoubleLinkedList{
private:
    int size = 0;
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
public:
    void insertAtHead(T val);
    void insertAtTail(T val);
    void insertAt(T val, int index);
    void insertAfter(Node<T>* prev,T val);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T val, int index);
    bool isExist(T val);
    bool isItemAtEqual(T val, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    void reverse();
    bool isEmpty();
    int doubleLinkedListSize();
    void clear();
    void forwardTraversal();
    void backwardTraversal();
};

