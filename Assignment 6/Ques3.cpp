// Size of the Doubly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int v) { data = v; next = nullptr; prev = nullptr; }
};

int sizeDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(30);
    Node* n3 = new Node(50);
    Node* n4 = new Node(70);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    cout << "Size of Doubly Linked List: " << sizeDoubly(n1);
    return 0;
}

// Size of the circular linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = nullptr; }
};

int sizeCircular(Node* head) {
    if (head == nullptr) return 0;
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* c1 = new Node(20);
    Node* c2 = new Node(100);
    Node* c3 = new Node(40);
    Node* c4 = new Node(80);
    Node* c5 = new Node(60);

    c1->next = c2;
    c2->next = c3;
    c3->next = c4;
    c4->next = c5;
    c5->next = c1;

    cout << "Size of Circular Linked List: " << sizeCircular(c1);
    return 0;
}


