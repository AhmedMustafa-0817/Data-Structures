#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 4;

// Check if queen can be placed safely
bool isSafe(int board[][4], int row, int col)
{
    int i, j;

    // Check column
    for(i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    i = row - 1;
    j = col - 1;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // Check upper-right diagonal
    i = row - 1;
    j = col + 1;

    while(i >= 0 && j < N)
    {
        if(board[i][j] == 1)
            return false;
        i--;
        j++;
    }

    return true;
}

// Recursive helper
void helper(int board[][4], int row)
{
    // All queens placed
    if(row == N)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        return;
    }

    // Try every column
    for(int col = 0; col < N; col++)
    {
        if(isSafe(board, row, col))
        {
            board[row][col] = 1;

            helper(board, row + 1);

            board[row][col] = 0;  // Backtracking
        }
    }
}

int main()
{
    int board[4][4] = {0};
    helper(board, 0);
    
    return 0;
}