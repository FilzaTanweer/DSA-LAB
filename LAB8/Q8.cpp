#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

int countInRange(Node* root, int a, int b) {
    if (root == nullptr) return 0;
    if (root->data >= a && root->data <= b)
        return 1 + countInRange(root->left, a, b) + countInRange(root->right, a, b);
    else if (root->data < a)
        return countInRange(root->right, a, b);
    else
        return countInRange(root->left, a, b);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 40);
    root = insert(root, 50);

    int a = 5, b = 45;
    cout << "Number of nodes in range [" << a << ", " << b << "] = " 
         << countInRange(root, a, b) << endl;

    return 0;
}
