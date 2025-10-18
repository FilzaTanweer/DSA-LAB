#include <iostream>
using namespace std;

class Stack {
private:
    string tasks[100];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    void push(string task) {
        if (top < 99) {
            tasks[++top] = task;
            cout << "Added: " << task << endl;
        } else {
            cout << "List full " << endl; 
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "No tasks to remove " << endl;
        } else {
            cout << "Removed: " << tasks[top--] << endl;
        }
    }

    void showTop() {
        if (!isEmpty()) cout << "Current task: " << tasks[top] << endl;
    }
};

int main() {
    Stack todo;
    todo.push("Finish report");
    todo.push("Email client");
    todo.showTop();
    todo.pop();
    todo.showTop();
    return 0;
}
