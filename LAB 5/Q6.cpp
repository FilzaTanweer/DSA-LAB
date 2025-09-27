#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    if (dim == 1) {
        int sum = 0;
        for (int i = 0; i < sizes[0]; i++) sum += arr[i][0];
        return sum;
    }
    int sum = 0;
    for (int i = 0; i < sizes[0]; i++) {
      sum += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
    }
    return sum;
}

int main() {
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5};
    int a3[] = {6, 7, 8, 9};
    int* arr1[] = {a1, a2, a3};
    int sizes[] = {3, 4};
    cout << recursiveArraySum((int**)arr1, sizes, 2);
}
