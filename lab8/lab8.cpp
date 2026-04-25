#include <iostream>
#include <chrono>
#include <functional>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

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
    SinglyLinkedList<int> sList;
    DoublyLinkedList<int> dList;

	// Заміри швидкості однакових операцій для SinglyLinkedList та DoublyLinkedList

    measureTime("SinglyList: Add 1000 elements to end", [&]() {
        for (int i = 0; i < 1000; i++) sList.addToEnd(i);
        });

    measureTime("SinglyList: Remove element from middle", [&]() {
        sList.remove(500);
        });

    measureTime("SinglyList: Remove last element", [&]() {
        sList.removeLast();
        });

    cout << endl;

    measureTime("DoublyList: Add 1000 elements to end", [&]() {
        for (int i = 0; i < 1000; i++) dList.addToEnd(i);
        });

    measureTime("DoublyList: Remove element from middle", [&]() {
        dList.remove(500);
        });

    measureTime("DoublyList: Remove last element", [&]() {
        dList.removeLast();
		});

    return 0;
}
