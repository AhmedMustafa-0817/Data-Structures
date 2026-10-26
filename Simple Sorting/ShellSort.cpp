#include<iostream>
using namespace std;

void ShellSort(int arr[], int n) {
    int gap = n/2;
    while(gap>0) {
        for(int i=gap; i<n ; i++) {
            int temp=arr[i];
            int j=i-gap;
            while(j>=0 && arr[j]>temp) {
                arr[j+gap] = arr[j];
                j-=gap;
            }
            arr[j+gap] = temp;
        }
        gap=gap/2;
    }
}

int main() {
    int arr[] = {8,3,1,6,4};
    ShellSort(arr, 5);
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}