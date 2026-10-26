#include <iostream>
using namespace std;


class RatMaze
{
private:

    static const int N = 4;
    static const int MAX_PATHS = 10;

  
    // 0  = Blocked
    // 1  = Open
    // -1 = Visited
    
	int maze[N][N];
    char path[N * N];
    int pathIndex;
    char allPaths[MAX_PATHS][N * N];
    int pathCount;

public:

    // Constructor
    RatMaze()
    {
        int temp[N][N] =
        {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}
        };

        pathIndex = 0;
        pathCount = 0;

        // Initialize maze
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                maze[i][j] = temp[i][j];
            }
        }
    }

    // Check whether the cell is safe
    bool isSafe(int row, int col)
    {
        if(row >= 0 && row < N &&
           col >= 0 && col < N &&
           maze[row][col] == 1)
        {
            return true;
        }

        return false;
    }


    // Store the current path
    void storePath()
    {
        // Check whether storage is available
        if(pathCount >= MAX_PATHS)
        {
            return;
        }

        // Copy current path
        for(int i = 0; i < pathIndex; i++)
        {
            allPaths[pathCount][i] = path[i];
        }

        allPaths[pathCount][pathIndex] = '\0';
        pathCount++;
    }


    // Recursive function to find ALL paths
    void findAllPaths(int row, int col)
    {
           if(isSafe(row, col))
        {
            // Mark current cell as visited
            maze[row][col] = -1;

            if(row == N - 1 && col == N - 1)
            {
                storePath();

                // Restore destination cell
                maze[row][col] = 1;
                return;
            }


            // =========================
            // TRY UP
            // =========================

            path[pathIndex] = 'U';
            pathIndex++;
            findAllPaths(row - 1, col);
            pathIndex--;

            // =========================
            // TRY DOWN
            // =========================

            path[pathIndex] = 'D';
            pathIndex++;
            findAllPaths(row + 1, col);
            pathIndex--;

            // =========================
            // TRY RIGHT
            // =========================

            path[pathIndex] = 'R';
            pathIndex++;
            findAllPaths(row, col + 1);
            pathIndex--;

            // =========================
            // TRY LEFT
            // =========================

            path[pathIndex] = 'L';
            pathIndex++;
            findAllPaths(row, col - 1);
            pathIndex--;

            // =========================
            // BACKTRACK
            // =========================

            // Restore current cell
            maze[row][col] = 1;
        }
    }


    // Display all possible paths
    void printAllPaths()
    {
        if(pathCount == 0)
        {
            cout << "No Path Exists." << endl;
            return;
        }

        cout << "All Possible Paths:" << endl;
        cout << endl;


        for(int i = 0; i < pathCount; i++)
        {
            cout<<"Path " << i + 1 << ": "<<allPaths[i]<<endl;
        }
        cout<<endl<<"Total Paths: " << pathCount << endl;
    }


    // Start finding all paths
    void solve()
    {
        findAllPaths(0, 0);
        printAllPaths();
    }
};


int main()
{
    RatMaze obj;
    obj.solve();

    return 0;
}