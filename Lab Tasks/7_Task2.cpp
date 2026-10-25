#include <iostream>
#include <string>

using namespace std;

struct Guest {
    string name;
    int regNum;
    int priority;
    int seatingNum;
};

void mergeGuests(Guest arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Guest* L = new Guest[n1];
    Guest* R = new Guest[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].priority >= R[j].priority) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSortGuests(Guest arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortGuests(arr, l, m);
        mergeSortGuests(arr, m + 1, r);
        mergeGuests(arr, l, m, r);
    }
}

void assignSeating(Guest arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].seatingNum = i + 1;
    }
}

int searchGuest(Guest arr[], int n, int regNum) {
    for (int i = 0; i < n; i++) {
        if (arr[i].regNum == regNum) {
            return arr[i].seatingNum;
        }
    }
    return -1;
}

int main() {
    Guest guests[] = {
        {"Areeba", 104, 85, 0},
        {"Hamza", 101, 92, 0},
        {"Zain", 105, 85, 0},
        {"Hira", 102, 96, 0},
        {"Saad", 103, 92, 0}
    };
    int n = 5;

    mergeSortGuests(guests, 0, n - 1);
    assignSeating(guests, n);

    cout << "Sorted guest seating:" << endl;
    for (int i = 0; i < n; i++) {
        cout << guests[i].name << " (" << guests[i].seatingNum << ")" << (i == n - 1 ? "" : ", ");
    }
    cout << endl;

    cout << "Search Registration ID 103: " << searchGuest(guests, n, 103) << endl;
    cout << "Search Registration ID 999: " << searchGuest(guests, n, 999) << endl;

    return 0;
}