#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = NULL; }

    bool isEmpty() {
        return top == NULL;
    }

    void push(string val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        Node* temp = top;
        string val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    string peek() {
        if (!isEmpty()) return top->data;
        return "";
    }

    void display() {
        cout << "Stack (Top to Bottom):" << endl;
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack st;

    st.push("x");
    st.push("=");

    double x = 12 + 13 - 5 * (0.5 + 0.5) + 1;

    st.push("12");
    st.push("+");
    st.push("13");
    st.push("-");
    st.push("5");
    st.push("(");
    st.push("0.5");
    st.push("+");
    st.push("0.5");
    st.push(")");
    st.push("+");
    st.push("1");

    string result = to_string((int)x);
    st.push(result);

    cout << "Final Result = " << result << endl << endl;
    st.display();

    return 0;
}
