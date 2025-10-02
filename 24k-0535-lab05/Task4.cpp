#include <iostream>
#include <cmath>
using namespace std;

void printBoard(int board[][20], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int board[][20], int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    for (int i=row, j=col; i>=0 && j<N; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    return true;
}
void solveNQueensUtil(int board[][20], int row, int N, int &totalSolutions) {
    if (row == N) {
        totalSolutions++;
        printBoard(board, N);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, N, totalSolutions);
            board[row][col] = 0; 
        }
    }
}
void solveNQueens(int N) {
    int board[20][20] = {0};
    int totalSolutions = 0;
    solveNQueensUtil(board, 0, N, totalSolutions);
    cout << "Total distinct solutions for N=" << N << " : " << totalSolutions << endl;
}

int main() {
    int N;
    cout << "Enter the value of N (size of chessboard, max 20): ";
    cin >> N;
    if (N <= 0 || N > 20) {
        cout << "Invalid N!" << endl;
        return 0;
    }
    solveNQueens(N);
    return 0;
}
