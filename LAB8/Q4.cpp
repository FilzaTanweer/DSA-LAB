#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

bool search(Node* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    if (data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    cout << "Initial BST (Inorder): ";
    inorder(root);
    cout << endl;

    int val;
    cout << "Enter a value to search: ";
    cin >> val;

    if (search(root, val))
        cout << "Value " << val << " found in BST." << endl;
    else {
        cout << "Value not found! Inserting " << val << "..." << endl;
        root = insert(root, val);
        cout << "Updated BST (Inorder): ";
        inorder(root);
        cout << endl;
    }

    return 0;
}
