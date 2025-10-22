#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;


void guessNumber(int secret, int currentPlayer, int totalPlayers) {
    int guess;
    cout << "Player " << currentPlayer << ", enter your guess (1–100): ";
    cin >> guess;

    if (guess == secret) {
        cout << "?? Player " << currentPlayer << " guessed it right! The number was " << secret << "!\n";
        return; 
    } 
    else if (guess < secret) {
        cout << "Too low!\n";
    } 
    else {
        cout << "Too high!\n";
    }

    
    int nextPlayer = (currentPlayer % totalPlayers) + 1;

    
    guessNumber(secret, nextPlayer, totalPlayers);
}

int main() {
    srand(time(0)); 
    int secret = rand() % 100 + 1;

    int players;
    cout << "Enter number of players: ";
    cin >> players;

    cout << "\n--- Number Guessing Game ---\n";
    guessNumber(secret, 1, players);

    return 0;
}
