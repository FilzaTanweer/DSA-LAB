#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char items[100];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (top < 99)
            items[++top] = c;
        else
            cout << "Stack Overflow" << endl;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        } else {
            return items[top--];
        }
    }

    char peek() {
        if (!isEmpty())
            return items[top];
        return '\0';
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                postfix += st.pop();
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                if (c == '^' && st.peek() == '^')
                    break;
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
        postfix += st.pop();

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
