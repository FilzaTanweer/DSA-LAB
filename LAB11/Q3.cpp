#include <iostream>
#include <list>
using namespace std;

class Hash {
public:
    static const int size = 10;
    list<pair<string,string>> table[size];

    int hashFunction(string s) {
        int sum = 0;
        for(int i=0; i<s.length(); i++)
            sum += s[i];
        return sum % size;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    void deleteKey(string key) {
        int index = hashFunction(key);
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    void search(string key) {
        int index = hashFunction(key);
        for(auto &p : table[index]) {
            if(p.first == key) {
                cout << "Found: " << p.first << " " << p.second << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }

    void display() {
        for(int i=0; i<size; i++) {
            cout << i << ": ";
            for(auto &p : table[i])
                cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    Hash h;
    h.insert("A","aaaa");
    h.insert("B","bbbb");
    h.insert("A","zzzz");
    h.search("A");
    h.deleteKey("B");
    h.display();
    return 0;
}
