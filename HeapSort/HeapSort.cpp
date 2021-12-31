//HeapSort
//Kacper Hnatyszyn 3prT5
#include<iostream>
#include<math.h>

using namespace std;

class MinHeap {
public:
    int* harr; 
    int capacity; 
    int heap_size; 

    MinHeap(int cap) {
        heap_size = cap;
        capacity = cap;
        harr = new int[cap];
    }

    void printArray() {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }
    int getMin() {
        return harr[0];
    }
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin() {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        //printArray();
        //cout <<"--"<<harr[0]<<"--";
        return root;
    }

    void getUnsortedArray() {
        cout << "Enter " << capacity << " no of elements to sort using HEAPSORT" << endl;
        for (int i = 0; i < capacity; i++)
            cin >> harr[i];
    }

    void heapSort() {
        int temp[capacity]; // NIE WIEM JAK TO NAPRAWIC :(
        for (int j = 0; j < capacity; j++) {
            //cout<<extractMin()<<" ";
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }
    }

};

int main() {
    int s;
    cout << "Enter Size of Min Heap" << endl;
    cin >> s;
    MinHeap obj(s);
    obj.getUnsortedArray();

    cout << "Unsorted Array :" << endl;
    obj.printArray();

    for (int i = s / 2 - 1; i >= 0; i--) {
        obj.MinHeapify(i);
    }

    //cout << "Heapified Array :"<<endl;
    //obj.printArray();

    cout << "Heap Sorted Array :" << endl;
    obj.heapSort();

}