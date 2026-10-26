#include<iostream>
using namespace std;

void CombSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    while(gap>1 || swapped) {
        gap = gap/2;
        if (gap<1) {
            gap = 1;
        }
        swapped = false;
        for (int i=0; i+gap<n; i++) {
            if (arr[i]>arr[i+gap]) {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    int arr[] = {8,3,1,6,4};
    CombSort(arr, 5);
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}