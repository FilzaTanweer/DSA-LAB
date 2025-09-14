#include <iostream>
#include <string>
using namespace std;

int linearSearch(string arr[], int n, string target, int& steps) {
    steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(string arr[], int n, string target, int& steps) {
    int low = 0, high = n - 1;
    steps = 0;
    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    string arr[10] = {"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
    int n = 10;

    string names[3] = {"Aftab","Rizwan","Tariq"};
    for (int i = 0; i < 3; i++) {
        int stepsLin, stepsBin;
        int idxLin = linearSearch(arr, n, names[i], stepsLin);
        int idxBin = binarySearch(arr, n, names[i], stepsBin);

        cout << names[i] << " -> Linear: index=" << idxLin << " steps=" << stepsLin
             << " | Binary: index=" << idxBin << " steps=" << stepsBin << endl;
    }
    return 0;
}
