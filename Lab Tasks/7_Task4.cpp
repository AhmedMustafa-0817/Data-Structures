#include <iostream>

using namespace std;

void countingSortPixels(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSortPixels(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortPixels(arr, n, exp);
    }
}

void findMostFrequentPixels(const int arr[], int n) {
    int maxFreq = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && arr[j] == arr[i]) j++;
        int freq = j - i;
        if (freq > maxFreq) maxFreq = freq;
        i = j;
    }
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && arr[j] == arr[i]) j++;
        int freq = j - i;
        if (freq == maxFreq) {
            cout << "- Intensity " << arr[i] << " -- Frequency: " << maxFreq << endl;
        }
        i = j;
    }
}

int main() {
    const int originalPixels[] = {120, 45, 200, 45, 120, 255, 45, 200, 10, 120};
    int n = 10;

    int sortedPixels[10];
    for (int i = 0; i < n; i++) {
        sortedPixels[i] = originalPixels[i];
    }

    radixSortPixels(sortedPixels, n);

    cout << "Original pixel array: ";
    for (int i = 0; i < n; i++) {
        cout << originalPixels[i] << (i == n - 1 ? "" : ", ");
    }
    cout << endl;

    cout << "Sorted pixel array: ";
    for (int i = 0; i < n; i++) {
        cout << sortedPixels[i] << (i == n - 1 ? "" : ", ");
    }
    cout << endl;

    cout << "Most frequently occurring intensity values:" << endl;
    findMostFrequentPixels(sortedPixels, n);

    return 0;
}