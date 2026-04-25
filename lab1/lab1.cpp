#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

static void quickSort(int arr[], int firstInd, int lastInd) {
	if (firstInd >= lastInd) return;
	int separator = arr[lastInd];
	int indBeforeSep = firstInd - 1;
	for (int i = firstInd; i <= lastInd - 1; i++) {
		if (arr[i] < separator) {
			indBeforeSep++;
			int value = arr[indBeforeSep];
			arr[indBeforeSep] = arr[i];
			arr[i] = value;
		}
	}
	int value = arr[indBeforeSep + 1];
	arr[indBeforeSep + 1] = arr[lastInd];
	arr[lastInd] = value;

	quickSort(arr, firstInd, indBeforeSep);
	quickSort(arr, indBeforeSep + 2, lastInd);
}

int main()
{
	/// Перевірка коректної роботи методів

	int arr1[] = { 2, 1, 10, 3, 5, 4, 8 };
	int arr2[] = { 2, 1, 10, 3, 5, 4, 8 };

	cout << "Original array: ";
	for (int i = 0; i < size(arr1); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	bubbleSort(arr1, 7);
	quickSort(arr2, 0, 6);

	cout << "Sorted array using Bubble Sort: ";
	for (int i = 0; i < size(arr1); i++) {
		cout << arr1[i] << " ";
	}

	cout << endl;

	cout << "Sorted array using Quick Sort: ";
	for (int i = 0; i < size(arr2); i++) {
		cout << arr2[i] << " ";
	}

	cout << endl << endl;

	/// Заміри швидкості виконання

	const int N = 10000;
	int* arrBubble = new int[N];
	for (int i = 0; i < N; i++) {
		arrBubble[i] = rand() % 1000;
	}

	int* arrQuick = new int[N];
	for (int i = 0; i < N; i++) {
		arrQuick[i] = arrBubble[i];
	}
	auto start = high_resolution_clock::now();

	bubbleSort(arrBubble, N);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "BubbleSort execution time for 10000 elements: " << duration.count() << " microseconds" << endl;

	start = high_resolution_clock::now();

	quickSort(arrQuick, 0, N - 1);

	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "QuickSort execution time for 10000 elements: " << duration.count() << " microseconds" << endl;

	delete[] arrBubble;
	delete[] arrQuick;
}