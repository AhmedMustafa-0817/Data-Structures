#include<iostream>
using namespace std;
#include<string>

int main() {
    const int MAX = 10; int val;
    string** arr = new string*[MAX];

    for (int i=0; i<MAX; i++) {
        cout << "enter seating capacity for row " << i+1 << " ";
        cin >> val;
        arr[i] = new string[val];

        for (int j=0; j<val; j++) {
            cout << "\nenter name for seat " << j << " ";
            cin >> arr[i][j];
        }
    } 
}