#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, bool ascending) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    if (ascending) {
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
    } else {
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n, bool ascending = true) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp, ascending);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:\n";
    printArray(arr, n);

    int ascArr[50], descArr[50];
    for (int i = 0; i < n; i++) {
        ascArr[i] = arr[i];
        descArr[i] = arr[i];
    }

    radixSort(ascArr, n, true);
    cout << "\nSorted in Ascending Order (Radix Sort): " << endl;
    printArray(ascArr, n);

    radixSort(descArr, n, false);
    cout << "\nSorted in Descending Order (Radix Sort): " << endl;
    printArray(descArr, n);

    return 0;
}
