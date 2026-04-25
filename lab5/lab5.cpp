#include <iostream>
#include <chrono>
#include <functional>
using namespace std;
using namespace chrono;

static void bubbleSort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int value = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = value;
			}
		}
	}
}

static void insertionSort(int arr[], int length) {
	int num;
	int j;

	for (int i = 1; i < length; i++) {
		num = arr[i];
		j = i - 1;

		while (j >= 0 && num < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = num;
	}
}

static int* initArray(int length) {
	int* arr = new int[length];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 1000;
	}
	return arr;
}

static int* copyArray(int* arr, int length) {
	int* arrCopy = new int[length];
	for (int i = 0; i < length; i++) {
		arrCopy[i] = arr[i];
	}
	return arrCopy;
}

static void measureTime(const string& title, function<void()> func) {
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << title << ": " << duration.count() << " microseconds" << endl;
}

int main()
{
	int* arr100 = initArray(100);
	int* arr100copy = copyArray(arr100, 100);

	int* arr1000 = initArray(1000);
	int* arr1000copy = copyArray(arr1000, 1000);

	int* arr10000 = initArray(10000);
	int* arr10000copy = copyArray(arr10000, 10000);

	measureTime("BubbleSort execution time for 100 elements", [&]() {
		bubbleSort(arr100, 100);
	});

	measureTime("BubbleSort execution time for 1000 elements", [&]() {
		bubbleSort(arr1000, 1000);
	});

	measureTime("BubbleSort execution time for 10000 elements", [&]() {
		bubbleSort(arr10000, 10000);
	});

	cout << endl;

	measureTime("InsertionSort execution time for 100 elements", [&]() {
		insertionSort(arr100copy, 100);
	});

	measureTime("InsertionSort execution time for 1000 elements", [&]() {
		insertionSort(arr1000copy, 1000);
	});

	measureTime("InsertionSort execution time for 10000 elements", [&]() {
		insertionSort(arr10000copy, 10000);
	});

	delete[] arr100;
	delete[] arr1000;
	delete[] arr10000;
	delete[] arr100copy;
	delete[] arr1000copy;
	delete[] arr10000copy;
}
