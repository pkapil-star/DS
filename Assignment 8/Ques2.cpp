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
// Node* insertBST(Node* root, int v) {
//     if (root == nullptr) return new Node(v);
//     if (v < root->data) root->left = insertBST(root->left, v);
//     else if (v > root->data) root->right = insertBST(root->right, v);
//     return root;
// }
//
// Node* searchRec(Node* root, int key) {
//     if (root == nullptr || root->data == key) return root;
//     if (key < root->data) return searchRec(root->left, key);
//     else return searchRec(root->right, key);
// }
//
// Node* searchIter(Node* root, int key) {
//     Node* curr = root;
//     while (curr != nullptr) {
//         if (key == curr->data) return curr;
//         else if (key < curr->data) curr = curr->left;
//         else curr = curr->right;
//     }
//     return nullptr;
// }
//
// Node* minNode(Node* root) {
//     if (root == nullptr) return nullptr;
//     Node* curr = root;
//     while (curr->left != nullptr) curr = curr->left;
//     return curr;
// }
//
// Node* maxNode(Node* root) {
//     if (root == nullptr) return nullptr;
//     Node* curr = root;
//     while (curr->right != nullptr) curr = curr->right;
//     return curr;
// }
//
// Node* inorderSuccessor(Node* root, int key) {
//     Node* target = searchIter(root, key);
//     if (target == nullptr) return nullptr;
//     if (target->right != nullptr) {
//         Node* curr = target->right;
//         while (curr->left != nullptr) curr = curr->left;
//         return curr;
//     }
//     Node* succ = nullptr;
//     Node* curr = root;
//     while (curr != nullptr) {
//         if (key < curr->data) {
//             succ = curr;
//             curr = curr->left;
//         } else if (key > curr->data) {
//             curr = curr->right;
//         } else break;
//     }
//     return succ;
// }
//
// Node* inorderPredecessor(Node* root, int key) {
//     Node* target = searchIter(root, key);
//     if (target == nullptr) return nullptr;
//     if (target->left != nullptr) {
//         Node* curr = target->left;
//         while (curr->right != nullptr) curr = curr->right;
//         return curr;
//     }
//     Node* pred = nullptr;
//     Node* curr = root;
//     while (curr != nullptr) {
//         if (key > curr->data) {
//             pred = curr;
//             curr = curr->right;
//         } else if (key < curr->data) {
//             curr = curr->left;
//         } else break;
//     }
//     return pred;
// }
//
// int main() {
//     int n;
//     cout << "Enter number of nodes: ";
//     cin >> n;
//     Node* root = nullptr;
//     cout << "Enter values: ";
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         root = insertBST(root, x);
//     }
//
//     cout << "\nMinimum element: ";
//     Node* mn = minNode(root);
//     if (mn) cout << mn->data; else cout << "Tree empty";
//
//     cout << "\nMaximum element: ";
//     Node* mx = maxNode(root);
//     if (mx) cout << mx->data; else cout << "Tree empty";
//
//     int key;
//     cout << "\n\nEnter key to search: ";
//     cin >> key;
//
//     Node* s1 = searchRec(root, key);
//     cout << "\nRecursive search: ";
//     if (s1) cout << "Found"; else cout << "Not found";
//
//     Node* s2 = searchIter(root, key);
//     cout << "\nIterative search: ";
//     if (s2) cout << "Found"; else cout << "Not found";
//
//     Node* succ = inorderSuccessor(root, key);
//     cout << "\nInorder successor of " << key << ": ";
//     if (succ) cout << succ->data; else cout << "None";
//
//     Node* pred = inorderPredecessor(root, key);
//     cout << "\nInorder predecessor of " << key << ": ";
//     if (pred) cout << pred->data; else cout << "None";
//
//     return 0;
// }
