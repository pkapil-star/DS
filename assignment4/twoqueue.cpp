#include <iostream>
#include <queue>
using namespace std;

class StackTwoQ {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << q1.front() << " popped" << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Top element: " << q1.front() << endl;
        }
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
