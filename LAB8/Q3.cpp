#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student {
    string name;
    string roll;
    int score;

    Student() {}
    Student(string n, string r, int s) {
        name = n;
        roll = r;
        score = s;
    }
};

struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(Student s) {
        data = s;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, Student s) {
        if (node == NULL)
            return new Node(s);
        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else if (s.name > node->data.name)
            node->right = insert(node->right, s);
        else
            cout << "Duplicate name not allowed: " << s.name << endl;
        return node;
    }

    Node* search(Node* node, string name) {
        if (node == NULL)
            return NULL;
        if (node->data.name == name)
            return node;
        else if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteByName(Node* node, string name) {
        if (node == NULL)
            return node;

        if (name < node->data.name)
            node->left = deleteByName(node->left, name);
        else if (name > node->data.name)
            node->right = deleteByName(node->right, name);
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
            node->data = temp->data;
            node->right = deleteByName(node->right, temp->data.name);
        }
        return node;
    }

    Node* deleteScoreBelow(Node* node, int threshold) {
        if (node == NULL)
            return NULL;
        node->left = deleteScoreBelow(node->left, threshold);
        node->right = deleteScoreBelow(node->right, threshold);

        if (node->data.score < threshold)
            return deleteByName(node, node->data.name);
        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << "Name: " << node->data.name
                 << " | Roll: " << node->data.roll
                 << " | Score: " << node->data.score << endl;
            inorder(node->right);
        }
    }

    void findMaxScore(Node* node, Student& topStudent) {
        if (node == NULL) return;
        if (node->data.score > topStudent.score)
            topStudent = node->data;
        findMaxScore(node->left, topStudent);
        findMaxScore(node->right, topStudent);
    }

public:
    BST() { root = NULL; }

    void insert(Student s) { root = insert(root, s); }

    void searchStudent(string name) {
        Node* res = search(root, name);
        if (res)
            cout << "Student found → " << res->data.name << " (" << res->data.roll
                 << "), Score: " << res->data.score << endl;
        else
            cout << "Student with name \"" << name << "\" not found.\n";
    }

    void deleteLowScores(int threshold) {
        root = deleteScoreBelow(root, threshold);
    }

    void displayAll() {
        cout << "\n--- Students in BST (Inorder Traversal) ---\n";
        inorder(root);
        cout << "------------------------------------------\n";
    }

    void getTopScorer() {
        if (root == NULL) {
            cout << "BST is empty.\n";
            return;
        }
        Student top = root->data;
        findMaxScore(root, top);
        cout << "\n🏅 Top Scorer: " << top.name
             << " (" << top.roll << ") with " << top.score << " points.\n";
    }
};

int main() {
    srand(time(0));

    Student students[10] = {
        {"Ali", "K221001", 8},
        {"Bilal", "K221002", 15},
        {"Fatima", "K221003", 20},
        {"Hassan", "K221004", 5},
        {"Hammad", "K221005", 12},
        {"Filza", "K221006", 9},
        {"Ayesha", "K221007", 18},
        {"Hamza", "K221008", 25},
        {"Talmeeha", "K221009", 7},
        {"Ahmed", "K221010", 11}
    };

    BST tree;
    cout << "=== Student BST Creation ===\n";
    cout << "Randomly inserting 7 students...\n\n";

    bool used[10] = {false};
    for (int i = 0; i < 7; ) {
        int r = rand() % 10;
        if (!used[r]) {
            used[r] = true;
            tree.insert(students[r]);
            i++;
        }
    }

    tree.displayAll();

    cout << "\n🔍 Searching for a student by name
