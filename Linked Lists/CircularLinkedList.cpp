#include "CircularLinkedList.h"

template<class T>
void CircularLinkedList<T>::insertAtHead(T val) {
    Node<T>* t = new Node<T>();
    t->value = val;
    if(head == NULL){
        t->next = NULL;
        head = t;
        tail = t;
        tail->next = head;
    }
    else{
        t->next = head;
        head = t;
        tail->next = head;
    }
    size++;
}


template<class T>
void CircularLinkedList<T>::insertAtTail(T val) {
    Node<T>* t = new Node<T>();
    t->value = val;
    if(head == NULL){
        t->next = NULL;
        head = t;
        tail = t;
        tail->next = head;
    }
    else{
        tail->next = t;
        tail = t;
        tail->next = head;
    }
    t->next = head;
    size++;
}


template<class T>
void CircularLinkedList<T>::insertAt(T val, int index) {
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
            do{
                if(idx == index) break;
                q = p;
                p = p->next;
                idx++;
            }while(p != head);
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
void CircularLinkedList<T>::removeAtHead() {
    if(head == NULL) return;
    if(size == 1){
        delete head;
        head = tail = NULL;
    }
    else {
        Node<T> *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        temp = NULL;
    }
    size--;
}


template<class T>
void CircularLinkedList<T>::removeAtTail() {
    if(head->next == NULL){
        delete head;
        delete tail;
        tail = head = NULL;
        size = 0;
        return;
    }
    Node<T>* p = head;
    while(p->next->next != head){
        p = p->next;
    }
    delete tail;
    tail = NULL;
    tail = p;
    p->next = head;
    size--;
    if(!size){
        head = tail = NULL;
    }
}


template<class T>
void CircularLinkedList<T>::removeAt(int index) {
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
            do{
                q = p;
                p = p->next;
                idx++;
            }while (p != head && idx != index);
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
T CircularLinkedList<T>::retrieveAt(int index) {
    try{
        if(index >= size || index < 0){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* p = head;
        int idx = 0;
        do{
            p = p->next;
            idx++;
        }while(p != head && idx != index);

        return p->value;
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
void CircularLinkedList<T>::replaceAt(T val, int index) {
    try{
        if(index >= size || index < 0){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* p = head;
        int idx = 0;
        do{
            p = p->next;
            idx++;
        }while(p != head && idx != index);

        p->value = val;
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
bool CircularLinkedList<T>::isExist(T val) {
    Node<T>* p = head;
    do{
        if(p->value == val)
            return true;
        p = p->next;
    }while(p != head);

    return false;
}


template<class T>
bool CircularLinkedList<T>::isItemAtEqual(T val, int index) {
    try{
        if(index >= size || index < 0){
            throw std::invalid_argument("Index is Not Available");
        }
        Node<T>* p = head;
        int idx = 0;
        do{
            p = p->next;
            idx++;
        }while(p != head && idx != index);
        return p->value == val;
    }
    catch(std::invalid_argument const &err){
        std::cerr << err.what() << std::endl;
        exit(0);
    }
}


template<class T>
void CircularLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    try {
        if (firstItemIdx >= size || firstItemIdx < 0 || secondItemIdx >= size || secondItemIdx < 0 || firstItemIdx > secondItemIdx) {
            throw std::invalid_argument("Index is Not Available");
        }
        if(firstItemIdx == secondItemIdx) return;

        Node<T> *p, *q, *leftP, *leftQ, *rightQ;
        p = q = head;
        leftP = leftQ = rightQ = NULL;
        int idx1 = 0;

        if(firstItemIdx != 0) {
            do {
                leftP = p;
                p = p->next;
                idx1++;
            } while (p != head && idx1 != firstItemIdx);
        }

        int idx2 = 0;
        do{
            leftQ = q;
            q = q->next;
            rightQ = q->next;
            idx2++;
        }while (q != head && idx2 != secondItemIdx);

        if(firstItemIdx == secondItemIdx-1){
            if(firstItemIdx != 0) leftP->next = q;
            p->next = q->next;
            q->next = p;
            if(secondItemIdx == size-1) tail = p;
            if(firstItemIdx == 0) {
                head = q;
                tail->next = head;
            }
        }
        else if(firstItemIdx == 0 && secondItemIdx == size-1){
            q->next = p->next;
            p->next = head;
            leftQ->next = p;
            tail = p;
            head = q;
            tail->next = head;
        }
        else if(firstItemIdx == 0){
            leftQ->next = p;
            q->next = p->next;
            p->next = rightQ;
            head = q;
            tail->next = head;
        }
        else if(secondItemIdx == size - 1){
            q->next = p->next;
            p->next = head;
            leftQ->next = p;
            leftP->next = q;
            tail = p;
            p->next = head;
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
bool CircularLinkedList<T>::isEmpty() const {
    return size == 0;
}


template<class T>
int CircularLinkedList<T>::linkedListSize() const {
    return size;
}


template<class T>
void CircularLinkedList<T>::clear() {
    if(head == NULL) return;
    Node<T>* p = head;
    Node<T>* temp = NULL;
    do{
        temp = p;
        p = p->next;
        delete temp;
        temp = NULL;
    }while(p != head);

    head = NULL;
    tail = NULL;

    size = 0;
}


template<class T>
void CircularLinkedList<T>::print() {
    if(head == NULL) return;
    Node<T>* p = head;
    do{
        std::cout << p->value << " ";
        p = p->next;
        if(p == head)
            std::cout << std::endl;
    }while(p != head);

}
