#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Global head pointer

// Function to insert node at end (for setup/testing)
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

// Function to delete a specific node by value
void deleteNodeByValue(int target) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    // If the node to be deleted is the head
    if (head->data == target) {
        Node* temp = head;
        head = head->next;
        cout << "Node with value " << target << " deleted successfully.\n";
        delete temp;
        return;
    }

    // Find the previous node of the target node
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != target)
        temp = temp->next;

    // If node not found
    if (temp->next == nullptr) {
        cout << "Node with value " << target << " not found in the list.\n";
        return;
    }

    // Delete the target node
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    cout << "Node with value " << target << " deleted successfully.\n";
    delete toDelete;
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
    cout << "2. Delete Specific Node (by Value)\n";
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
        cout << "Enter value of node to delete: ";
        cin >> value;
        deleteNodeByValue(value);
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
