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

bool searchRec(Node* head, int key) {
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    return searchRec(head->next, key); 
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (searchRec(head, key))
        cout << key << " found in list" << endl;
    else
        cout << key << " not found in list" << endl;

    return 0;
}
