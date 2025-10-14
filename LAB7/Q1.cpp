#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    int size;     
    char* arr;     
    int top;       

public:
    Stack(int s) {
        size = s;
        arr = new char[size];  
        top = -1;
    }

    void push(char ch) {
        if (top == size - 1)
            cout << "Stack Overflow! " << endl;
        else
            arr[++top] = ch;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow"  << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    string word = "BORROWROB";
    int size = word.length();
    Stack s(size);

    string reversed = "";

    for (int i = 0; i < word.length(); i++) {
        s.push(word[i]);
    }

    while (!s.isEmpty()) {
        reversed += s.pop();
    }


    cout << "Original String: " << word << endl;
    cout << "Reversed String: " << reversed << endl;

    if (word == reversed)
        cout << "It is a palindrome!" << endl;
    else
        cout << " It is not a palindrome!" << endl;

    return 0;
}
