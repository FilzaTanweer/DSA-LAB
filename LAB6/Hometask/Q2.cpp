#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) {
        url = u;
        next = NULL;
    }
};

struct StackNode {
    string url;
    StackNode* next;
    StackNode(string u) {
        url = u;
        next = NULL;
    }
};

void push(StackNode*& top, string url) {
    StackNode* newNode = new StackNode(url);
    newNode->next = top;
    top = newNode;
}

void pop(StackNode*& top) {
    if (top != NULL) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

bool isEmpty(StackNode* top) {
    return top == NULL;
}

void visitWebsite(Node*& head, StackNode*& history, string url) {
    Node* newNode = new Node(url);
    newNode->next = head;
    head = newNode;
    push(history, url);
}

void goBack(Node*& head, StackNode*& history, int steps) {
    for (int i = 0; i < steps && !isEmpty(history); i++) {
        pop(history);
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

void display(Node* head) {
    cout << "Current Browsing History (Most Recent First):" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    StackNode* history = NULL;

    visitWebsite(head, history, "Google");
    visitWebsite(head, history, "Facebook");
    visitWebsite(head, history, "Twitter");
    visitWebsite(head, history, "LinkedIn");
    visitWebsite(head, history, "Instagram");

    cout << "Before going back:" << endl;
    display(head);

    goBack(head, history, 2);

    cout << endl << "After going back twice:" << endl;
    display(head);

    return 0;
}
