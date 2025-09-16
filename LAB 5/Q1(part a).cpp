#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayReverse(Node* node) {
        if (node == NULL) return;
        displayReverse(node->next);
        cout << node->data << " ";
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(12);
    list.insertAtEnd(34);
    list.insertAtEnd(26);
    cout << "Reverse order: " << endl;
    list.displayReverse(list.head);
}
