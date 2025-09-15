#include <iostream>
using namespace std;

struct Stack {
    int arr[100]; // fixed array
    int top;
    int size;
};

// Push operation
void push(Stack& s, int val) {
    if (s.top >= s.size - 1)
        cout << "Stack Overflow" << endl;
    else {
        s.top++;
        s.arr[s.top] = val;
        cout << "Pushed " << val << endl;
    }
}

// Display operation
void display(Stack& s) {
    if (s.top == -1)
        cout << "Stack is empty" << endl;
    else {
        cout << "Stack elements are: ";
        for (int i = s.top; i >= 0; i--)
            cout << s.arr[i] << " ";
        cout << endl;
    }
}

// Pop operation
void pop(Stack& s) {
    if (s.top == -1)
        cout << "Stack Underflow" << endl;
    else {
        cout << "Popped " << s.arr[s.top] << endl;
        s.top--;
    }
}

int main() {
    Stack s;
    s.top = -1;
    s.size = 100; // Stack size

    int choice, val;
    while (true) {
        cout << "\n==== Stack Menu ====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> val;
            push(s, val);
        }
        else if (choice == 2) {
            pop(s);
        }
        else if (choice == 3) {
            display(s);
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
