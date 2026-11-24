#include<iostream>
using namespace std;

void Heapify(int arr[], int n, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    // Build Max Heap
    for(int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // Move max to end one by one
    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // swap largest with the last element
        Heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {40, 30, 60, 20, 50, 80, 70};
    int n = 7;
    HeapSort(arr, n);

    cout << " Sorted Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// Heap Sort is also mentioned in the file BinaryHeap1.cpp
// For heap sort in ascending order:
// 1) Insert the elements in the max heap
// 2) After that interchange the positions of first and last element
// 3) Heapify down (exluding the last value added)

// void HeapSort() {
//     int originalSize = size;
//     while (size > 1)
//        {
//           swap(heap[0], heap[size - 1]);   move the current max to the end
//           size--;                          that slot is now "sorted", outside the heap
//           HeapifyDown(0);                  fix what's left
//        }
//        size = originalSize;                 so PrintHeap shows all elements
// }