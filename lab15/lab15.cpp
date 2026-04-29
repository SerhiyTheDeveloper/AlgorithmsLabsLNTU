#include <iostream>
#include "HashTable.h"
#include <chrono>
#include <functional>
#include <string>

using namespace std;
using namespace chrono;

static void measureTime(const string& title, function<void()> func) {
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << title << ": " << duration.count() << " microseconds" << endl;
}

int main()
{
	srand(time(0));

	// Перевірка коректності роботи
	HashTable<string, int> students(10);
	students.insert("Alice", 90);
	students.insert("Bob", 85);
	students.insert("Charlie", 95);

	std::cout << "Alice's score: " << students.get("Alice") << endl;
	std::cout << "Bob`s removal status: " << (students.remove("Bob") ? "True" : "False") << endl << endl;

	// Тестування на великій кількості даних
	HashTable<string, int> table1(100);
	HashTable<string, int> table2(1000);
	HashTable<string, int> table3(10000);

	measureTime("Insert 1k elements into a ht(100 cells)  ", [&]() {
		for (int i = 0; i < 1000; ++i) {
			string key = "key_id_" + to_string(i);
			table1.insert(key, i);
		}
	});
	measureTime("Insert 10k elements into a ht(1k cells)  ", [&]() {
		for (int i = 0; i < 10000; ++i) {
			string key = "key_id_" + to_string(i);
			table2.insert(key, i);
		}
	});
	measureTime("Insert 100k elements into a ht(10k cells)", [&]() {
		for (int i = 0; i < 100000; ++i) {
			string key = "key_id_" + to_string(i);
			table3.insert(key, i);
		}
	});

	std::cout << endl;

	measureTime("Remove 1k elements from ht  ", [&]() {
		for (int i = 0; i < 1000; ++i) {
			string key = "key_id_" + to_string(i);
			table1.remove(key);
		}
	});
	measureTime("Remove 10k elements from ht ", [&]() {
		for (int i = 0; i < 10000; ++i) {
			string key = "key_id_" + to_string(i);
			table2.remove(key);
		}
	});
	measureTime("Remove 100k elements from ht", [&]() {
		for (int i = 0; i < 100000; ++i) {
			string key = "key_id_" + to_string(i);
			table3.remove(key);
		}
	});

	return 0;
}
