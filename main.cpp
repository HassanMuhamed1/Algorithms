#include <bits/stdc++.h>
#define input(arr,size) for(int i=0;i<size;i++){cin>>arr[i];}
#define output(arr,size) for(int i=0;i<size;i++){cout<<arr[i]<<' ';}
#define ll long long
using namespace std;

template<typename T>
class priorityQueue {
    vector<T> pQueue;
    int n;
public:
    priorityQueue() {
        n = 0;
    }
    //function to return value of the max element
    T maxElement() {
        return pQueue[0];
    }
    //function to retrieve heap property
    void maxHeapify( int index) {
        int l = 2 * index + 1, r = 2 * index + 2;
        int largest;
        if (l < n && pQueue[index] < pQueue[l])
            largest = l;
        else
            largest = index;
        if (r < n && pQueue[largest] < pQueue[r])
            largest = r;
        if (largest != index) {
            swap(pQueue[index], pQueue[largest]);
            maxHeapify( largest);
        }
    }
    //function to extract / remove the max element
    T dequeue() {
        if (pQueue.empty()) {
            cout<<"Heap is empty";
            return -1;
        }
        T max = pQueue[0];
        swap(pQueue[0],pQueue[n - 1]);
        n--;
        maxHeapify(0);
        return max;
    }
    //function to change the key
    void changeKey( int index, T key) {
        if (key > pQueue[index]) {
            pQueue[index] = key;
            while (index > 0 && pQueue[(index-1)/2] < pQueue[index]) {
                swap(pQueue[index], pQueue[(index-1)/2]);
                index = (index-1)/2;
            }
        }
        else if (key < pQueue[index]) {
            pQueue[index] = key;
            maxHeapify( index);
        }
        else {
            cout<<"new key is equal to the present one.";
        }
    }
    //function to insert a new element
    void enqueue(T key) {
        n++;
        if (std::is_arithmetic<T>::value) {  // Ensure T is a numeric type
            pQueue.push_back(-std::numeric_limits<T>::infinity());
        }
        changeKey(n - 1, key);
    }
    int count() {
        return n;
    }

};

// int main() {
//
//     // Basic functionality sample of Priority Queue
//
//     // Creating priority queue which contains int in it
//     priorityQueue<int> pq;
//
//     // Insert element 1 in pq
//     pq.enqueue(1);
//
//     cout << "Size of pq is : " << pq.count() <<
//       " and Peek Element is : " << pq.maxElement() << endl;
//
//     // Insert element 10 and -8 in pq
//     pq.enqueue(10);
//     pq.enqueue(-8);
//
//     cout << "Size of pq is : " << pq.count() <<
//       " and Peek Element is : " << pq.maxElement() << endl;
//
//     // Delete element from pq
//     pq.dequeue();
//
//     cout << "Size of pq is : " << pq.count() <<
//       " and Peek Element is : " << pq.maxElement() << endl;
//
//     // Delete element from pq
//     pq.dequeue();
//
//     cout << "Size of pq is : " << pq.count() <<
//       " and Peek Element is : " << pq.maxElement() << endl;
//
//     // Insert element 25 in pq
//     pq.enqueue(25);
//
//     cout << "Size of pq is : " << pq.count() <<
//       " and Peek Element is : " << pq.maxElement() << endl;
//     return 0;
//
// }
