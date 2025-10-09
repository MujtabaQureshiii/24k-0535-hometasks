#include <iostream>
using namespace std;

const int N = 5;

int maze[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

char rabbitGrid[N][N];
char catGrid[N][N];
bool rabbitVisited[N][N] = {false};
bool catVisited[N][N] = {false};

bool isSafe(int r, int c, int maze[N][N], char grid[N][N]) {
    return (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] == 1 && grid[r][c] == '-');
}

void printGrid(char grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Rabbit from (0,0) → (2,2)
void findRabbit(int r, int c) {
    if (r == 2 && c == 2) {
        rabbitGrid[r][c] = 'R';
        rabbitVisited[r][c] = true;
        cout << "\nRabbit Path Found:\n";
        printGrid(rabbitGrid);
        rabbitGrid[r][c] = '-';
        return;
    }

    rabbitGrid[r][c] = 'R';
    rabbitVisited[r][c] = true;

    if (isSafe(r + 1, c, maze, rabbitGrid))
        findRabbit(r + 1, c);

    if (isSafe(r, c + 1, maze, rabbitGrid))
        findRabbit(r, c + 1);

    if (isSafe(r - 1, c, maze, rabbitGrid))
        findRabbit(r - 1, c);

    if (isSafe(r, c - 1, maze, rabbitGrid))
        findRabbit(r, c - 1);

    rabbitGrid[r][c] = '-'; // backtrack
}

// Cat from (4,4) → (2,2)
void findCat(int r, int c) {
    if (r == 2 && c == 2) {
        catGrid[r][c] = 'C';
        catVisited[r][c] = true;
        cout << "\nCat Path Found:\n";
        printGrid(catGrid);
        catGrid[r][c] = '-';
        return;
    }

    catGrid[r][c] = 'C';
    catVisited[r][c] = true;

    if (isSafe(r - 1, c, maze, catGrid))
        findCat(r - 1, c);

    if (isSafe(r, c - 1, maze, catGrid))
        findCat(r, c - 1);

    if (isSafe(r + 1, c, maze, catGrid))
        findCat(r + 1, c);

    if (isSafe(r, c + 1, maze, catGrid))
        findCat(r, c + 1);

    catGrid[r][c] = '-'; // backtrack
}

void showIntersections() {
    cout << "\nIntersection Points (Visited by Both):\n";
    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rabbitVisited[i][j] && catVisited[i][j]) {
                cout << "(" << i << "," << j << ") ";
                found = true;
            }
        }
    }
    if (!found)
        cout << "None";
    cout << endl;
}

void showCombinedGrid() {
    cout << "\nCombined Grid (R=Rabbit, C=Cat, X=Both, -=Unvisited):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rabbitVisited[i][j] && catVisited[i][j])
                cout << "X ";
            else if (rabbitVisited[i][j])
                cout << "R ";
            else if (catVisited[i][j])
                cout << "C ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            rabbitGrid[i][j] = '-';
            catGrid[i][j] = '-';
        }

    cout << "Given Grid (1 = open, 0 = blocked):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }

    cout << "\nRabbit exploring from (0,0) to (2,2)...\n";
    if (maze[0][0] == 1)
        findRabbit(0, 0);
    else
        cout << "Rabbit start blocked!\n";

    cout << "\nCat exploring from (4,4) to (2,2)...\n";
    if (maze[4][4] == 1)
        findCat(4, 4);
    else
        cout << "Cat start blocked!\n";

    showIntersections();
    showCombinedGrid();

    return 0;
}
