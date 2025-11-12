//AVL trees are height-balanced binary search trees that ensure O(logn) time complexity for insertion, deletion, and search operations.
//They prevent the tree from becoming skewed by maintaining a height difference ≤ 1 between left and right subtrees.


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
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; 
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; 
}
Node* convertToAVL(Node* root) {
    if (!root) return NULL;

    
    root->left = convertToAVL(root->left);
    root->right = convertToAVL(root->right);

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


Node* buildTreeA() {
    Node* root = newNode(10);
    root->left = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    return root;
}

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

    A = convertToAVL(A);
    B = convertToAVL(B);

    cout << "AVL Tree A (Inorder): ";
    inorder(A);
    cout << "\nAVL Tree B (Inorder): ";
    inorder(B);
    cout << endl;
return 0;
}


