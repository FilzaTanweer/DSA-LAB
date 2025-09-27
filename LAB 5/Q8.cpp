#include <iostream>
using namespace std;

#define N 4

int board[N][N];
int maxFlags = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;
    return true;
}

void solve(int col) {
    if (col >= N) {
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == 1) count++;
        if (count > maxFlags) maxFlags = count;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            solve(col + 1);
            board[i][col] = 0;
        }
    }
    solve(col + 1);
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    solve(0);
    cout << "Maximum Flags: " << maxFlags << endl;
  return 0;
}
