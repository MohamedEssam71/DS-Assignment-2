#pragma once
#include "DoubleLinkedList.h"

template<class T>
void DoubleLinkedList<T>::insertAtHead(T val) {
    Node<T>* t = new Node<T>();
    t->value = val;
    if(head == NULL){
        t->next = NULL;
        t->prev = NULL;
        head = t;
        tail = t;
    }
    else{
        t->next = head;
        t->prev = NULL;
        head->prev = t;
        head = t;
    }
    size++;
}


template<class T>
void DoubleLinkedList<T>::insertAtTail(T val) {
    Node<T>* t = new Node<T>();
    t->value = val;
    if(head == NULL){
        t->next = NULL;
        t->prev = NULL;
        head = t;
        tail = t;
    }
    else{
        t->next = NULL;
        t->prev = tail;
        tail->next = t;
        tail = t;
    }
    size++;
}


template<class T>
void DoubleLinkedList<T>::insertAt(T val, int index) {
    try {
        if ((index >= size) || (index < 0)) {
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T> *t = new Node<T>();
        t->value = val;
        if (!index) {
            insertAtHead(val);
        } else if (index == size - 1) {
            insertAtTail(val);
        } else {
            int idx = 0;
            Node<T> *p = head;
            while (p != NULL && idx != index) {
                p = p->next;
                idx++;
            }
            t->next = p->next;
            p->next->prev = t;
            p->next = t;
            t->prev = p;
            size++;
        }
    }
    catch(std::invalid_argument & err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }

}


template<class T>
void DoubleLinkedList<T>::insertAfter(Node<T> *prev, T val) {
    Node<T>* t = new Node<T>();
    t->value = val;
    prev->next = t;
    t->prev = prev;
    size++;
}


template<class T>
void DoubleLinkedList<T>::removeAtHead() {
    if(head == NULL) return;
    if(size == 1){
        delete head;
        head = tail = NULL;
    }
    else {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    size--;
}


template<class T>
void DoubleLinkedList<T>::removeAtTail() {
    if(size == 1){
        delete head;
        tail = head = NULL;
        size = 0;
        return;
    }
    tail = tail->prev;
    delete tail->next;
    tail->next = NULL;
    size--;
    if(!size){
        delete head;
        head = tail = NULL;
    }
}


template<class T>
void DoubleLinkedList<T>::removeAt(int index) {
    try {
        if (index >= size || index < 0)
            throw std::invalid_argument("Index is Not Available");
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtTail();
        } else {
            Node<T> *p = head;
            int idx = 0;
            while (p != NULL && idx != index) {
                p = p->next;
                idx++;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
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
T DoubleLinkedList<T>::retrieveAt(int index) {
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
void DoubleLinkedList<T>::replaceAt(T val, int index) {
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
bool DoubleLinkedList<T>::isExist(T val) {
    Node<T>* p = head;
    while(p != NULL){
        if(p->value == val)
            return true;
        p = p->next;
    }
    return false;
}


template<class T>
bool DoubleLinkedList<T>::isItemAtEqual(T val, int index) {
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
void DoubleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    try {
        if (firstItemIdx >= size || firstItemIdx < 0 || secondItemIdx >= size || secondItemIdx < 0 ||
            firstItemIdx > secondItemIdx) {
            throw std::invalid_argument("Index is Not Available");
        }
        if (firstItemIdx == secondItemIdx) return;
        Node<T> *p, *q, *rightP, *leftQ;
        p = q = head;
        rightP = leftQ = NULL;
        rightP = p->next;
        int idx1 = 0;
        while (p != NULL && idx1 != firstItemIdx) {
            p = p->next;
            idx1++;
            rightP = p->next;
        }
        int idx2 = 0;
        while (q != NULL && idx2 != secondItemIdx) {
            leftQ = q;
            q = q->next;
            idx2++;
        }
        //swap Head Tail
        if (firstItemIdx == 0 && secondItemIdx == size - 1) {
            q->prev->next = p;
            p->next->prev = q;
            q->next = p->next;
            p->prev = q->prev;
            p->next = q->prev = NULL;
            head = q;
            tail = p;
            return;
        }
        // Swap Neither tail nor head
        if (firstItemIdx != 0 && secondItemIdx != size - 1) {
            // if space is found between them
            if (firstItemIdx != secondItemIdx - 1) {
                p->prev->next = q;
                q->prev->next = p;
                q->prev = p->prev;
                p->prev = leftQ;
                p->next->prev = q;
                q->next->prev = p;
                p->next = q->next;
                q->next = rightP;
            }
                // if no space is found between them
            else {
                p->prev->next = q;
                q->prev = p->prev;
                q->next->prev = p;
                Node<T> *temp = q->next;
                q->next = p;
                p->prev = q;
                p->next = temp;
            }
        } else {   //Swap Head with any index
            if (firstItemIdx == 0 && secondItemIdx != size - 1) {
                if (firstItemIdx != secondItemIdx - 1) {
                    q->prev->next = p;
                    p->prev = leftQ;
                    q->prev = NULL;
                    p->next->prev = q;
                    q->next->prev = p;
                    p->next = q->next;
                    q->next = rightP;
                    head = q;
                } else {
                    p->next = q->next;
                    q->next->prev = p;
                    q->next = p;
                    q->prev = NULL;
                    p->prev = q;
                    head = q;
                }
            } else {   //Swap tail with any Index
                if (firstItemIdx != secondItemIdx - 1) {
                    p->prev->next = q;
                    q->prev->next = p;
                    q->prev = p->prev;
                    p->prev = leftQ;
                    p->next->prev = q;
                    q->next = p->next;
                    p->next = NULL;
                    tail = p;
                } else {
                    q->next = p;
                    q->prev = p->prev;
                    p->prev->next = q;
                    p->prev = q;
                    p->next = NULL;
                    tail = p;
                }
            }
        }
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
void DoubleLinkedList<T>::reverse() {
    Node<T>* p,*q;
    p = head;
    q = NULL;
    tail = head;
    // Until before p == tail
    while(p->next!=NULL){
        q = p;
        p = p->next;
        q->next = p->prev->prev;
        q->prev = p;
    }
    // reverse tail;
    p->prev = NULL;
    p->next = q;
    head = p;

}

template<class T>
bool DoubleLinkedList<T>::isEmpty() {
    return size == 0;
}


template<class T>
int DoubleLinkedList<T>::doubleLinkedListSize() {
    return size;
}


template<class T>
void DoubleLinkedList<T>::clear() {
    if(head == NULL) return;
    Node<T>* p = head;
    while(p->next != NULL){
        p = p->next;
        delete p->prev;
        p->prev = NULL;
    }
    delete p;
    head = tail = NULL;
    size = 0;
}


template<class T>
void DoubleLinkedList<T>::forwardTraversal() {
    Node<T>* p = head;
    while(p != NULL){
        std::cout << p->value << " ";
        p = p->next;
        if(p == NULL)
            std::cout << std::endl;
    }
}


template<class T>
void DoubleLinkedList<T>::backwardTraversal() {
    Node<T>* p = tail;
    while(p != NULL){
        std::cout << p->value << " ";
        p = p->prev;
        if(p == NULL){
            std::cout << std::endl;
        }
    }
}

