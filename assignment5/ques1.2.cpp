#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;  // Global head pointer

// Function to insert a node at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    newNode->data = value;
    newNode->next = nullptr;

    // If the list is empty, new node becomes the head
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link last node to new node
    }

    cout << "Node inserted at the end successfully.\n";
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
    cout << "1. Insert at End\n";
    cout << "2. Display List\n";
    cout << "3. Exit\n";
}

// Function to handle user choices
void handleChoice(int choice) {
    int value;
    if (choice == 1) {
        cout << "Enter value to insert at end: ";
        cin >> value;
        insertAtEnd(value);
    }
    else if (choice == 2) {
        displayList();
    }
    else if (choice == 3) {
        cout << "Exiting program...\n";
        exit(0);
    }
    else {
        cout << "Invalid choice! Try again.\n";
    }
}

// Main function
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
