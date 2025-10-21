#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
};

void insertStudent(Student*& head, string name, int score) {
    Student* newNode = new Student{name, score, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Student* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void displayList(Student* head) {
    cout << "\nStudent Records:" << endl;
    while (head) {
        cout << "Name: " << head->name << " | Score: " << head->score << endl;
        head = head->next;
    }
}

int getMax(Student* head) {
    int mx = head->score;
    while (head) {
        if (head->score > mx)
            mx = head->score;
        head = head->next;
    }
    return mx;
}

void countSort(Student*& head, int exp) {
    Student* output = NULL;
    Student* tail = NULL;
    int count[10] = {0};
    int n = 0;

    Student* temp = head;
    while (temp) {
        int index = (temp->score / exp) % 10;
        count[index]++;
        temp = temp->next;
        n++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    Student** arr = new Student*[n];
    temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    Student** sortedArr = new Student*[n];
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i]->score / exp) % 10;
        sortedArr[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n - 1; i++)
        sortedArr[i]->next = sortedArr[i + 1];
    sortedArr[n - 1]->next = NULL;
    head = sortedArr[0];

    delete[] arr;
    delete[] sortedArr;
}

void radixSort(Student*& head) {
    int maxScore = getMax(head);
    for (int exp = 1; maxScore / exp > 0; exp *= 10)
        countSort(head, exp);
}

int main() {
    Student* head = NULL;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        insertStudent(head, name, score);
    }

    cout << "\nBefore Sorting:";
    displayList(head);

    radixSort(head);

    cout << "\nAfter Sorting (Ascending by Score):";
    displayList(head);

    return 0;
}
