// #include <iostream>
// using namespace std;
//
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int v) {
//         data = v;
//         left = nullptr;
//         right = nullptr;
//     }
// };
//
// Node* buildTree() {
//     int x;
//     cout << "Enter value (-1 for null): ";
//     cin >> x;
//     if (x == -1) return nullptr;
//     Node* root = new Node(x);
//     cout << "Enter left of " << x << endl;
//     root->left = buildTree();
//     cout << "Enter right of " << x << endl;
//     root->right = buildTree();
//     return root;
// }
//
// void preorder(Node* root) {
//     if (!root) return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
//
// void inorder(Node* root) {
//     if (!root) return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }
//
// void postorder(Node* root) {
//     if (!root) return;
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }
//
// int main() {
//     Node* root = buildTree();
//
//     cout << "\nPreorder: ";
//     preorder(root);
//
//     cout << "\nInorder: ";
//     inorder(root);
//
//     cout << "\nPostorder: ";
//     postorder(root);
//
//     return 0;
// }
