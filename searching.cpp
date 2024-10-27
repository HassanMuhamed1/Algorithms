#include <bits/stdc++.h>
#define input(arr,size) for(int i=0;i<size;i++){cin>>arr[i];}
#define output(arr,size) for(int i=0;i<size;i++){cout<<arr[i]<<' ';}
#define ll long long
using namespace std;

//Sequential Search
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
//-------------------------------------------
//Recursive Sequential Search
template <typename t>
//pass the array, the target element and default parameter left
//set to 0 not to let the user pass it when calling the function
int recursiveSequentialSearch(vector<t>& arr, t target, int left = 0) {
    if (left == arr.size() - 1 && arr[left] != target)
        return -1;
    if (arr[left] == target)
        return left + 1;
    return recursiveSequentialSearch(arr, target, left + 1);
}
//-------------------------------------------
//Binary search
template<typename T>
int binarySearch(const vector<T>& arr, T target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid + 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
//-------------------------------------------
//Recursive Binary Search
template<typename t>
int recursiveBinarySearch(vector<t> A, int low, int high, t key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (A[mid] == key)
            return mid + 1;
        else if (key < A[mid])
            return recursiveBinarySearch(A, low, mid - 1, key);
        else
            return recursiveBinarySearch(A, mid + 1, high, key);
    }
    return -1;
}
int main() {
    vector<char>arr={'a','b','c','d'};
    cout<<"Sequential search: "<<sequentialSearch(arr,'a')<<endl;
    cout<<"Recursive Sequential search: "<<recursiveSequentialSearch(arr,'a')<<endl;
    sort(arr.begin(),arr.end());
    cout<<"Iterative Binary search: "<<binarySearch(arr,'a')<<endl;
    cout<<"Recursive Binary search: "<<recursiveBinarySearch(arr,0,arr.size()-1,'a');
    return 0;
}