#include <iostream>
#include<map>
#include<unordered_map>
#include<chrono>
using namespace std;
using namespace std::chrono;

static int linarySearch(int arr[], int length, int value) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}

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

static void insertIntoArray(int*& arr, int length, int index, int value) {
	int* nums = new int[length + 1];
	for (int i = 0; i < index; i++) {
		nums[i] = arr[i];
	}

	nums[index] = value;

	for (int i = index + 1; i < length + 1; i++) {
		nums[i] = arr[i - 1];
	}
	delete[] arr;
	arr = nums;
}

static void deleteFromArray(int*& arr, int length, int index) {
	int* nums = new int[length - 1];
	for (int i = 0; i < index; i++) {
		nums[i] = arr[i];
	}

	for (int i = index; i < length - 1; i++) {
		nums[i] = arr[i + 1];
	}
	delete[] arr;
	arr = nums;
}

static void arrayStatistic(int arr[], int length) {
	int min = arr[0];
	int max = arr[0];
	double sum = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
		sum += arr[i];
	}
	cout << "Min value: " << min << endl;
	cout << "Max value: " << max << endl;
	cout << "Average value: " << sum / length << endl;
}

static map<int, int> countStatistic(int arr[], int length) {
	map<int, int> numsCount;
	for (int i = 0; i < length; i++) {
		numsCount[arr[i]]++;
	}
	return numsCount;
}


int main() {
	int* numbers = new int[8] {2, 5, 9, 3, 1, 8, 5, 3};

	cout << "Original array: ";
	for (int i = 0; i < 8; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "Index of element 5: " << linarySearch(numbers, 8, 5) << endl;

	insertIntoArray(numbers, 8, 4, 10);
	deleteFromArray(numbers, 9, 2);

	cout << "Edited array: ";
	for (int i = 0; i < 8; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl << endl;

	arrayStatistic(numbers, 8);
	cout << endl;

	map<int, int> count = countStatistic(numbers, 8);
	for (const auto& pair : count) {
		cout << "Number " << pair.first << " occurs " << pair.second << " time(s)." << endl;
	}

	delete[] numbers;
	cout << endl;

	map<string, long long> contacts = {
		{"Bogdan", 3906574856},
		{"Biba", 3809546712},
		{"Vlad", 3065746832}
	};

	// Додаємо
	contacts["Taras"] = 3801234567;
	// Змінюємо
	contacts["Vlad"] = 3801231212;
	// Видаляємо
	contacts.erase("Biba");
	// Виводимо
	cout << "Vlad's phone number: " << contacts.at("Vlad") << endl;

	// Порівняння швидкості вставки та пошуку для map та unordered_map
	cout << endl;
	const int N = 1000000;

	// map
	map<int, int> ordered;
	auto start1 = high_resolution_clock::now();

	for (int i = 0; i < N; i++) {
		ordered[i] = i;
	}

	auto end1 = high_resolution_clock::now();

	long long sum = 0;
	auto start2 = high_resolution_clock::now();

	for (int i = 0; i < N; i++) {
		sum += ordered.at(i);
	}

	auto end2 = high_resolution_clock::now();

	auto duration1 = duration_cast<milliseconds>(end1 - start1);
	auto duration2 = duration_cast<milliseconds>(end2 - start2);

	cout << "map:\n";
	cout << "  Insertion time: " << duration1.count() << " milliseconds\n";
	cout << "  Search time: " << duration2.count() << " milliseconds\n\n";

	// unordered_map 
	unordered_map<int, int> unordered;
	start1 = high_resolution_clock::now();

	for (int i = 0; i < N; i++) {
		unordered[i] = i;
	}

	end1 = high_resolution_clock::now();

	sum = 0;
	start2 = high_resolution_clock::now();

	for (int i = 0; i < N; i++) {
		sum += unordered.at(i);
	}

	end2 = high_resolution_clock::now();

	duration1 = duration_cast<milliseconds>(end1 - start1);
	duration2 = duration_cast<milliseconds>(end2 - start2);

	cout << "unordered_map:\n";
	cout << "  Insertion time: " << duration1.count() << " milliseconds\n";
	cout << "  Search time: " << duration2.count() << " milliseconds\n";

	return 0;
}