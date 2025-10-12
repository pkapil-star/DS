#include <iostream>
#include <cstdlib> // for exit()
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Global head pointer

// Function to insert a new node at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    newNode->data = value;
    newNode->next = head;  // Point new node to the current head
    head = newNode;        // Move head to point to the new node
    cout << "Node inserted at the beginning successfully.\n";
}

// Function to display the linked list
void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to show menu
void showMenu() {
    cout << "\n===== Singly Linked List Menu =====\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Display List\n";
    cout << "3. Exit\n";
}

// Function to handle user choice
void handleChoice(int choice) {
    int value;

    if (choice == 1) {
        cout << "Enter value to insert: ";
        cin >> value;
        insertAtBeginning(value);
    }
    else if (choice == 2) {
        displayList();
    }
    else if (choice == 3) {
        cout << "Exiting program...\n";
        exit(0);
    }
    else {
        cout << "Invalid choice! Please try again.\n";
    }
}


int main() {
    int choice;
    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        handleChoice(choice);
    }
    return 0;
}
