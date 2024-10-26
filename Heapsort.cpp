#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
private:
    vector<int>& H;
    int heapsize;

    void heapifyDown(int index) {
        int largest = index;           // Initialize largest as root
        int left = 2 * index + 1;      // Left child index
        int right = 2 * index + 2;     // Right child index

        // Compare with left child
        if (left < heapsize && H[left] > H[largest]) {
            largest = left;
        }

        // Compare with right child
        if (right < heapsize && H[right] > H[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != index) {
            swap(H[index], H[largest]);  // Swap root with largest
            heapifyDown(largest);
        }
    }
    void buildMaxHeap() {
        // Start from the last non-leaf node and move up
        for (int i = heapsize / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

public:
    HeapSort(vector<int>& arr) : H(arr), heapsize(arr.size()) {
        buildMaxHeap();
    }

    int extractMax() {
        if (heapsize <= 0) return -1;            // Return -1 if heap is empty
        if (heapsize == 1) return H[--heapsize];  // Reduce size by 1 and return the last element

        int maxVal = H[0];
        H[0] = H[heapsize - 1];        // Move last element to root
        heapsize--;                          // Reduce heap size
        heapifyDown(0);                  // Heapify root
        return maxVal;
    }
};

void heapSort(vector<int>& arr) {
    HeapSort maxHeap(arr);  // Build max heap from the array

    // Extract elements from the heap one by one, storing them at the end of the array
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = maxHeap.extractMax();
    }
}

// Helper function to print an array
void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    printArray(arr);

    heapSort(arr);

    cout << "\n"<< "Sorted array: ";
    printArray(arr);

    return 0;
}
