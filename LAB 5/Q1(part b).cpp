#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};

int sol[N][N];

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int x, int y, int tx, int ty) {
    if (x == tx && y == ty) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(x, y)) {
        sol[x][y] = 1;
        if (solveMaze(x + 1, y, tx, ty)) return true;
        if (solveMaze(x, y + 1, tx, ty)) return true;
        if (solveMaze(x - 1, y, tx, ty)) return true;
        if (solveMaze(x, y - 1, tx, ty)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (solveMaze(0, 0, 2, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path found" << endl;
    }
    return 0;
}
