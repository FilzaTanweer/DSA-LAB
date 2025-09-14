#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
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

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {11, 23, 35, 42, 57, 63, 74, 89, 95};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    int key = 34;
    int index = binarySearch(arr, n, key);

    if (index == -1) {
        int newArr[20];
        int m = n + 1, j = 0;
        bool inserted = false;
        for (int i = 0; i < m; i++) {
            if (!inserted && (j >= n || key < arr[j])) {
                newArr[i] = key;
                inserted = true;
            } else {
                newArr[i] = arr[j++];
            }
        }
        n = m;
        for (int i = 0; i < n; i++) arr[i] = newArr[i];
        index = binarySearch(arr, n, key);
    }

    cout << " Sorted Array: " << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "Value " << key << " found at index " << index << endl;

    return 0;
}
