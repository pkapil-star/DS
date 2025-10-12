#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Global head pointer

// Function to insert node at end
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

// Function to display linked list
void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find and display the middle node
void findMiddle() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle node value: " << slow->data << endl;
}

// Function to show menu
void showMenu() {
    cout << "\n===== Singly Linked List Menu =====\n";
    cout << "1. Insert at End\n";
    cout << "2. Display List\n";
    cout << "3. Find Middle Node\n";
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
        displayList();
    }
    else if (choice == 3) {
        findMiddle();
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
