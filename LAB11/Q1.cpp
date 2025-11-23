#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;
    Node(string k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
public:
    static const int size = 10;
    Node* table[size];

    HashTable() {
        for(int i=0; i<size; i++)
            table[i] = NULL;
    }

    int hashFunction(string s) {
        int sum = 0;
        for(int i=0; i<s.length(); i++)
            sum += s[i];
        return sum % size;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);
        Node* n = new Node(key, value);
        if(table[index] == NULL) {
            table[index] = n;
        } else {
            Node* temp = table[index];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = n;
        }
    }

    void display() {
        for(int i=0; i<size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << "(" << temp->key << "," << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    myhash.display();
    return 0;
}
