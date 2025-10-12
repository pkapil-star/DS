#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Global head pointer

// Function to insert node at the end (for easier testing)
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
}

// Function to insert a node after a specific value
void insertAfterValue(int target, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node with value " << target << " not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node " << value << " inserted after " << target << " successfully.\n";
}

// Function to insert a node before a specific value
void insertBeforeValue(int target, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // If inserting before head
    if (head->data == target) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Node " << value << " inserted before " << target << " successfully.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != target)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node with value " << target << " not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node " << value << " inserted before " << target << " successfully.\n";
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
    cout << "1. Insert at End (for setup)\n";
    cout << "2. Insert AFTER a specific node\n";
    cout << "3. Insert BEFORE a specific node\n";
    cout << "4. Display List\n";
    cout << "5. Exit\n";
}

// Function to handle user choice
void handleChoice(int choice) {
    int value, target;

    if (choice == 1) {
        cout << "Enter value to insert at end: ";
        cin >> value;
        insertAtEnd(value);
    }
    else if (choice == 2) {
        cout << "Enter target node value (after which to insert): ";
        cin >> target;
        cout << "Enter new node value to insert: ";
        cin >> value;
        insertAfterValue(target, value);
    }
    else if (choice == 3) {
        cout << "Enter target node value (before which to insert): ";
        cin >> target;
        cout << "Enter new node value to insert: ";
        cin >> value;
        insertBeforeValue(target, value);
    }
    else if (choice == 4) {
        displayList();
    }
    else if (choice == 5) {
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
