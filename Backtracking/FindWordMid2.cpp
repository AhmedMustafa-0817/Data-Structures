#include <iostream>
#include <string>
using namespace std;

void findPath(char grid[][3], int N, int r, int c, string path, string Word, int index)
{
    // Invalid cell / already visited
    if (r < 0 || c < 0 || r >= N || c >= N || grid[r][c] == '-1' || grid[r][c]!=Word[index])
    {
        return;
    }

    // Destination reached
    int length = Word.length();
    if (grid[r][c] == Word[length-1] && length-1 == index)
    {
        cout << path << endl;
        return;
    } 

    // Mark as visited
    char letter = grid[r][c];
    grid[r][c] = '-1';
    index ++;

    // Down
    findPath(grid, N, r + 1, c, path + "D", Word, index);

    // Up
    findPath(grid, N, r - 1, c, path + "U", Word, index);

    // Left
    findPath(grid, N, r, c - 1, path + "L", Word, index);

    // Right
    findPath(grid, N, r, c + 1, path + "R", Word, index);

    // Unvisit (backtracking)
    grid[r][c] = letter;
    index--;
}


int main()
{
    char grid[3][3] =
    {
        {'D', 'R', 'S'},
        {'C', 'A', 'R'},
        {'W', 'G', 'H'}
    };

    string ToFind = "CARS";

    for (int x=0; x<3; x++) {
        for (int y=0; y<3; y++) {
            findPath(grid, 3, x, y, "", ToFind, 0);
        }
    }

    return 0;
}