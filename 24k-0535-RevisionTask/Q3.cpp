// (a) Backtracking explores all possible paths from the top-left to bottom-right cell.
// It tries each direction recursively (down, right, up, left) until a valid path is found.
// If a move leads to a dead end, the algorithm backtracks and tries another route.
//
// (b) If multiple paths exist, the algorithm follows the first valid path based on the
// direction order defined (down → right → up → left). It always prefers moving down first.

#include <iostream>
using namespace std;

#define N 4

int sol[N][N] = {0};

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int maze[N][N], int x, int y) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y)) return true;

        // Move Right
        if (solveMazeUtil(maze, x, y + 1)) return true;

        // Move Up
        if (solveMazeUtil(maze, x - 1, y)) return true;

        // Move Left
        if (solveMazeUtil(maze, x, y - 1)) return true;

        sol[x][y] = 0; // Backtrack
        return false;
    }
    return false;
}

int main() {
    int maze[N][N] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    cout << "Path the robot takes (1 = part of path):\n";

    if (solveMazeUtil(maze, 0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
