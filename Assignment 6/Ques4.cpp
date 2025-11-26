#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char c) {
        data = c;
        next = nullptr;
        prev = nullptr;
    }
};

Node* createList(const string& s) {
    if (s.empty()) return nullptr;
    Node* head = new Node(s[0]);
    Node* tail = head;
    for (int i = 1; i < (int)s.size(); i++) {
        Node* temp = new Node(s[i]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    return head;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;
    Node* left = head;
    Node* right = head;
    while (right->next != nullptr) right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter characters: ";
    cin >> s;

    Node* head = createList(s);
    if (isPalindrome(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
