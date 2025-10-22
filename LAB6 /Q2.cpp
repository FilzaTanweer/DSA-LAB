#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Transaction {
public:
    int id;
    double amount;
    string description;
    int flag;

    Transaction() {}
    Transaction(int id, double amt, string desc) {
        this->id = id;
        this->amount = amt;
        this->description = desc;
        this->flag = (amt >= 0) ? 1 : 0;
    }

    void applyDiscount() {
        if (flag == 1) {
            if (amount >= 1500) amount -= amount * 0.30;
            else if (amount >= 1000) amount -= amount * 0.15;
            else if (amount >= 500) amount -= amount * 0.05;
        }
    }

    void trimDescription() {
        if (description.length() > 20)
            description = description.substr(0, 17) + "...";
    }

    void reverseTransaction() {
        amount = -amount;
        description += " [REVERSED]";
        flag = 2;
    }

    void display() const {
        cout << "[id=" << id
             << ", amt=" << amount
             << ", desc=\"" << description
             << "\", flag=" << flag << "]" << endl;
    }
};

class Node {
public:
    Transaction data;
    Node* next;
    Node(Transaction t) { data = t; next = NULL; }
};

class TransactionStack {
private:
    Node* top;
public:
    TransactionStack() { top = NULL; }
    bool isEmpty() { return top == NULL; }
    void push(Transaction t) {
        Node* newNode = new Node(t);
        newNode->next = top;
        top = newNode;
    }
    Transaction pop() {
        if (isEmpty()) {
           cout << " Stack is empty! " << endl;
            return Transaction();
        }
        Node* temp = top;
        Transaction popped = temp->data;
        top = top->next;
         delete temp;
        return popped;
    }
    void display() {
        if (isEmpty()) {
           cout << "\nStack is empty!\n";
            return;
        }
        cout << "\nFinal Stack Output:\nTop →\n";
        Node* temp = top;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
        cout << "Bottom → NULL\n";
    }
};

class DoubleStack {
private:
    struct NumNode {
        double data;
        NumNode* next;
    };
    NumNode* top;
public:
    DoubleStack() { top = NULL; }
    void push(double val) {
        NumNode* n = new NumNode();
        n->data = val;
        n->next = top;
        top = n;
    }
    double pop() {
        if (!top) return 0;
        double val = top->data;
        NumNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    bool isEmpty() { return top == NULL; }
};

class CharStack {
private:
    struct CharNode {
        char data;
        CharNode* next;
    };
    CharNode* top;
public:
    CharStack() { top = NULL; }
    void push(char c) {
        CharNode* n = new CharNode();
        n->data = c;
        n->next = top;
        top = n;
    }
    char pop() {
        if (!top) return '\0';
        char val = top->data;
        CharNode* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    char peek() { return (top ? top->data : '\0'); }
    bool isEmpty() { return top == NULL; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        default: return 0;
    }
}

string infixToPostfix(string expr) {
    CharStack ops;
    string output = "";
    for (size_t i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') continue;
        if (isdigit(expr[i]) || expr[i] == '.') {
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                output += expr[i];
                i++;
            }
            output += ' ';
            i--;
        }
        else if (expr[i] == '(')
            ops.push(expr[i]);
        else if (expr[i] == ')') {
            while (!ops.isEmpty() && ops.peek() != '(') {
                output += ops.pop();
                output += ' ';
            }
            ops.pop();
        }
        else {
            while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(expr[i])) {
                output += ops.pop();
                output += ' ';
            }
            ops.push(expr[i]);
        }
    }
    while (!ops.isEmpty()) {
        output += ops.pop();
        output += ' ';
    }
    return output;
}

double evaluatePostfix(string expr) {
    DoubleStack st;
    for (size_t i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') continue;
        if (isdigit(expr[i]) || expr[i] == '.') {
            string val = "";
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                val += expr[i];
                i++;
            }
            st.push(stod(val));
            i--;
        } else {
            double b = st.pop();
            double a = st.pop();
            double result = applyOp(a, b, expr[i]);
            st.push(result);
        }
    }
    return st.pop();
}

int main() {
    srand(time(0));
    Transaction predefined[7] = {
        Transaction(0, 1200, "Sale: Blue Jacket"),
        Transaction(0, 450, "Sale: Cotton Socks"),
        Transaction(0, -300, "Refund: Defective Shirt"),
        Transaction(0, 1700, "Sale: Leather Jacket"),
        Transaction(0, 600, "Sale: Sneakers"),
        Transaction(0, -200, "Refund: Wrong Size"),
        Transaction(0, 2000, "Sale: Premium Watch")
    };
    TransactionStack stack;
    int idCounter = 1;
    cout << "Pushed Transactions:\n";
    for (int i = 0; i < 4; i++) {
        int idx = rand() % 7;
        Transaction t = predefined[idx];
        t.id = idCounter++;
        t.trimDescription();
        t.applyDiscount();
        stack.push(t);
        if (t.flag == 1)
            cout << i + 1 << ". " << t.description << " → Sale Final: " << t.amount << endl;
        else
            cout << i + 1 << ". " << t.description << " → Refund Amount: " << t.amount << endl;
    }
    string infix = "(100 + 20) * 0.9 - 5";
    cout << "\nIntermediate Expression Calculation: " << endl;
    cout << "Infix: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    double result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;
    cout << "\nPop (remove) one transaction:\n";
    Transaction popped = stack.pop();
    popped.reverseTransaction();
    cout << "Popped Transaction: " << popped.description << endl;
    cout << "Amount changed to " << popped.amount << endl;
    cout << "Flag updated to " << popped.flag << endl;
    stack.display();
    return 0;
}
