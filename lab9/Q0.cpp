//AVL trees are height-balanced binary search trees that ensure O(logn) time complexity for insertion, deletion, and search operations.
//They prevent the tree from becoming skewed by maintaining a height difference ≤ 1 between left and right subtrees.

// Explanation is in  the comments. 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) {
    if (!n) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// ===== Right Rotation =====
// y is the unbalanced node
// x is y's left child
// T2 is x's right subtree (temporarily stored)
// After rotation, x becomes the new root of the rotated subtree
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root (x)
    return x; 
}

// ===== Left Rotation =====
// x is the unbalanced node
// y is x's right child
// T2 is y's left subtree (temporarily stored)
// After rotation, y becomes the new root of the rotated subtree
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root (y)
    return y; 
}

// ===== Convert BST to AVL =====
// This function recursively traverses the BST and balances it
Node* convertToAVL(Node* root) {
    if (!root) return NULL;

    // Convert left and right subtrees first
    root->left = convertToAVL(root->left);
    root->right = convertToAVL(root->right);

    // Update current node height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Case 1: Left Left Rotation
    // Imbalance caused by inserting into left subtree of left child
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Case 2: Right Right Rotation
    // Imbalance caused by inserting into right subtree of right child
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Case 3: Left Right Rotation (double rotation)
    // Imbalance caused by inserting into right subtree of left child
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left Rotation (double rotation)
    // Imbalance caused by inserting into left subtree of right child
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return balanced node
    return root;
}

// ===== Hard-coded BST A =====
//      10
//     /
//    6
//   / \
//  4   8
// Balanced form after conversion → 6 becomes root
Node* buildTreeA() {
    Node* root = newNode(10);
    root->left = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    return root;
}

// ===== Hard-coded BST B =====
//  10
//    \
//     16
//    /  \
//   12  18
// Balanced form after conversion → 16 becomes root
Node* buildTreeB() {
    Node* root = newNode(10);
    root->right = newNode(16);
    root->right->left = newNode(12);
    root->right->right = newNode(18);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* A = buildTreeA();
    Node* B = buildTreeB();

    // Convert both BSTs into AVL trees
    A = convertToAVL(A);
    B = convertToAVL(B);

    cout << "AVL Tree A (Inorder): ";
    inorder(A);
    cout << "\nAVL Tree B (Inorder): ";
    inorder(B);
    cout << endl;

    return 0;
}


