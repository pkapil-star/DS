#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if empty
bool isEmpty() {
    return (front == -1);
}

// Check if full
bool isFull() {
    return (rear == MAX - 1);
}

// Enqueue
void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is Full! Cannot insert " << x << endl;
    } else {
        if (front == -1) front = 0;  // first element
        rear++;
        queue[rear] = x;
        cout << x << " inserted into queue" << endl;
    }
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty! Nothing to delete." << endl;
    } else {
        cout << queue[front] << " removed from queue" << endl;
        if (front == rear) { // queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }
}

// Peek
void peek() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}

// Display
void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            display();
        }
        else if (choice == 5) {
            cout << (isEmpty() ? "Queue is Empty" : "Queue is NOT Empty") << endl;
        }
        else if (choice == 6) {
            cout << (isFull() ? "Queue is Full" : "Queue is NOT Full") << endl;
        }
        else if (choice == 0) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
