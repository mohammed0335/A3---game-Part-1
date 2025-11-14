#ifndef GAME5_H
#define GAME5_H

#include <algorithm>
#include "BoardGame_Classes.h"
#include <iomanip>

using namespace std;

int m;
bool gg;
vector<int> player_1 = { 1, 3, 5, 7, 9 };
vector<int> player_2 = { 2, 4, 6, 8 };

template <typename T>
class X_O_Board_5 : public Board<T> {
public:
    X_O_Board_5();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class X_O_Player_5 : public Player<T> {
public:
    X_O_Player_5(string name, vector<int> vec);
    void getmove(int& x, int& y);
    virtual bool get_num_player(int num);
    vector<int> VEC;
};

// ============= Board Implementation =============
template <typename T>
X_O_Board_5<T>::X_O_Board_5() {
    this->rows = this->columns = 3;
    this->board = new int* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool X_O_Board_5<T>::update_board(int x, int y, T mark) {
    if (gg && !(x < 0 || x >= this->rows || y < 0 || y >= this->columns) &&
        (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = mark;
        }
        return true;
    }
    return false;
}

template <typename T>
void X_O_Board_5<T>::display_board() {
    cout << "\n";
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            if (this->board[i][j] == 0) {
                cout << setw(2) << " " << " |";
            }
            else {
                cout << setw(2) << this->board[i][j] << " |";
            }
        }
        cout << "\n-----------------------------\n";
    }
}

template <typename T>
bool X_O_Board_5<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] + this->board[i][1] + this->board[i][2] == 15 &&
            (this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0)) ||
            (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15 &&
                (this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0))) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] + this->board[1][1] + this->board[2][2] == 15 &&
        (this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0)) ||
        (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15 &&
            (this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0))) {
        return true;
    }
    return false;
}

template <typename T>
bool X_O_Board_5<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool X_O_Board_5<T>::game_is_over() {
    return is_win() || is_draw();
}

// ============= Player Implementation =============
template <typename T>
X_O_Player_5<T>::X_O_Player_5(string name, vector<int> vec) : Player<T>(name) {
    this->VEC = vec;
}

template <typename T>
void X_O_Player_5<T>::getmove(int& x, int& y) {
    cout << "\n" << this->getname() << "'s turn" << endl;
    cout << "Available numbers: ";
    for (int num : this->VEC) {
        cout << num << " ";
    }
    cout << "\nEnter x, y, and number (e.g., 0 1 3): ";
    cin >> x >> y >> m;
    this->symbol = m;
    gg = this->get_num_player(m);

    if (!gg) {
        cout << "Invalid number! Choose from your available numbers." << endl;
    }
}

template <typename T>
bool X_O_Player_5<T>::get_num_player(int num) {
    auto if_in = find(this->VEC.begin(), this->VEC.end(), num);
    if (if_in != this->VEC.end()) {
        this->VEC.erase(if_in);
        return true;
    }
    return false;
}

#endif // GAME5_H