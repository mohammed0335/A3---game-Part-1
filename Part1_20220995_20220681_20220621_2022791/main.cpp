#include <iostream>
#include "BoardGame_Classes.h"
#include "5.h"

using namespace std;

int main() {
    while (true) {
        int order;
        cout << "\n Welcome to Tic-Tac-Toe Games -" << endl;
        cout << "1- Numerical Tic-Tac-Toe (Group Game)" << endl;
        cout << "2- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> order;

        if (order == 1) {
            // Numerical Tic-Tac-Toe
            Player<int>* players[2];
            X_O_Board_5<int>* board = new X_O_Board_5<int>();
            string player1_name, player2_name;

            cout << "\n=== Numerical Tic-Tac-Toe ===" << endl;
            cout << "Player 1 uses ODD numbers: 1, 3, 5, 7, 9" << endl;
            cout << "Player 2 uses EVEN numbers: 2, 4, 6, 8" << endl;
            cout << "Goal: Make a line that sums to 15!\n" << endl;

            cout << "Enter Player 1 name: ";
            cin >> player1_name;
            players[0] = new X_O_Player_5<int>(player1_name, player_1);

            cout << "Enter Player 2 name: ";
            cin >> player2_name;
            players[1] = new X_O_Player_5<int>(player2_name, player_2);

            GameManager<int> game(board, players);
            game.run();

            delete board;
            delete players[0];
            delete players[1];

        }
        else if (order == 2) {
            cout << "\nThank you for play.\n" << endl;
            break;
        }
        else {
            cout << "\n Please try again.\n" << endl;
        }
    }
    return 0;
}