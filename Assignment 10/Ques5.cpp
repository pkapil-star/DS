#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = nullptr;
    }
};

bool hasLoop(Node* head) {
    unordered_set<Node*> visited;
    Node* curr = head;
    while (curr != nullptr) {
        if (visited.find(curr) != visited.end())
            return true;
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;    // creating loop

    if (hasLoop(n1))
        cout << "true";
    else
        cout << "false";

    return 0;
}
