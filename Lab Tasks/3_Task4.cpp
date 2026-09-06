#include <iostream>
using namespace std;

void combSort(int arr[], int size) {
    int gap = size;
    bool sorted = false;

    while (gap > 1 || !sorted) {

        gap = gap / 1.3;

        if (gap < 1) {
            gap = 1;
        }

        sorted = true;

        for (int i = 0; i + gap < size; i++) {

            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                sorted = false;
            }
        }
    }
}


bool binarySearch(int arr[], int size, int val) {

    int first = 0;
    int last = size - 1;

    while (first <= last) {

        int mid = (first + last) / 2;

        if (arr[mid] == val) {
            return true;
        }
        else if (val > arr[mid]) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }

    return false;
}


void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}


int main() {

    int ID[7] = {105, 203, 150, 87, 310, 120, 250};
    int size = 7;
    int id;

    cout << "Enter book ID to search: ";
    cin >> id;

    bool beforeSorting = binarySearch(ID, size, id);

    cout << "\nBefore sorting: ";

    if (beforeSorting) {
        cout << "Book ID found";
    }
    else {
        cout << "Book ID not found";
    }

    cout << endl;


    combSort(ID, size);

    cout << "Sorted array: ";
    printArray(ID, size);


    bool afterSorting = binarySearch(ID, size, id);

    cout << "After sorting: ";

    if (afterSorting) {
        cout << "Book ID found";
    }
    else {
        cout << "Book ID not found";
    }

    cout << endl;

    return 0;
}