#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left])
            return false;
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            return false;
        if (right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nArray elements: " << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    if (isMaxHeap(arr, n))
        cout << "The array represents a Max Heap. " << endl;
    else if (isMinHeap(arr, n))
        cout << "The array represents a Min Heap. " << endl;
    else
        cout << "The array does not represent a Binary Heap " << endl;

    sortArray(arr, n);

    cout << "\nArray after sorting in ascending order: " << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
