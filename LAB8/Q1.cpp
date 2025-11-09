#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            cout << "Duplicate keys not allowed!" << endl;
        return node;
    }

    bool search(Node* node, int key) {
        if (node == NULL)
            return false;
        if (node->key == key)
            return true;
        if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == NULL)
            return node;
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void searchKey(int key) {
        if (search(root, key))
            cout << "Key " << key << " found in the BST.\n";
        else
            cout << "Key " << key << " not found in the BST.\n";
    }

    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n====== Binary Search Tree Operations ======\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteNode(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            tree.searchKey(value);
            break;

        case 4:
            tree.inorderTraversal();
            break;

        case 5:
            tree.preorderTraversal();
            break;

        case 6:
            tree.postorderTraversal();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
