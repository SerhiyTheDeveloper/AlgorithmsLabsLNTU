#include <iostream>
#include <chrono>
#include <functional>
#include "Stack.h"
#include "LinkedListStack.h"

using namespace std;
using namespace chrono;

static void measureTime(const string& title, function<void()> func) {
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << title << ": " << duration.count() << " microseconds" << endl;
}

int main()
{
    Stack<int> arrayStack(10000);
	LinkedListStack<int> linkedListStack;

	// Заміри швидкості основних операцій для ArrayStack та LinkedListStack

    measureTime("ArrayStack: Push 10000 elements", [&]() {
        for (int i = 0; i < 10000; i++) arrayStack.push(i);
        });
    measureTime("ArrayStack: Pop 5000 elements", [&]() {
        for (int i = 0; i < 5000; i++) arrayStack.pop();
        });

    cout << endl;

    measureTime("LinkedListStack: Push 10000 elements", [&]() {
        for (int i = 0; i < 10000; i++) linkedListStack.push(i);
        });
    measureTime("LinkedListStack: Pop 5000 elements", [&]() {
        for (int i = 0; i < 5000; i++) linkedListStack.pop();
        });

	return 0;
}
