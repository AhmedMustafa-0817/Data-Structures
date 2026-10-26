#include <iostream>
#include <vector>
using namespace std;

int partition(int *arr, int low, int high)
{
    // choose the pivot
    int pivot = arr[high];
    int i = low - 1;
      
    for (int j = low; j <= high - 1; j++)     // Traverse arr[low..high] and move all smaller
    {										  // elements on left side. Elements from low to
        if (arr[j] < pivot)                   // elements on left side. Elements from low to
        {									  // i are smaller after every iteration
            i++;
            swap(arr[i], arr[j]);
        }
    }
	
    swap(arr[i + 1], arr[high]);             // move pivot after smaller elements
    return i + 1;
}

// the QuickSort function implementation


void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // recursion calls for smaller elements
        quickSort(arr, pi + 1, high);  // and greater or equals elements
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}