#include <iostream>
#include <string>

using namespace std;

struct Transaction {
    string id;
    int time;
};

void mergeLogs(Transaction A[], int nA, Transaction B[], int nB, Transaction C[]) {
    int i = 0, j = 0, k = 0;
    while (i < nA && j < nB) {
        if (A[i].time <= B[j].time) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < nA) {
        C[k++] = A[i++];
    }
    while (j < nB) {
        C[k++] = B[j++];
    }
}

void findLongestGap(Transaction C[], int n, string &id1, string &id2, int &maxGap) {
    maxGap = 0;
    if (n < 2) return;
    for (int i = 0; i < n - 1; i++) {
        int gap = C[i + 1].time - C[i].time;
        if (gap > maxGap) {
            maxGap = gap;
            id1 = C[i].id;
            id2 = C[i + 1].id;
        }
    }
}

string searchTransaction(Transaction C[], int n, int time) {
    for (int i = 0; i < n; i++) {
        if (C[i].time == time) {
            return C[i].id;
        }
    }
    return "-1";
}

int main() {
    Transaction A[] = {{"A1", 540}, {"A2", 555}, {"A3", 600}, {"A4", 660}};
    Transaction B[] = {{"B1", 545}, {"B2", 600}, {"B3", 610}, {"B4", 700}};
    int nA = 4, nB = 4;
    Transaction C[8];

    mergeLogs(A, nA, B, nB, C);

    cout << "Merged log: ";
    for (int i = 0; i < 8; i++) {
        cout << C[i].id << " " << C[i].time << (i == 7 ? "" : ", ");
    }
    cout << endl;

    string id1, id2;
    int maxGap = 0;
    findLongestGap(C, 8, id1, id2, maxGap);
    cout << "Longest gap: " << maxGap << " minutes, between " << id1 << " and " << id2 << endl;

    cout << "Searching 600: " << searchTransaction(C, 8, 600) << endl;
    cout << "Searching 650: " << searchTransaction(C, 8, 650) << endl;

    return 0;
}