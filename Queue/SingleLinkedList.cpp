#pragma once
#include "SingleLinkedList.h"
template<class T>
void SingleLinkedList<T>::insertAtHead(T val) {
    Node<T>* t = new Node<T>();
    t->value = val;

    if(head == NULL){
        t->next = NULL;
        head = t;
        tail = t;
    }
    else{
        t->next = head;
        head = t;
    }
    size++;
}


template<class T>
void SingleLinkedList<T>::insertAtTail(T val) {
    Node<T>* t = new Node<T>();
    t->value = val;
    if(head == NULL){
        head = t;
        tail = t;
    }
    else{
        tail->next = t;
        tail = t;
    }
    t->next = NULL;
    size++;
}


template<class T>
void SingleLinkedList<T>::insertAt(T val, int index) {
    try{
        if((index >= size) || (index < 0)){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* t = new Node<T>();
        t->value = val;
        if(!index){
            insertAtHead(val);
        }
        else if(index == size-1){
            insertAtTail(val);
        }
        else{
            int idx = 0;
            Node<T>* p = head;
            Node<T>* q = NULL;
            while(p != NULL){
                if(idx == index) break;
                q = p;
                p = p->next;
                idx++;
            }
            q->next = t;
            t->next = p;
            size++;
        }
    }catch(std::invalid_argument & err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }

}


template<class T>
T SingleLinkedList<T>::removeAtHead() {
    T val;
    if(size == 1){
        val = head->value;
        delete head;
        head = tail = NULL;
    }
    else {
        Node<T> *temp = head;
        val = head->value;
        head = head->next;
        delete temp;
        temp = NULL;
    }
    size--;
    return val;
}


template<class T>
void SingleLinkedList<T>::removeAtTail() {
    if(head->next == NULL){
        delete head;
        delete tail;
        tail = head = NULL;
        size = 0;
        return;
    }
    Node<T>* p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    delete tail;
    tail = NULL;
    tail = p;
    p->next = NULL;
    size--;
    if(!size){
        delete head;
        head = tail = NULL;
    }
}


template<class T>
void SingleLinkedList<T>::removeAt(int index) {
    try {
        if (index >= size || index < 0)
            throw std::invalid_argument("Index is Not Available");
        if (index == 0) {
            removeAtHead();
        }
        else if(index == size-1){
            removeAtTail();
        }
        else {
            Node<T> *p = head;
            Node<T> *q = NULL;
            int idx = 0;
            while (p != NULL && idx != index) {
                q = p;
                p = p->next;
                idx++;
            }
            q->next = p->next;
            delete p;
            p = NULL;
            size--;
        }

    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
T SingleLinkedList<T>::retrieveAt(int index) {
    try{
        if(index >= size || index < 0){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* p = head;
        int idx = 0;
        while(p != NULL && idx != index){
            p = p->next;
            idx++;
        }
        return p->value;
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
void SingleLinkedList<T>::replaceAt(T val, int index) {
    try{
        if(index >= size || index < 0){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* p = head;
        int idx = 0;
        while(p != NULL && idx != index){
            p = p->next;
            idx++;
        }
        p->value = val;
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
bool SingleLinkedList<T>::isExist(T val) {
    Node<T>* p = head;
    while(p != NULL){
        if(p->value == val)
            return true;
        p = p->next;
    }
    return false;
}


template<class T>
bool SingleLinkedList<T>::isItemAtEqual(T val, int index) {
    try{
        if(index >= size || index < 0){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* p = head;
        int idx = 0;
        while(p != NULL && idx != index){
            p = p->next;
            idx++;
        }
        return p->value == val;
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    try {
        if (firstItemIdx >= size || firstItemIdx < 0 || secondItemIdx >= size || secondItemIdx < 0 || firstItemIdx > secondItemIdx) {
            throw std::invalid_argument("Index is Not Available");
        }
        if(firstItemIdx == secondItemIdx) return;

        Node<T> *p, *q, *leftP, *leftQ, *rightQ;
        p = q = head;
        leftP = leftQ = rightQ = NULL;
        int idx1 = 0;
        while (p != NULL && idx1 != firstItemIdx) {
            leftP = p;
            p = p->next;
            idx1++;
        }
        int idx2 = 0;
        while (q != NULL && idx2 != secondItemIdx) {
            leftQ = q;
            q = q->next;
            rightQ = q->next;
            idx2++;
        }

        if(firstItemIdx == secondItemIdx-1){
            if(firstItemIdx != 0) leftP->next = q;
            p->next = q->next;
            q->next = p;
            if(secondItemIdx == size-1) tail = p;
            if(firstItemIdx == 0) head = q;
        }
        else if(firstItemIdx == 0 && secondItemIdx == size-1){
            q->next = p->next;
            p->next = NULL;
            leftQ->next = p;
            tail = p;
            head = q;
        }
        else if(firstItemIdx == 0){
            leftQ->next = p;
            q->next = p->next;
            p->next = rightQ;
            head = q;
        }
        else if(secondItemIdx == size - 1){
            q->next = p->next;
            p->next = NULL;
            leftQ->next = p;
            leftP->next = q;
            tail = p;
        }
        else{
            leftP->next = q;
            q->next = p->next;
            p->next = rightQ;
            leftQ->next = p;
        }

    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
bool SingleLinkedList<T>::isEmpty() const {
    return size == 0;
}


template<class T>
int SingleLinkedList<T>::linkedListSize() const {
    return size;
}


template<class T>
void SingleLinkedList<T>::clear() {
    if(head == NULL) return;
    Node<T>* p = head;
    Node<T>* temp = NULL;
    while(p != NULL){
        temp = p;
        p = p->next;
        delete temp;
        temp = NULL;
    }
    head = NULL;
    tail = NULL;

    size = 0;
}


template<class T>
void SingleLinkedList<T>::print() {
    Node<T>* p = head;
    while(p != NULL){
        std::cout << p->value << " ";
        p = p->next;
        if(p == NULL)
            std::cout << std::endl;
    }
}


template<class T>
void SingleLinkedList<T>::create(T *arr, int n) {
    head = new Node<T>();
    head->value = arr[0];
    tail = head;
    tail->next = head->next = NULL;
    for(int i = 1; i < n; ++i){
        Node<T>* t = new Node<T>();
        t->value = arr[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
    if(head == NULL){

    }
}


template<class T>
int SingleLinkedList<T>::getSize() const {
    return size;
}


template<class T>
void SingleLinkedList<T>::setSize(int size) {
    SingleLinkedList::size = size;
}


template<class T>
Node<T> *SingleLinkedList<T>::getHead() const {
    return head;
}


template<class T>
void SingleLinkedList<T>::setHead(Node<T> *head) {
    SingleLinkedList::head = head;
}


template<class T>
Node<T> *SingleLinkedList<T>::getTail() const {
    return tail;
}


template<class T>
void SingleLinkedList<T>::setTail(Node<T> *tail) {
    SingleLinkedList::tail = tail;
}




