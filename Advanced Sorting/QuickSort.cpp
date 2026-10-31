#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    // choose the pivot
    int pivot = arr[end];
    int i = start - 1;
      
    for (int j = start; j <= end - 1; j++)    // Traverse arr[start...end] and move all elements 
    {										  // smaller than the pivot on left side. 
        if (arr[j] < pivot)                   
        {									   
            i++;
            swap(arr[i], arr[j]);
        }
    }
	
    swap(arr[i + 1], arr[end]);             // move pivot after smaller elements
    return i + 1;
}

// the QuickSort function implementation


void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        // pi is the partition return index of pivot
        int pi = partition(arr, start, end);

        quickSort(arr, start, pi - 1);   // recursion calls for smaller elements
        quickSort(arr, pi  + 1, end);  // and greater or equals elements
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