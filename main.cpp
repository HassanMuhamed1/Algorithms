#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n) {
    if (n<=1)
        return n;
    else
        return fibonacci(n-1)+ fibonacci(n-2);
}

template<class T>
int sequentialSearch(vector<T>arr , int target){
    int index=-1;
    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i]==target){
            index=(i+1);
            return index;
        }
    }
    return index;
}


int rBinarySearch(int A[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            return rBinarySearch(A, low, mid - 1, key);
        else
            return rBinarySearch(A, mid + 1, high, key);
    }
    return -1;
}

int main() {
//    int x;
//    cin>>x;
//    cout<<fibonacci(x);
vector<char>arr={'a','b','c','d'};
    cout<<sequentialSearch(arr,'h');

    return 0;
}
