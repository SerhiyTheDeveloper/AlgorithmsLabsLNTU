#include <iostream>
#include <chrono>
#include <functional>

using namespace std;
using namespace chrono;

static void measureTime(const string& title, function<void()> func) {
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << title << ": " << duration.count() << " nanoseconds" << endl;
}

static int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

static int binarySearch(int* arr, int size, int target) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) return mid;
		if (arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

static int* initArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
	return arr;
}

int main()
{
	srand(time(0));

	int* arr1 = initArray(10000);
	int* arr2 = initArray(100000);
	int* arr3 = initArray(1000000);

	int target1 = (rand() * rand()) % 10000;
	int target2 = (rand() * rand()) % 100000;
	int target3 = (rand() * rand()) % 1000000;

	cout << "Searching for " << target1 << " in array 10k elements:" << endl;
	measureTime("Linear Search", [&]() { linearSearch(arr1, 10000, target1); });
	measureTime("Binary Search", [&]() { binarySearch(arr1, 10000, target1); });

	cout << endl << "Searching for " << target2 << " in array 100k elements:" << endl;
	measureTime("Linear Search", [&]() { linearSearch(arr2, 100000, target2); });
	measureTime("Binary Search", [&]() { binarySearch(arr2, 100000, target2); });

	cout << endl << "Searching for " << target3 << " in array 1M elements:" << endl;
	measureTime("Linear Search", [&]() { linearSearch(arr3, 1000000, target3); });
	measureTime("Binary Search", [&]() { binarySearch(arr3, 1000000, target3); });

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}
