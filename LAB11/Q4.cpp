#include <iostream>
using namespace std;

class Node {
public:
    int sum;
    int a, b;
    Node* next;
    Node(int s, int x, int y) {
        sum = s;
        a = x;
        b = y;
        next = NULL;
    }
};

class HashTable {
public:
    static const int size = 1007;
    Node* table[size];

    HashTable() {
        for(int i=0; i<size; i++)
            table[i] = NULL;
    }

    int hashFunction(int x) {
        if(x < 0) x = -x;
        return x % size;
    }

    Node* search(int sum) {
        int index = hashFunction(sum);
        Node* t = table[index];
        while(t != NULL) {
            if(t->sum == sum)
                return t;
            t = t->next;
        }
        return NULL;
    }

    void insert(int sum, int a, int b) {
        int index = hashFunction(sum);
        Node* n = new Node(sum, a, b);
        n->next = table[index];
        table[index] = n;
    }
};

void findPairs(int arr[], int n) {
    HashTable h;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int s = arr[i] + arr[j];
            Node* found = h.search(s);
            if(found != NULL) {
                int a = found->a, b = found->b;
                int c = arr[i], d = arr[j];
                if(a!=c && a!=d && b!=c && b!=d) {
                    cout << "(" << a << ", " << b << ") and (" << c << ", " << d << ")" << endl;
                    return;
                }
            }
            h.insert(s, arr[i], arr[j]);
        }
    }
    cout << "No pairs found" << endl;
}

int main() {
    int arr1[] = {3,4,7,1,2,9,8};
    int arr2[] = {3,4,7,1,12,9};
    int arr3[] = {65,30,7,90,1,9,8};

    findPairs(arr1, 7);
    findPairs(arr2, 6);
    findPairs(arr3, 7);

    return 0;
}
