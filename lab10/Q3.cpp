#include <iostream>
using namespace std;

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int kthLargest(int arr[], int n, int k) {
    sortDescending(arr, n);
    return arr[k - 1];
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter value of K: ";
    cin >> k;
    cout << "Kth largest element is: " << kthLargest(arr, n, k) << endl;
    return 0;
}
