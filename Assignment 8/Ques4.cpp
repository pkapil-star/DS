#include <iostream>
#include <climits>
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

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == nullptr) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = buildTree();
    if (isBST(root))
        cout << "Tree is a BST";
    else
        cout << "Tree is not a BST";
    return 0;
}
