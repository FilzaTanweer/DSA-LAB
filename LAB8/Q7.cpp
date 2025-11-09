#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }

    Node* insert(Node* root, int val) {
        if (root == NULL) return new Node(val);
        if (val < root->data) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    void insertNode(int val) {
        root = insert(root, val);
    }

    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    void findKth(Node* root, int &k, int &ans) {
        if (root == NULL) return;
        findKth(root->left, k, ans);
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        findKth(root->right, k, ans);
    }

    double findMedian() {
        int n = countNodes(root);
        if (n == 0) return 0;

        int k1 = (n + 1) / 2;
        int val1 = 0;
        findKth(root, k1, val1);

        if (n % 2 != 0) return val1;
        else {
            int k2 = n / 2;
            int val2 = 0;
            findKth(root, k2, val2);
            return (val1 + val2) / 2.0;
        }
    }
};

int main() {
    BST bst;
    bst.insertNode(50);
    bst.insertNode(30);
    bst.insertNode(70);
    bst.insertNode(20);
    bst.insertNode(40);
    bst.insertNode(60);
    bst.insertNode(80);

    cout << "Median of BST: " << bst.findMedian() << endl;
    return 0;
}
