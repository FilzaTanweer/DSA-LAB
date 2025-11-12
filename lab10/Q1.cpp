#include <iostream>
using namespace std;

class Heap {
    int arr[100];
    int size;
    bool isMin;

public:
    Heap(bool minHeap = true) {
        size = 0;
        isMin = minHeap;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void insert(int val) {
        arr[size] = val;
        int i = size;
        size++;
        if (isMin) {
            while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        } else {
            while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        }
    }

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int extreme = i;

        if (isMin) {
            if (left < size && arr[left] < arr[extreme])
                extreme = left;
            if (right < size && arr[right] < arr[extreme])
                extreme = right;
        } else {
            if (left < size && arr[left] > arr[extreme])
                extreme = left;
            if (right < size && arr[right] > arr[extreme])
                extreme = right;
        }

        if (extreme != i) {
            swap(arr[i], arr[extreme]);
            heapify(extreme);
        }
    }

    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) return;
        arr[i] = new_val;
        if (isMin) {
            while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        } else {
            while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        }
        heapify(i);
    }

    void delete_key(int i) {
        if (i < 0 || i >= size) return;
        arr[i] = isMin ? -9999 : 9999;
        if (isMin) {
            while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        } else {
            while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
                swap(arr[(i - 1) / 2], arr[i]);
                i = (i - 1) / 2;
            }
        }
        extract_root();
    }

    void extract_root() {
        if (size <= 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap minHeap(true);
    int values[] = {8, 7, 6, 5, 4};
    for (int i = 0; i < 5; i++) minHeap.insert(values[i]);

    cout << "Min Heap: ";
    minHeap.display();

    minHeap.update_key(2, 3);
    cout << "After updating index 2 with value 3: "  << endl;
    minHeap.display();

    minHeap.delete_key(1);
    cout << "After deleting index 1: "  << endl;
    minHeap.display();

    Heap maxHeap(false);
    for (int i = 0; i < 5; i++) maxHeap.insert(values[i]);

    cout << "\nMax Heap: ";
    maxHeap.display();

    maxHeap.update_key(2, 9);
    cout << "After updating index 2 with value 9: " << endl;
    maxHeap.display();

    maxHeap.delete_key(1);
    cout << "After deleting index 1: " << endl;
    maxHeap.display();

    return 0;
}
