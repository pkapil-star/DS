#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;  // Global head pointer

// Function to insert a node at the end (for testing purposes)
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Node inserted at end successfully.\n";
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    Node* temp = head;    // Temporarily store head
    head = head->next;    // Move head to next node
    cout << "Node with value " << temp->data << " deleted from beginning.\n";
    delete temp;          // Free memory
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

// Function to display menu
void showMenu() {
    cout << "\n===== Singly Linked List Menu =====\n";
    cout << "1. Insert at End (for setup)\n";
    cout << "2. Delete from Beginning\n";
    cout << "3. Display List\n";
    cout << "4. Exit\n";
}

// Function to handle user input (without switch)
void handleChoice(int choice) {
    int value;

    if (choice == 1) {
        cout << "Enter value to insert at end: ";
        cin >> value;
        insertAtEnd(value);
    }
    else if (choice == 2) {
        deleteFromBeginning();
    }
    else if (choice == 3) {
        displayList();
    }
    else if (choice == 4) {
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
