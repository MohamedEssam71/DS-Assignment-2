#include <iostream>
#include "Queue.cpp"
using namespace std;

void reverseQueue(Queue<int>&q){
    if(!q.queueSize()) return;
    int top = q.dequeue();
    reverseQueue(q);
    q.enqueue(top);
}

void generateBinaryNumbers(int n){
    Queue<int>q;
    for(int i = 1; i <= n; ++i) {
        int num = i;
        while(num) {
            q.enqueue(num % 2);
            num /= 2;
        }
        reverseQueue(q);
        q.print();
        q.clear();
    }
}

void sortQueue(Queue<int>q){
    Queue<int>q1, q2, sortedQ;
    while(!q.isEmpty()) {
        while (!q.isEmpty()) {
            int val = q.dequeue();
            if (!q1.isEmpty()) {
                if (q1.first() <= val) {
                    q1.enqueue(val);
                    continue;
                } else {
                    while(!q1.isEmpty()){
                        q.enqueue(q1.dequeue());
                    }
                    q1.enqueue(val);
                }
            }
            else q1.enqueue(val);
        }
        sortedQ.enqueue(q1.dequeue());
        while(!q1.isEmpty()){
            q.enqueue(q1.dequeue());
        }
    }
    sortedQ.print();
}


int main() {
//    generateBinaryNumbers(5);

//    Queue<int> q;
//    q.enqueue(9);
//    q.enqueue(2);
//    q.enqueue(3);
//    q.enqueue(1);
//    sortQueue(q);
//    q.print();
//    q.clear();
//    std::cout << q.isEmpty();
//    q.print();
}
