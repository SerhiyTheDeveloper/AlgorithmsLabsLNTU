#include <iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int nums[5][5] = {
        {  1,  7, 12,  3,  9 },
        { 14,  5,  2, 11,  8 },
        {  4, 13, 10, 15,  6 },
        { 19, 16, 20, 17, 18 },
        { 23, 21, 25, 22, 24 }
    };

    // Обхід по рядках
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << nums[i][j] << " ";
        }
    }
	cout << "- Row-wise traversal" << endl;

    // Обхід по стовпцях
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << nums[j][i] << " ";
        }
    }
	cout << "- Column-wise traversal" << endl;

    // Спіральний вивід
    int top = 0, down = 4, left = 0, right = 4;
    while (top <= down && left <= right) {
        for (int j = left; j <= right; j++) {
            cout << nums[top][j] << " ";
        }
        top++;
        for (int i = top; i <= down; i++) {
            cout << nums[i][right] << " ";
        }
        right--;
        for (int j = right; j >= left; j--) {
            cout << nums[down][j] << " ";
        }
        down--;
        for (int i = down; i >= top; i--) {
            cout << nums[i][left] << " ";
        }
        left++;
    }
    cout << "- Spiral traversal" << endl << endl;

    // Заміри часу для матриці зі 10000 елементів
    int largeNums[500][500];
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            largeNums[i][j] = rand() % 10 + 1;
        }
    }

    // Обхід по рядках
    int sum1 = 0;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            sum1 += largeNums[i][j];
        }
    }
    auto stop = high_resolution_clock::now();
    cout << "Sum of elements by row traversal: " << sum1 << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Row-wise traversal time: " << duration.count() << " microseconds" << endl;

    // Обхід по стовпцях
    int sum2 = 0;
    start = high_resolution_clock::now();
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            sum2 += largeNums[j][i];
        }
    }
    stop = high_resolution_clock::now();
    cout << endl << "Sum of elements by column traversal: " << sum2 << endl;
    duration = duration_cast<microseconds>(stop - start);
    cout << "Column-wise traversal time: " << duration.count() << " microseconds" << endl;

    // Спіральний вивід
    int sum3 = 0;
    start = high_resolution_clock::now();
    int top2 = 0, down2 = 499, left2 = 0, right2 = 499;
    while (top2 <= down2 && left2 <= right2) {
        for (int j = left2; j <= right2; j++) {
            sum3 += largeNums[top2][j];
        }
        top2++;
        for (int i = top2; i <= down2; i++) {
            sum3 += largeNums[i][right2];
        }
        right2--;
        for (int j = right2; j >= left2; j--) {
            sum3 += largeNums[down2][j];
        }
        down2--;
        for (int i = down2; i >= top2; i--) {
            sum3 += largeNums[i][left2];
        }
        left2++;
    }
    stop = high_resolution_clock::now();
    cout << endl << "Sum of elements by spiral traversal: " << sum3 << endl;
    duration = duration_cast<microseconds>(stop - start);
    cout << "Spiral traversal time: " << duration.count() << " microseconds" << endl;
    return 0;
}