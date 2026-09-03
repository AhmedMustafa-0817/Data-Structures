#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "enter number of rows ";
    cin >> rows;

    int** arr = new int*[rows];

    int* sizes = new int[rows];

    for (int i = 0; i < rows; i++) {
        cout << "enter number of elements in row " << i + 1 << " ";
        cin >> sizes[i];

        arr[i] = new int[sizes[i]];
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter elements for row "
             << i + 1 << ": ";

        for (int j = 0; j < sizes[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxRow = 0;

    for (int i = 1; i < rows; i++)
    {
        if (sizes[i] > sizes[maxRow])
        {
            maxRow = i;
        }
    }

    cout << "row with maximum elements " << maxRow + 1 << endl;

    cout << "size of that row " << sizes[maxRow] << endl;

    cout << "Elements of that row: ";

    for (int j = 0; j < sizes[maxRow]; j++)
    {
        cout << arr[maxRow][j] << " ";
    }

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] sizes;

    return 0;
}