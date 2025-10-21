#include <iostream>

using namespace std;

 

int getMax(int a[], int n) {

    int max = a[0];

    for (int i = 1; i < n; i++) {

        if (a[i] > max)

            max = a[i];

    }

    return max;

}

 

void countingSort(int a[], int n, int place) {

    int output[n];

    int count[10] = {0};

 

    for (int i = 0; i < n; i++)

        count[(a[i] / place) % 10]++;

 

    for (int i = 1; i < 10; i++)

        count[i] += count[i - 1];

 

    for (int i = n - 1; i >= 0; i--) {

        output[count[(a[i] / place) % 10] - 1] = a[i];

        count[(a[i] / place) % 10]--;

    }

 

    for (int i = 0; i < n; i++)

        a[i] = output[i];

}

 

void radixSort(int a[], int n) {

    int max = getMax(a, n);

    for (int place = 1; max / place > 0; place *= 10)

        countingSort(a, n, place);

}

 

void printArray(int a[], int n) {

    for (int i = 0; i < n; i++)

        cout << a[i] << " ";

    cout << endl;

}

 

int main() {

    int array1[] = {12, 34, 6, 78, 33, 9, 59, 0, 31, 99};

    int array2[] = {45, 60, 1, 39, 89, 11, 26, 90, 23, 56};

 

    int n1 = sizeof(array1) / sizeof(array1[0]);

    int n2 = sizeof(array2) / sizeof(array2[0]);

    int totalsize = n1 + n2;

 

    int combined[totalsize];

 

    for (int i = 0; i < n1; i++)

        combined[i] = array1[i];

    for (int i = 0; i < n2; i++)

        combined[n1 + i] = array2[i];

 

    cout << "Before sorting, the combined array is:\n";

    printArray(combined, totalsize);

 

    radixSort(combined, totalsize);

 

    cout << "After applying Radix Sort, the combined array is:\n";

    printArray(combined, totalsize);

 

    return 0;


}

 

int partition(Product arr[], int low, int high) {

    double pivot = arr[high].price;

    int i = low - 1;

 

    for (int j = low; j < high; j++) {

        if (arr[j].price < pivot) {

            i++;

            swap(arr[i], arr[j]);

        }

    }

    swap(arr[i + 1], arr[high]);

    return (i + 1);

}

void quicksort(Product arr[], int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);

        quicksort(arr, pi + 1, high);

    }

}

 

int main() {

    Product products[3] = {

        Product("Product 1", 10.99, "This is product 1.", true),

        Product("Product 2", 5.99, "This is product 2.", false),

        Product("Product 3", 2.99, "This is product 3.", true)

    };

 

    quicksort(products, 0, 2);

 

    cout << "Products sorted by price:\n";

    for (int i = 0; i < 3; i++) {

        products[i].display();

    }

 

    return 0;

}
