#include <iostream>
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

class Dictionary {
public:
    static const int size = 100;
    Node* table[size];

    Dictionary() {
        for(int i=0; i<size; i++)
            table[i] = NULL;
    }

    int hashFunction(string s) {
        int sum = 0;
        for(int i=0; i<s.length(); i++)
            sum += s[i];
        return sum % size;
    }

    void Add_Record(string key, string value) {
        int index = hashFunction(key);
        Node* n = new Node(key, value);
        if(table[index] == NULL) {
            table[index] = n;
        } else {
            Node* t = table[index];
            while(t->next != NULL)
                t = t->next;
            t->next = n;
        }
    }

    void Word_Search(string key) {
        int index = hashFunction(key);
        Node* t = table[index];
        while(t != NULL) {
            if(t->key == key) {
                cout << "search key " << key << ": " << t->value << endl;
                return;
            }
            t = t->next;
        }
        cout << "Error: key " << key << " not found!" << endl;
    }

    void Delete_Record(string key) {
        int index = hashFunction(key);
        Node* t = table[index];
        Node* prev = NULL;
        while(t != NULL) {
            if(t->key == key) {
                if(prev == NULL)
                    table[index] = t->next;
                else
                    prev->next = t->next;
                delete t;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = t;
            t = t->next;   
        }
        cout << "Error: key " << key << " not found!" << endl;
    }

    void Print_Dictionary() {
        for(int i=0; i<size; i++) {
            cout << "index " << i << ": ";
            Node* t = table[i];
            while(t != NULL) {
                cout << "(" << t->key << ", " << t->value << ") ";
                t = t->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    d.Add_Record("EF", "ENG");

    d.Word_Search("AB");
    d.Delete_Record("EF");
    d.Print_Dictionary();

    return 0;
}
