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

// Function to count occurrences of a key
int countOccurrences(int key) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

// Function to delete all occurrences of a key
void deleteAllOccurrences(int key) {
    while (head != nullptr && head->data == key) { // Delete head nodes if matching
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr) return;

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

// Function to handle menu options
void handleChoice(int choice) {
    int value, key;

    if (choice == 1) {
        cout << "Enter value to insert at end: ";
        cin >> value;
        insertAtEnd(value);
    }
    else if (choice == 2) {
        cout << "Enter key to count occurrences and delete: ";
        cin >> key;
        int count = countOccurrences(key);
        cout << "Count of " << key << ": " << count << endl;
        deleteAllOccurrences(key);
        cout << "Updated Linked List: ";
        displayList();
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

// Function to display menu
void showMenu() {
    cout << "\n===== Singly Linked List Menu =====\n";
    cout << "1. Insert at End\n";
    cout << "2. Count and Delete All Occurrences of a Key\n";
    cout << "3. Display List\n";
    cout << "4. Exit\n";
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
