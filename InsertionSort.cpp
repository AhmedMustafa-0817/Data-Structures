#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[] = {8,3,1,6,4};
    InsertionSort(arr, 5);
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}