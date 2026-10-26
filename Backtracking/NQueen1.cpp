#include <iostream>
using namespace std;

class NQueen
{
private:

    static const int N = 4;
    int board[N][N];

public:

    // Constructor
    NQueen()
    {
        // Initialize the complete board with 0
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                board[i][j] = 0;
            }
        }
    }


    // Check whether a Queen can be placed
    bool isSafe(int row, int col)
    {
        int i, j;


        // 1. Check same column
        for(i = 0; i < row; i++)
        {
            if(board[i][col] == 1)
                return false;
        }


        // 2. Check Upper-Left Diagonal
        i = row - 1;
        j = col - 1;

        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 1)
                return false;

            i--;
            j--;
        }


        // 3. Check Upper-Right Diagonal
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


    // Recursive Backtracking Function
    bool solveNQueen(int row)
    {
        // Base Case: all Queens have been successfully placed.
        if(row == N)
        {
            return true;
        }

        // Try every column in the current row
        for(int col = 0; col < N; col++)
        {
            if(isSafe(row, col))
            {
                // STEP 1: CHOOSE: Place Queen
                board[row][col] = 1;

                // STEP 2: EXPLORE: Try to place Queen in next row
                if(solveNQueen(row + 1))
                {
                    return true;
                }

                // STEP 3: BACKTRACK
                board[row][col] = 0;
            }
        }


        // Queen cannot be placed in this row
        return false;
    }


    // Display the Chess Board
    void printBoard()
    {
        cout << endl;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }


    // Start N-Queen Problem
    void solve()
    {
        if(solveNQueen(0))
        {
            cout << "Solution Found:" << endl;

            printBoard();
        }
        else
        {
            cout << "No Solution Exists." << endl;
        }
    }
};


int main()
{
    NQueen obj;

    obj.solve();

    return 0;
}