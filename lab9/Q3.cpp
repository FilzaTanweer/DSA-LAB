
#include <iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;
    Node(int val) {
        key = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int height(Node *n) {
    if (n == NULL)
        return 0;
    else
        return n->height;
}

int getBalance(Node *n) {
    if (n == NULL)
        return 0;
    else
        return height(n->left) - height(n->right);
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node *node, int key) {
    if (node == NULL)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printBalance(Node *node) {
    if (node != NULL) {
        printBalance(node->left);
        cout << "Node " << node->key << " -> Balance Factor: " << getBalance(node) << endl;
        printBalance(node->right);
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int arr[] = {10, 5, 15, 3, 7};
    for (int i = 0; i < 5; i++)
        root = insert(root, arr[i]);

    cout << "AVL Tree before inserting 12: ";
    inorder(root);
    cout << endl;

    root = insert(root, 12);

    cout << "AVL Tree after inserting 12: ";
    inorder(root);
    cout << endl;

    cout << "Balance Factors:" << endl;
    printBalance(root);

    cout << "\nHeight of tree: " << height(root) << endl;

    return 0;
}
