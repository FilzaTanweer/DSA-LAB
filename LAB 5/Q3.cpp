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

    int lengthTailRec(Node* node, int count = 0) {
        if (node == NULL) return count;
        return lengthTailRec(node->next, count + 1);
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(8);
    list.insertAtEnd(20);
    list.insertAtEnd(15);
    list.insertAtEnd(35);

    cout << "Length of list: " << list.lengthTailRec(list.head) << endl;
    return 0;
}
