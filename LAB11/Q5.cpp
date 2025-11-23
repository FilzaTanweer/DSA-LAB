#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    bool used;
    Student() {
        roll = -1;
        name = "";
        used = false;
    }
};

class StudentHashTable {
public:
    static const int size = 15;
    Student table[size];

    int hashFunction(int roll) {
        return roll % size;
    }

    void InsertRecord(int roll, string name) {
        int index = hashFunction(roll);
        int attempt = 0;
        while(attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if(!table[newIndex].used) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].used = true;
                return;
            }
            attempt++;
        }
    }

    void SearchRecord(int roll) {
        int index = hashFunction(roll);
        int attempt = 0;
        while(attempt < size) {
            int newIndex = (index + attempt * attempt) % size;
            if(table[newIndex].used && table[newIndex].roll == roll) {
                cout << table[newIndex].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable h;
    h.InsertRecord(21, "Ali");
    h.InsertRecord(36, "Filza");
    h.InsertRecord(51, "Fatima");

    h.SearchRecord(36);
    h.SearchRecord(99);

    return 0;
}
