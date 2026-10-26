#include <iostream>
#include <string>
using namespace std;

void helper(int mat[][4], int n, int r, int c,
            string path, string ans[], int &count)
{
    // Invalid cell / already visited
    if (r < 0 || c < 0 || r >= n || c >= n ||
        mat[r][c] == 0 || mat[r][c] == -1)
    {
        return;
    }

    // Destination reached
    if (r == n - 1 && c == n - 1)
    {
        ans[count] = path;
        count++;
        return;
    }

    // Mark as visited
    mat[r][c] = -1;

    // Down
    helper(mat, n, r + 1, c, path + "D", ans, count);

    // Up
    helper(mat, n, r - 1, c, path + "U", ans, count);

    // Left
    helper(mat, n, r, c - 1, path + "L", ans, count);

    // Right
    helper(mat, n, r, c + 1, path + "R", ans, count);

    // Unvisit (backtracking)
    mat[r][c] = 1;
}


void findPath(int mat[][4], int n)
{
    string ans[100];
    int count = 0;

    helper(mat, n, 0, 0, "", ans, count);

    for (int i = 0; i < count; i++)
    {
        cout << ans[i] << endl;
    }
}


int main()
{
    int mat[4][4] =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    findPath(mat, 4);

    return 0;
}