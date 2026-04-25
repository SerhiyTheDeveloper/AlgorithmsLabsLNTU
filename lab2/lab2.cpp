#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int factorial(int n) {
    if (n <= 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int tailFactorial(int n, int acc = 1) {
    if (n <= 0) {
        return acc;
    }
    return tailFactorial(n - 1, n * acc);
}

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int tailFibonacci(int n, int acc1 = 0, int acc2 = 1) {
    if (n <= 0) {
        return acc1;
    }
    if (n == 1) {
        return acc2;
    }
    return tailFibonacci(n - 1, acc2, acc1 + acc2);
}

int tailNumDegree(int num, int degree, int acc = 1) {
    if (degree <= 0) {
        return acc;
    }
    return tailNumDegree(num, degree - 1, acc * num);
}


int main()
{
    auto start = high_resolution_clock::now();
    std::cout << "Factorial of 15: " << factorial(15);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << " << " << duration.count() << " microseconds" << endl << endl;

    start = high_resolution_clock::now();
    std::cout << "Tail Factorial of 15: " << tailFactorial(15);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << " << " << duration.count() << " microseconds" << endl << endl;

    start = high_resolution_clock::now();
    std::cout << "Fibonacci of 30: " << fibonacci(30);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << " << " << duration.count() << " microseconds" << endl << endl;

    start = high_resolution_clock::now();
    std::cout << "Tail Fibonacci of 30: " << tailFibonacci(30);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << " << " << duration.count() << " microseconds" << endl << endl;

    start = high_resolution_clock::now();
    std::cout << "Tail Num Degree of 9^9: " << tailNumDegree(9, 9);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << " << " << duration.count() << " microseconds" << endl << endl;

    return 0;
}
