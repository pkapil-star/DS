#include <iostream>
#include <queue>
using namespace std;


class StackOneQ {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << q.front() << " popped" << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Top element: " << q.front() << endl;
        }
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        queue<int> temp = q;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
