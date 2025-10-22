#include <iostream>
using namespace std;

#define N 4

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeRec(int maze[N][N], int x, int y, int sol[N][N]) {
    // If destination is reached
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;  // mark this cell in solution path

        // Move down
        if (solveMazeRec(maze, x + 1, y, sol))
            return true;

        // Move right
        if (solveMazeRec(maze, x, y + 1, sol))
            return true;

        // Backtrack: unmark this cell
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int sol[N][N] = {0};  // initialize empty solution matrix

    if (solveMazeRec(maze, 0, 0, sol))
        printSolution(sol);
    else
        cout << "No path found!" << endl;

    return 0;
}
