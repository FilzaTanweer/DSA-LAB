#include <iostream>
using namespace std;

bool hasDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {3, 5, 1, 7, 2, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (hasDuplicates(arr, n))
        cout << "Array contains duplicates" << endl;
    else
        cout << "No duplicates" << endl;

    return 0;
}
