#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessGame(int target, int turn, int players) {
    int guess;
    cout << "Player " << turn + 1 << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == target) {
        cout << "Player " << turn + 1 << " wins! The number was " << target << endl;
        return;
    }
    else if (guess > target) {
        cout << "Too high!" << endl;
    }
    else {
        cout << "Too low!" << endl;
    }

    guessGame(target, (turn + 1) % players, players);
}

int main() {
    srand(time(0));
    int target = rand() % 100 + 1;

    int players;
    cout << "Enter number of players: ";
    cin >> players;

    guessGame(target, 0, players);
    return 0;
}
