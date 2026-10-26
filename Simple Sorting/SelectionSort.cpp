#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int minIndex= i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j+1;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {8,3,1,6,4};
    SelectionSort(arr, 5);
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}