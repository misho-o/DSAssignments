#include <iostream>
using namespace std;

#define N 4  // Grid size

// Function to print a valid board arrangement
void printSolution(int board[N][N]) {
    cout << "\nOne possible arrangement of flags:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Function to check if placing a flag at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column (above)
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;  // Safe to place
}

// Recursive backtracking function
bool solveFlags(int board[N][N], int row) {
    // Base case: all rows processed
    if (row >= N)
        return true;

    // Try placing a flag in each column of this row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place the flag

            if (solveFlags(board, row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;  // No valid position found
}

int main() {
    int board[N][N] = {0};  // Initialize empty grid

    if (solveFlags(board, 0)) {
        printSolution(board);
        cout << "\nMaximum number of flags that can be placed: " << N << endl;
    } else {
        cout << "No valid arrangement found!" << endl;
    }

    return 0;
}

