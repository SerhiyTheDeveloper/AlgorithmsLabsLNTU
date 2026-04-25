#include <iostream>
#include "ArrayQueue.h"
#include "LinkedListQueue.h"
#include <chrono>
#include <functional>

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
    ArrayQueue<int> arrayQueue1(100);
    LinkedListQueue<int> linkedListQueue1;
    ArrayQueue<int> arrayQueue2(1000);
    LinkedListQueue<int> linkedListQueue2;
	ArrayQueue<int> arrayQueue3(10000);
	LinkedListQueue<int> linkedListQueue3;

    // Заміри швидкості основних операцій для ArrayQueue та LinkedListQueue

	cout << "ArrayQueue:" << endl;
    measureTime("   Enqueue 100 elements", [&]() {
        for (int i = 0; i < 100; i++) arrayQueue1.enqueue(i);
	});
    measureTime("   Enqueue 1000 elements", [&]() {
        for (int i = 0; i < 1000; i++) arrayQueue2.enqueue(i);
    });
    measureTime("   Enqueue 10000 elements", [&]() {
        for (int i = 0; i < 10000; i++) arrayQueue3.enqueue(i);
	});
	cout << endl;
    measureTime("   Dequeue 100 elements", [&]() {
		for (int i = 0; i < 100; i++) arrayQueue1.dequeue();
    });
    measureTime("   Dequeue 1000 elements", [&]() {
        for (int i = 0; i < 1000; i++) arrayQueue2.dequeue();
    });
    measureTime("   Dequeue 10000 elements", [&]() {
        for (int i = 0; i < 10000; i++) arrayQueue3.dequeue();
    });

    cout << endl << endl;

    cout << "LinkedListQueue:" << endl;
    measureTime("   Enqueue 100 elements", [&]() {
        for (int i = 0; i < 100; i++) linkedListQueue1.enqueue(i);
	});
    measureTime("   Enqueue 1000 elements", [&]() {
        for (int i = 0; i < 1000; i++) linkedListQueue2.enqueue(i);
	});
    measureTime("   Enqueue 10000 elements", [&]() {
        for (int i = 0; i < 10000; i++) linkedListQueue3.enqueue(i);
	});
    cout << endl;
    measureTime("   Dequeue 100 elements", [&]() {
        for (int i = 0; i < 100; i++) linkedListQueue1.dequeue();
    });
    measureTime("   Dequeue 1000 elements", [&]() {
        for (int i = 0; i < 1000; i++) linkedListQueue2.dequeue();
    });
    measureTime("   Dequeue 10000 elements", [&]() {
        for (int i = 0; i < 10000; i++) linkedListQueue3.dequeue();
    });
}
