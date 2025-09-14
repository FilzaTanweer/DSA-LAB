#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int n = 10;

    cout << "Enter 10 elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "The 4 minimum elements are: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
