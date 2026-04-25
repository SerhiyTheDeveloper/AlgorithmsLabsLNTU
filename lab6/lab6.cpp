#include <iostream>
#include <chrono>
#include <functional>
using namespace std;
using namespace chrono;

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

static void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

static void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[left + (right - left) / 2];

	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			swap(arr, i, j);
			i++;
			j--;
		}
	}

	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}

static void shellSort(int arr[], int length) {
	for (int gap = length / 2; gap > 0; gap /= 2) {

		for (int i = gap; i < length; i++) {
			int temp = arr[i];
			int j;

			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}

			arr[j] = temp;
		}
	}
}


int main()
{
	srand(time(0));

	int* arr100 = initArray(100);
	int* arr100copy = copyArray(arr100, 100);

	int* arr1000 = initArray(1000);
	int* arr1000copy = copyArray(arr1000, 1000);

	int* arr10000 = initArray(10000);
	int* arr10000copy = copyArray(arr10000, 10000);

	measureTime("QuickSort execution time for 100 elements", [&]() {
		quickSort(arr100, 0, 99);
	});

	measureTime("QuickSort execution time for 1000 elements", [&]() {
		quickSort(arr1000, 0, 999);
	});

	measureTime("QuickSort execution time for 10000 elements", [&]() {
		quickSort(arr10000, 0, 9999);
	});

	cout << endl;

	measureTime("ShellSort execution time for 100 elements", [&]() {
		shellSort(arr100copy, 99);
	});

	measureTime("ShellSort execution time for 1000 elements", [&]() {
		shellSort(arr1000copy, 999);
	});

	measureTime("ShellSort execution time for 10000 elements", [&]() {
		shellSort(arr10000copy, 9999);
	});
	
	delete[] arr100;
	delete[] arr1000;
	delete[] arr10000;
	delete[] arr100copy;
	delete[] arr1000copy;
	delete[] arr10000copy;
}