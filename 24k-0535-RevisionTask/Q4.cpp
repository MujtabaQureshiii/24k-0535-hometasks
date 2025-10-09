// (a) Backtracking is used to find a safe escape path from the top-left to the bottom-right corner.
// It explores all possible moves (down, right, up, left) recursively until it reaches the exit.
// If a move leads to a blocked or already visited cell, it backtracks to try a new route.
//
// (b) If no safe route exists, backtracking ensures the algorithm explores all paths.
// When all routes fail, the function returns false, and the message "No escape path found."
// is printed. The line responsible for this backtrack step is:  sol[x][y] = 0;  // backtrack

#include <iostream>
using namespace std;

#define N 4

int sol[N][N] = {0}; 

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool findPath(int maze[N][N], int x, int y) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        // Move Down
        if (findPath(maze, x + 1, y)) return true;

        // Move Right
        if (findPath(maze, x, y + 1)) return true;

        // Move Up
        if (findPath(maze, x - 1, y)) return true;

        // Move Left
        if (findPath(maze, x, y - 1)) return true;

        sol[x][y] = 0;  // backtrack
        return false;
    }
    return false;
}

int main() {
    int maze[N][N] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    cout << "Safe escape path (1 = part of path):\n";

    if (findPath(maze, 0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No escape path found." << endl;
    }

    return 0;
}
