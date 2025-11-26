#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree() {
    int x;
    cout << "Enter value (-1 for null): ";
    cin >> x;
    if (x == -1) return nullptr;
    Node* root = new Node(x);
    cout << "Enter left of " << x << endl;
    root->left = buildTree();
    cout << "Enter right of " << x << endl;
    root->right = buildTree();
    return root;
}

bool checkDuplicate(Node* root, unordered_set<int> &s) {
    if (root == nullptr) return false;
    if (s.find(root->data) != s.end()) return true;
    s.insert(root->data);
    return checkDuplicate(root->left, s) || checkDuplicate(root->right, s);
}

int main() {
    Node* root = buildTree();
    unordered_set<int> s;
    if (checkDuplicate(root, s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
    return 0;
}
