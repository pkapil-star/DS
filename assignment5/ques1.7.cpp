#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Global head pointer

// Function to insert node at end (for creating sample list)
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

// Function to search for a node and display its position
void searchNode(int target) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int position = 1;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == target) {
            cout << "Node with value " << target
                 << " found at position " << position << " from head.\n";
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
        cout << "Node with value " << target << " not found in the list.\n";
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
    cout << "2. Search for Node and Display Position\n";
    cout << "3. Display List\n";
    cout << "4. Exit\n";
}

// Function to handle menu choice without switch-case
void handleChoice(int choice) {
    int value;

    if (choice == 1) {
        cout << "Enter value to insert at end: ";
        cin >> value;
        insertAtEnd(value);
    }
    else if (choice == 2) {
        cout << "Enter value to search: ";
        cin >> value;
        searchNode(value);
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
