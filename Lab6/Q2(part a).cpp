#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
public:
    Node(int val) {
        data = val;
        next = NULL;
    }
    friend class SinglyLinkedList;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() {
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
    }

    void bubbleSort() {
        if (head == NULL) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insertAtEnd(50);
    sll.insertAtEnd(20);
    sll.insertAtEnd(40);
    sll.insertAtEnd(10);
    sll.insertAtEnd(30);

    cout << "Original List: ";
    sll.display();

    sll.bubbleSort();

    cout << "Sorted List: ";
    sll.display();

    return 0;
}
