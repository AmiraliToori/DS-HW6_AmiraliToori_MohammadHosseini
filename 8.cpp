
#include <iostream>

using namespace std;

class MinHeap {
    int *arr;
    int size;
    int capacity;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && arr[l] < arr[i])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(&arr[i], &arr[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    void insert(int val) {
        size++;
        arr[size - 1] = val;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];) {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteMin() {
        if (size == 0) {
            cout << "Underflow" << endl;
            return;
        }
        swap(&arr[0], &arr[size - 1]);
        size--;
        heapify(0);
    }

    int getMin() {
        return arr[0];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h(11);
    h.insert(3);
    h.insert(22);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.insert(1);
    h.print();
    h.insert(4);
    h.print();
    h.insert(18);
    h.print();
    h.insert(11);
    h.print();
    h.insert(2);
    h.print();
    h.deleteMin();
    h.print();
    h.deleteMin();
    h.print();
    h.insert(13);
    h.print();
    h.insert(5);
    h.print();
    h.insert(1);
    h.print();
    h.deleteMin();
    h.print();
    return 0;
}
 


