#include <iostream>
using namespace std;

// Find maximum value in array
int getMax(int arr[], int n)
{
    int maxValue = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}


// Counting Sort according to current digit
void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10] = {0};

    // Count occurrence of each digit
    for(int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Convert count[] into cumulative count
    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array
    // Traverse from right to left to maintain stability
    for(int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output array back to original array
    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}


// Radix Sort
void radixSort(int arr[], int n)
{
    int maxValue = getMax(arr, n);

    // exp = 1   -> Units
    // exp = 10  -> Tens
    // exp = 100 -> Hundreds
    for(int exp = 1; maxValue / exp > 0; exp = exp * 10)
    {
        countingSort(arr, n, exp);
    }
}


// Print Array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Main Function
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:" << endl;
    printArray(arr, n);

    radixSort(arr, n);
    cout << endl;

    cout << "Sorted Array:" << endl;
    printArray(arr, n);
	
    return 0;
}