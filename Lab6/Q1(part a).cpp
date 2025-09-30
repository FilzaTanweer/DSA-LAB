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
    void insertAtPos(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos == 1) { 
            newNode->next = head;
            if (head != NULL) head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }
    
       void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
    }
    
     void deleteLast() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        if (head->next == NULL) { // Only one node
            delete head;
            head = NULL;
            return;
        }

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }
    void deleteAtPos(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        if (pos == 1) { 
            head = head->next;
            if (head != NULL) head->prev = NULL;
            delete temp;
            return;
        }

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->prev != NULL) 
		temp->prev->next = temp->next;
        if (temp->next != NULL) 
		temp->next->prev = temp->prev;

        delete temp;
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

    dll.insertAtPos(10, 1); 
    dll.insertAtPos(20, 2); 
    dll.insertAtPos(25, 2); 
    dll.insertAtPos(30, 2); 
    dll.insertAtPos(60, 2); 
    cout << "Before Deleting" << endl;
    dll.display();

    cout << "After Deleting at pos 2" << endl;
    dll.deleteAtPos(2);     
    dll.display();
    
    cout << "After Deleting at first" << endl;
    dll.deleteFirst(); 
    dll.display();
  
    cout << "After Deleting at last" << endl;
    dll.deleteLast();  
    dll.display();

    return 0;
}
