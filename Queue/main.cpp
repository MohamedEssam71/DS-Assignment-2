#include <iostream>
#include <bits/stdc++.h>
#include "Queue.cpp"
using namespace std;


void generateBinaryNumbers(int n){
    Queue<string>q;
    q.enqueue("1");
    for(int i = 1; i <= n; ++i) {
        string s = q.dequeue();
        cout << s << " ";
        q.enqueue(s + "0");
        q.enqueue(s + "1");
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
//   generateBinaryNumbers(5);

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
