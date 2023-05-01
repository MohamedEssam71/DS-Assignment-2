#include <iostream>
#include "SingleLinkedList.cpp"
// #include "CircularLinkedList.cpp"
// #include "DoubleLinkedList.cpp"

using namespace std;

void combineNodesZero(SingleLinkedList<int> list)
{
    SingleLinkedList<int> newList;
    Node<int> *p = list.getHead();
    int sum = 0;
    while (p != NULL)
    {
        sum += p->value;
        if (p->value == 0)
        {
            if (sum != 0)
            {
                newList.insertAtTail(sum);
                sum = 0;
            }
        }
        p = p->next;
    }
    newList.print();
}

Node<int> *merge(Node<int> *p, Node<int> *q)
{
    Node<int> *third = new Node<int>();
    Node<int> *last = new Node<int>();

    if (p->value <= q->value)
    {
        third = last = p;
        p = p->next;
    }
    else
    {
        third = last = q;
        q = q->next;
    }
    last->next = NULL;

    while (p != NULL && q != NULL)
    {
        if (p->value <= q->value)
        {
            last->next = p;
            last = p;
            p = p->next;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
        }
        last->next = NULL;
    }
    if (p)
        last->next = p;
    else
        last->next = q;
    return third;
}

Node<int> *mergeLists(Node<int> *arr[], int k)
{
    int j = k - 1;
    while (j > 0)
    {
        arr[0] = merge(arr[0], arr[j]);
        --j;
    }
    return arr[0];
}

int main()
{
    SingleLinkedList<int> list, list2, list3;

    int arr[4] = {1, 3, 5, 7};
    list.create(arr, 4);
    list.print();

    int arr2[4] = {2, 4, 6, 8};
    list2.create(arr2, 4);
    list2.print();

    int arr3[3] = {0, 9, 10};
    list3.create(arr3, 3);
    list3.print();

    Node<int> *heads[3] = {list.getHead(), list2.getHead(), list3.getHead()};

    Node<int> *third = mergeLists(heads, 3);
    while (third != NULL)
    {
        cout << third->value << " ";
        third = third->next;
        if (third == NULL)
            cout << endl;
    }
}

//    DoubleLinkedList<int> list;
//    list.insertAtHead(4);
//    list.insertAtHead(5);
//    list.insertAtHead(6);
//    list.insertAtHead(7);
//    list.insertAtTail(9);
//    list.insertAtTail(10);
//    list.print();
//    list.clear();
//    list.print();
//    cout << list.linkedListSize() << endl;
//    list.forwardTraversal();
//    list.reverse();
//    list.forwardTraversal();
//    list.removeAt(3);
//    list.backwardTraversal();
//    list.swap(0,4);
//    list.backwardTraversal();
//    list.removeAtHead();
//
//    list.clear();
//    list.clear();
//    cout << list.retrieveAt(3) << endl;
//    list.replaceAt(10,4);
//    list.forwardTraversal();
//
//    list.insertAt(11,6);
//
//    list.forwardTraversal();
//    cout << list.retrieveAt(7) << endl;
//    list.replaceAt(20,-1);
//    list.removeAt(0);
//    list.forwardTraversal();
//    cout << list.doubleLinkedListSize();