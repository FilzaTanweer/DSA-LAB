#include <iostream>
#include <string>
using namespace std;

class LibraryQueue {
private:
    string patrons[100];
    int front, rear, size;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
        size = 100;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void addPatron(string name) {
        if (isFull()) {
            cout << "Queue is full. Please wait, no more patrons can join right now." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        patrons[++rear] = name;
        cout << name << " has joined the queue for book transactions." << endl;
    }

    void completeTransaction() {
        if (isEmpty()) {
            cout << "No patrons are waiting in the queue." << endl;
            return;
        }
        cout << patrons[front] << "'s book transaction is completed. They are leaving the queue." << endl;
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No patrons are currently waiting in the queue." << endl;
            return;
        }
        cout << "Current patrons in queue:" << endl;
        for (int i = front; i <= rear; i++)
            cout << i - front + 1 << ". " << patrons[i] << endl;
    }
};

int main() {
    LibraryQueue queue;
    int choice;
    string name;

    while (true) {
        cout << endl;
        cout << "====== Library Queue System ======" << endl;
        cout << "1. Add Patron to Queue" << endl;
        cout << "2. Complete Book Transaction" << endl;
        cout << "3. Display Current Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Enter patron name: ";
                cin >> name;
                queue.addPatron(name);
                break;
            case 2:
                queue.completeTransaction();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                cout << "Exiting the system. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
