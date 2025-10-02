#include <iostream>
using namespace std;

bool isSafe(int x, int y, int maze[N][N], int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool mazehelper(int x, int y, int maze[N][N], int sol[N][N]) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, maze, sol)) {
        sol[x][y] = 1;
        if (mazehelper(x + 1, y, maze, sol))
          return true;
        if (mazehelper(x, y + 1, maze, sol)) 
          return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void maze(int mazeArr[N][N]) {
    int sol[N][N] = {0};
    if (mazehelper(0, 0, mazeArr, sol)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
}

int main() {
  int N;
  cout << "Enter the dimension of maze " << endl;
  cin>> N;
    int mazeArr[N][N] = { {1, 0, 0, 0},
                          {1, 1, 0, 1},
                          {0, 1, 0, 0},
                          {1, 1, 1, 1},
                          {0, 0, 0, 1} };
    maze(mazeArr);
    return 0;
}
