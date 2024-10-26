#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
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
    cout << "Enter the position of the Fibonacci number you want: ";
    cin >> n;

    int result = fibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}