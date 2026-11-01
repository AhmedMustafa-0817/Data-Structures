#include <iostream>
using namespace std;

class Solution {

    // Checks whether placing a digit is valid
    bool isSafe(char board[9][9], int row, int col, char dig) {

        // Check horizontal (same row)
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) {
                return false;
            }
        }

        // Check vertical (same column)
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) {
                return false;
            }
        }

        // Find starting position of the 3x3 grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        // Check the 3x3 grid
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }


    // Recursive function to solve Sudoku
    bool helper(char board[9][9], int row, int col) {

        // Base case: All rows completed
        if (row == 9) {
            return true;
        }

        // Calculate next cell
        int nextRow = row;
        int nextCol = col + 1;

        // Move to the next row if current row is completed
        if (nextCol == 9) {
            nextRow++;
            nextCol = 0;
        }

        // If cell is already filled, skip it
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits from 1 to 9
        for (char dig = '1'; dig <= '9'; dig++) {

            if (isSafe(board, row, col, dig)) {

                // Place the digit
                board[row][col] = dig;

                // Recursively solve the next cell
                if (helper(board, nextRow, nextCol)) {
                    return true;
                }

                // Backtrack: Undo the placement
                board[row][col] = '.';
            }
        }

        return false;
    }


public:

    void solveSudoku(char board[9][9]) {
        helper(board, 0, 0);
    }
};


int main() {

    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);

    // Display solved Sudoku
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}