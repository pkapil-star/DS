#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularList {
private:
    Node* head;
public:
    CircularList() {
        head = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }

    bool insertAfterValue(int target, int value) {
        if (head == nullptr) return false;
        Node* current = head;
        do {
            if (current->data == target) {
                Node* newNode = new Node(value);
                newNode->next = current->next;
                current->next = newNode;
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    bool insertBeforeValue(int target, int value) {
        if (head == nullptr) return false;
        if (head->data == target) {
            insertAtBeginning(value);
            return true;
        }
        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == target) {
                Node* newNode = new Node(value);
                newNode->next = current;
                prev->next = newNode;
                return true;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        return false;
    }

    bool deleteByValue(int value) {
        if (head == nullptr) return false;
        Node* current = head;
        Node* prev = nullptr;
        if (head->next == head && head->data == value) {
            delete head;
            head = nullptr;
            return true;
        }
        do {
            if (current->data == value) {
                if (current == head) {
                    Node* tail = head;
                    while (tail->next != head) {
                        tail = tail->next;
                    }
                    head = head->next;
                    tail->next = head;
                    delete current;
                } else {
                    prev->next = current->next;
                    delete current;
                }
                return true;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        return false;
    }

    bool search(int value) const {
        if (head == nullptr) return false;
        Node* current = head;
        do {
            if (current->data == value) return true;
            current = current->next;
        } while (current != head);
        return false;
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Circular List: ";
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool insertAfterValue(int target, int value) {
        if (head == nullptr) return false;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == target) {
                Node* newNode = new Node(value);
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) current->next->prev = newNode;
                else tail = newNode;
                current->next = newNode;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool insertBeforeValue(int target, int value) {
        if (head == nullptr) return false;
        if (head->data == target) {
            insertAtBeginning(value);
            return true;
        }
        Node* current = head->next;
        while (current != nullptr) {
            if (current->data == target) {
                Node* newNode = new Node(value);
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool deleteByValue(int value) {
        if (head == nullptr) return false;
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (head == tail) {
                    delete current;
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                    delete current;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete current;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool search(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    void displayForward() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly List (forward): ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() const {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly List (backward): ";
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

void circularMenu(CircularList &list) {
    int choice;
    do {
        cout << "\n=== Circular Linked List Menu ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value\n";
        cout << "4. Insert before a value\n";
        cout << "5. Delete a value\n";
        cout << "6. Search a value\n";
        cout << "7. Display list\n";
        cout << "0. Go back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int value, target;
        bool result;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value after which to insert: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                result = list.insertAfterValue(target, value);
                if (!result) cout << "Value " << target << " not found.\n";
                break;
            case 4:
                cout << "Enter value before which to insert: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                result = list.insertBeforeValue(target, value);
                if (!result) cout << "Value " << target << " not found.\n";
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                result = list.deleteByValue(value);
                if (!result) cout << "Value " << value << " not found.\n";
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                result = list.search(value);
                if (result) cout << "Value found in the list.\n";
                else cout << "Value not found.\n";
                break;
            case 7:
                list.display();
                break;
            case 0:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

void doublyMenu(DoublyList &list) {
    int choice;
    do {
        cout << "\n=== Doubly Linked List Menu ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value\n";
        cout << "4. Insert before a value\n";
        cout << "5. Delete a value\n";
        cout << "6. Search a value\n";
        cout << "7. Display list forward\n";
        cout << "8. Display list backward\n";
        cout << "0. Go back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int value, target;
        bool result;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value after which to insert: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                result = list.insertAfterValue(target, value);
                if (!result) cout << "Value " << target << " not found.\n";
                break;
            case 4:
                cout << "Enter value before which to insert: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                result = list.insertBeforeValue(target, value);
                if (!result) cout << "Value " << target << " not found.\n";
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                result = list.deleteByValue(value);
                if (!result) cout << "Value " << value << " not found.\n";
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                result = list.search(value);
                if (result) cout << "Value found.\n";
                else cout << "Value not found.\n";
                break;
            case 7:
                list.displayForward();
                break;
            case 8:
                list.displayBackward();
                break;
            case 0:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int main() {
    CircularList circularList;
    DoublyList doublyList;

    int mainChoice;
    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Work with Circular Linked List\n";
        cout << "2. Work with Doubly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                circularMenu(circularList);
                break;
            case 2:
                doublyMenu(doublyList);
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (mainChoice != 0);

    return 0;
}
