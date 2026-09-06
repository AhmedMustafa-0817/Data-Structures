#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

bool binarySearch(int arr[], int size, int val)
{
    int first = 0;
    int last = size - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (arr[mid] == val)
        {
            return true;
        }
        else if (val > arr[mid])
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    int arr[n];

    cout << "Enter employee scores: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted scores: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int k;
    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid rank!" << endl;
        return 0;
    }

    int smallest = arr[k - 1];

    cout << "The " << k << "th smallest score is: "
         << smallest << endl;

    bool result = binarySearch(arr, n, smallest);

    if (result)
    {
        cout << "Score " << smallest
             << " exists in the sorted array." << endl;
    }
    else
    {
        cout << "Score " << smallest
             << " does not exist in the sorted array." << endl;
    }

    return 0;
}