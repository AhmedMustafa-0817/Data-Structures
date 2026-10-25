#include <iostream>

using namespace std;

struct Computer {
    int id;
    int memory;
};

void quickSortComputers(Computer arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[low + (high - low) / 2].memory;
    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i].memory < pivot) i++;
        while (arr[j].memory > pivot) j--;
        if (i <= j) {
            Computer temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j) quickSortComputers(arr, low, j);
    if (i < high) quickSortComputers(arr, i, high);
}

int main() {
    Computer comps[] = {
        {14, 2048},
        {7, 512},
        {21, 4096},
        {3, 1024},
        {18, 512}
    };
    int n = 5;

    cout << "Before sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Computer " << comps[i].id << " -- " << comps[i].memory << " MB" << endl;
    }

    quickSortComputers(comps, 0, n - 1);

    cout << "\nAfter sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Computer " << comps[i].id << " (" << comps[i].memory << " MB)" << (i == n - 1 ? "" : ", ");
    }
    cout << endl;

    return 0;
}