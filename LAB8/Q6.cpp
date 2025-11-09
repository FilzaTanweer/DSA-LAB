#include <iostream>
using namespace std;

struct Node {
    int productID;
    int quantity;
    Node* left;
    Node* right;
    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = right = NULL;
    }
};

class InventoryBST {
public:
    Node* root;
    InventoryBST() { root = NULL; }

    Node* insert(Node* root, int id, int qty) {
        if (root == NULL) return new Node(id, qty);
        if (id < root->productID) root->left = insert(root->left, id, qty);
        else if (id > root->productID) root->right = insert(root->right, id, qty);
        else root->quantity += qty;
        return root;
    }

    void insertProduct(int id, int qty) {
        root = insert(root, id, qty);
    }

    Node* search(Node* root, int id) {
        if (root == NULL || root->productID == id) return root;
        if (id < root->productID) return search(root->left, id);
        else return search(root->right, id);
    }

    void searchProduct(int id) {
        Node* result = search(root, id);
        if (result)
            cout << "Product ID: " << result->productID << " | Quantity: " << result->quantity << endl;
        else
            cout << "Product not found." << endl;
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << "Product ID: " << root->productID << " | Quantity: " << root->quantity << endl;
        inorder(root->right);
    }

    void displayInventory() {
        cout << "Current Inventory:\n";
        inorder(root);
    }

    void findMaxQuantity(Node* root, int &maxQty, int &maxID) {
        if (root == NULL) return;
        if (root->quantity > maxQty) {
            maxQty = root->quantity;
            maxID = root->productID;
        }
        findMaxQuantity(root->left, maxQty, maxID);
        findMaxQuantity(root->right, maxQty, maxID);
    }

    void displayMaxQuantityProduct() {
        int maxQty = -1, maxID = -1;
        findMaxQuantity(root, maxQty, maxID);
        if (maxQty == -1) cout << "Inventory is empty." << endl;
        else cout << "Product with highest quantity -> ID: " << maxID << " | Quantity: " << maxQty << endl;
    }
};

int main() {
    InventoryBST bst;
    bst.insertProduct(101, 50);
    bst.insertProduct(205, 20);
    bst.insertProduct(150, 35);
    bst.insertProduct(101, 10);
    bst.insertProduct(300, 70);
    bst.insertProduct(250, 15);

    bst.displayInventory();

    cout << "\nSearch Product (ID 150):\n";
    bst.searchProduct(150);

    cout << "\nSearch Product (ID 999):\n";
    bst.searchProduct(999);

    cout << "\nProduct with Highest Quantity:\n";
    bst.displayMaxQuantityProduct();

    return 0;
}
