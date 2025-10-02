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

    void mergeAlternate(SinglyLinkedList &list2) {
        Node* p1 = head;
        Node* p2 = list2.head;
        Node* p1_next;
        Node* p2_next;

        while (p1 != NULL && p2 != NULL) {
            p1_next = p1->next;
            p2_next = p2->next;

            p1->next = p2;
            p2->next = p1_next;

            p1 = p1_next;
            p2 = p2_next;
        }

        list2.head = p2; 
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
    SinglyLinkedList list1, list2;

    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);

    list2.insertAtEnd(4);
    list2.insertAtEnd(5);
    list2.insertAtEnd(6);
    list2.insertAtEnd(7);
    list2.insertAtEnd(8);

    cout << "List 1 before merge: " << endl;
    list1.display();
    cout << "List 2 before merge: " << endl;
    list2.display();

    list1.mergeAlternate(list2);

    cout << "List 1 after merge: " << endl;
    list1.display();
    cout << "Remaining List 2: "<< endl;
    list2.display();

    return 0;
}
