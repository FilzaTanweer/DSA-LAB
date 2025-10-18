#include <iostream>
using namespace std;

class Node {
    int data;
    Node* prev;
    Node* next;
public:
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    Node* reverseRecursive(Node* node) {
        if (node == NULL) return NULL;
        Node* temp = node->prev;
        node->prev = node->next;
        node->next = temp;
        if (node->prev == NULL) return node;
        return reverseRecursive(node->prev);
    }

    void reverse() {
        head = reverseRecursive(head);
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.display();
    cout << "After Reversing:" << endl;
    dll.reverse();
    dll.display();
    return 0;
}
