#include <iostream>
#include <chrono>
#include <vector>
#include <ctime>
#include <functional>

using namespace std;
using namespace chrono;

static void insertionSort(vector<int>& bucket) {
	int length = (int)bucket.size();

	if (length <= 1) return;

	for (int i = 1; i < length; i++) {
		int num = bucket[i];
		int j = i - 1;

		while (j >= 0 && bucket[j] > num) {
			bucket[j + 1] = bucket[j];
			j--;
		}

		bucket[j + 1] = num;
	}
}

static void countingSort(int* arr, int n) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;

    int* count = new int[range]();

    for (int i = 0; i < n; ++i) {
        count[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
        }
    }

    delete[] count;
}

static void bucketSort(int* arr, int length, int min, int max) {
	vector<vector<int>> buckets(length);

	long long range = (long long)max - min + 1;

	for (int i = 0; i < length; i++) {
		int ind = (int)(((long long)arr[i] - min) * (length - 1) / range);
		buckets[ind].push_back(arr[i]);
	}

	int index = 0;
	for (int i = 0; i < length; i++) {
		if (!buckets[i].empty()) {
			insertionSort(buckets[i]);

			for (int j = 0; j < buckets[i].size(); j++) {
				arr[index] = buckets[i][j];
				index++;
			}
		}
	}
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
	srand(time(0));

	int length = 1000;

	int* equalArr = new int[length];
	for (int i = 0; i < length; i++) {
		equalArr[i] = 2;
	}

	int* equalArrCopy = new int[length];
	for (int i = 0; i < length; i++) {
		equalArrCopy[i] = equalArr[i];
	}

	int* rangeArr = new int[length];
	rangeArr[0] = 1;
	rangeArr[1] = 10000;
	for (int i = 2; i < length; i++) {
		rangeArr[i] = rand() % 10000;
	}

	int* rangeArrCopy = new int[length];
	for (int i = 0; i < length; i++) {
		rangeArrCopy[i] = rangeArr[i];
	}

	int* evenArr = new int[length];
	for (int i = 0; i < length; i++) {
		evenArr[i] = rand() % 1000;
	}

	int* evenArrCopy = new int[length];
	for (int i = 0; i < length; i++) {
		evenArrCopy[i] = evenArr[i];
	}


	measureTime("CountingSort execution time for array (1000 el) with equal elements", [&]() {
		countingSort(equalArr, length);
	});

	measureTime("CountingSort execution time for array (1000 el) with a large range of values", [&]() {
		countingSort(rangeArr, length);
	});

	measureTime("CountingSort execution time for array (1000 el) with evenly distributed elements", [&]() {
		countingSort(evenArr, length);
	});

	cout << endl;

	measureTime("BucketSort execution time for array (1000 el) with equal elements", [&]() {
		bucketSort(equalArrCopy, 1000, 2, 2);
	});

	measureTime("BucketSort execution time for array (1000 el) with a large range of values", [&]() {
		bucketSort(rangeArrCopy, 1000, 1, 10000);
	});

	measureTime("BucketSort execution time for array (1000 el) with evenly distributed elements", [&]() {
		bucketSort(evenArrCopy, 1000, 0, 1000);
	});

	delete[] equalArr;
	delete[] equalArrCopy;
	delete[] rangeArr;
	delete[] rangeArrCopy;
	delete[] evenArr;
	delete[] evenArrCopy;
}