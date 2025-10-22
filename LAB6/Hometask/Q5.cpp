#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    Queue() {
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

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full, cannot add customer " << value << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << "Customer " << value << " added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers left in the queue." << endl;
            return;
        }
        cout << "Customer " << arr[front] << " has been checked out." << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in queue." << endl;
            return;
        }
        cout << "Customers currently in queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(13);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(1);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);

    cout << endl;
    q.display();
    cout << endl;

    q.dequeue();
    q.dequeue();

    cout << endl;
    q.display();

    return 0;
}
