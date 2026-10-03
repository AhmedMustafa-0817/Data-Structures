#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    int key = 30;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Found at index: " << result;
    else
        cout << "Not Found";

    return 0;
}