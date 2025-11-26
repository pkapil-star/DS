#include <iostream>
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

Node* insertBST(Node* root, int v) {
    if (root == nullptr) return new Node(v);
    if (v < root->data) root->left = insertBST(root->left, v);
    else if (v > root->data) root->right = insertBST(root->right, v);
    return root;
}

Node* minNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left) curr = curr->left;
    return curr;
}

Node* deleteBST(Node* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->data) root->left = deleteBST(root->left, key);
    else if (key > root->data) root->right = deleteBST(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int minDepth(Node* root) {
    if (root == nullptr) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return 1 + (lh < rh ? lh : rh);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, x;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Max Depth\n4. Min Depth\n5. Inorder Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                root = insertBST(root, x);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> x;
                root = deleteBST(root, x);
                break;
            case 3:
                cout << "Maximum depth: " << maxDepth(root) << endl;
                break;
            case 4:
                cout << "Minimum depth: " << minDepth(root) << endl;
                break;
            case 5:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
