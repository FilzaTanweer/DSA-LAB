#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int comparisons = 0;
void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int pivotFirst(int a[], int start, int end) {
    return start;
}

int pivotRandom(int a[], int start, int end) {
    return start + rand() % (end - start + 1);
}

int pivotMiddle(int a[], int start, int end) {
    return start + (end - start) / 2;
}

int pivotMedianOfThree(int a[], int start, int end) {
    int mid = start + (end - start) / 2;
    int x = a[start];
    int y = a[mid];
    int z = a[end];

    // Find median of x, y, z and return corresponding index
    if ((x >= y && x <= z) || (x <= y && x >= z))
        return start;
    else if ((y >= x && y <= z) || (y <= x && y >= z))
        return mid;
    else
        return end;
}


int partition(int a[], int start, int end, int pivotIndex) {
    swapInt(a[pivotIndex], a[end]);  
    int pivot = a[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        comparisons++;  
        if (a[j] <= pivot) {
            i++;
            swapInt(a[i], a[j]);
        }
    }
    swapInt(a[i + 1], a[end]);
    return i + 1;
}

void quick(int a[], int start, int end, int (*pivotStrategy)(int[], int, int)) {
 if (start < end) {
int pivotIndex = pivotStrategy(a, start, end);
int p = partition(a, start, end, pivotIndex);
quick(a, start, p - 1, pivotStrategy);
quick(a, p + 1, end, pivotStrategy);
}
}
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    srand(time(0));

    const int n = 10;
    int arr1[n] = {1,2,3,4,5,6,7,8,9,10};          
    int arr2[n] = {10,9,8,7,6,5,4,3,2,1};        
    int arr3[n] = {3,6,8,10,1,2,1,5,7,9};          

 
    int (*pivotMethods[])(int[], int, int) = {pivotFirst, pivotRandom, pivotMiddle, pivotMedianOfThree};
    const char* pivotNames[] = {"First Element", "Random Element", "Middle Element", "Median of Three"};

    int temp[n];

   
    for (int arrType = 0; arrType < 3; arrType++) {
        int *input;
        if (arrType == 0) input = arr1;
        else if (arrType == 1) input = arr2;
        else input = arr3;

        cout << "Testing on ";
        if (arrType == 0) cout << "Sorted array:\n";
        else if (arrType == 1) cout << "Reverse sorted array:\n";
        else cout << "Random array:\n";

        for (int i = 0; i < 4; i++) {
            // Copy input to temp
            for (int j = 0; j < n; j++) temp[j] = input[j];

            comparisons = 0;
            quick(temp, 0, n - 1, pivotMethods[i]);
            cout << pivotNames[i] << " pivot - Comparisons: " << comparisons << "\n";
        }
        cout << "\n";
    }

 
    cout << "Final quick sort on random array using First Element pivot:\n";
    for (int j = 0; j < n; j++) temp[j] = arr3[j];
    comparisons = 0;
    quick(temp, 0, n - 1, pivotFirst);
    cout << "Comparisons: " << comparisons << "\n";

    return 0;
}
