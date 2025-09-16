#include <iostream>
using namespace std;

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

// Check if empty
bool isEmpty() {
    return (front == -1);
}

// Check if full
bool isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Enqueue
void enqueue(int x) {
    if (isFull()) {
        cout << "Circular Queue is Full! Cannot insert " << x << endl;
    } else {
        if (front == -1) { // first element
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0; // wrap around
        } else {
            rear++;
        }
        cq[rear] = x;
        cout << x << " inserted into Circular Queue" << endl;
    }
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue is Empty! Nothing to delete." << endl;
    } else {
        cout << cq[front] << " removed from Circular Queue" << endl;
        if (front == rear) { // only one element
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0; // wrap around
        } else {
            front++;
        }
    }
}

// Peek
void peek() {
    if (isEmpty()) {
        cout << "Circular Queue is Empty!" << endl;
    } else {
        cout << "Front element: " << cq[front] << endl;
    }
}

// Display
void display() {
    if (isEmpty()) {
        cout << "Circular Queue is Empty!" << endl;
    } else {
        cout << "Circular Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << cq[i] << " ";
            }
        } else {
            for (int i = front; i < MAX; i++) {
                cout << cq[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << cq[i] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
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
            cout << (isEmpty() ? "Circular Queue is Empty" : "Circular Queue is NOT Empty") << endl;
        }
        else if (choice == 6) {
            cout << (isFull() ? "Circular Queue is Full" : "Circular Queue is NOT Full") << endl;
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
