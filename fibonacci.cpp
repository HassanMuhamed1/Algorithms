#include <bits/stdc++.h>
#define input(arr,size) for(int i=0;i<size;i++){cin>>arr[i];}
#define output(arr,size) for(int i=0;i<size;i++){cout<<arr[i]<<' ';}
#define ll long long
using namespace std;

//Fibonacci series using recursion.
int fibonacciRecursion(int n) {
    if (n<=1)
        return n;
    else
        return fibonacciRecursion(n-1)+ fibonacciRecursion(n-2);
}
//--------------------------------------------------
//Fibonacci series using divide and conquer (matrix multiplication)
// Function to multiply two 2x2 matrices
void matrixMultiplication(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    // Perform matrix multiplication
    int x = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int y = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int z = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int w = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    // Update matrix mat1 with the result
    mat1[0][0] = x; mat1[0][1] = y; mat1[1][0] = z; mat1[1][1] = w;
}
// Function to perform matrix powering
void matrixPower(vector<vector<int>>& matrix1, int n) {
    //Base case: n <= 1 then stop
    if (n <= 1)
        return;
    //recusrively calculate matrix power by dividing the power by 2 (n/2)
    matrixPower(matrix1, n / 2);
    //multiply the matrix by itself
    matrixMultiplication(matrix1, matrix1);
    //if n is odd then multiply the result by the transformation matrix
    vector<vector<int>> matrix2 = {{1,1},{1,0}};
    if (n % 2 != 0) {
        matrixMultiplication(matrix1, matrix2);
    }
}
// Function to calculate the nth Fibonacci number using matrix powering
int fibonacciDivideAndConquer(int n) {
    if (n <= 1) return n;
    // Initialize the transformation matrix
    vector<vector<int>> matrix1 = {{1, 1}, {1, 0}};
    // Raise the transformation matrix to the power of (n)
    matrixPower(matrix1, n);
    // The result is in the top-right cell of the matrix
    return matrix1[0][1];
}
//Fibonacci series using dynamic programming.
int fibonacciDP(int n) {
    if (n < 0) {
        cout << "Error: n must be non-negative." <<endl;
        exit(1);
    }
    if (n == 0 || n == 1) {
        return n;
    }
    vector<int> fib(n + 1);
    fib[0] = 0;  // F(0)
    fib[1] = 1;  // F(1)
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
int main() {
    int n;
    cin>>n;
    cout<<"Recursive Fibonacci: "<<fibonacciRecursion(n)<<endl;
    cout<<"Divide and Conquer Fibonacci: "<<fibonacciDivideAndConquer(n)<<endl;
    cout<<"Fibonacci dynamic programming: "<<fibonacciDP(n);
    return 0;
}