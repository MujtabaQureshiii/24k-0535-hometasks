#include <iostream>
using namespace std;

const int N = 7;

bool isSafe(int maze[N][N], int x, int y, int sol[N][N]) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, sol)) {
        sol[x][y] = 1;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int dir = 0; dir < 4; dir++) {
            if (solveMazeUtil(maze, x + dx[dir], y + dy[dir], sol))
                return true;
        }

        sol[x][y] = 0; 
    }

    return false;
}

void printSolution(int sol[N][N]) {
    cout << "Solution Path:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 1, 1}
    };

    int sol[N][N] = {0};

    if (solveMazeUtil(maze, 0, 0, sol))
        printSolution(sol);
    else
        cout << "No path found!\n";

    return 0;
}
