#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    string player1;
    string player2;
    char currentPlayerSymbol;
    string currentPlayerName;
    int movesCount;

    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = '1' + (i * 3 + j);
            }
        }
    }

    void displayBoard() const {
        cout << "\n";
        cout << "     |     |     \n";
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
        cout << "     |     |     \n\n";
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        
        return false;
    }

    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    TicTacToe() : movesCount(0) {
        initializeBoard();
    }

    void setupPlayers() {
        cout << "Enter Player 1 name (X): ";
        getline(cin, player1);
        if (player1.empty()) player1 = "Player 1";
        
        cout << "Enter Player 2 name (O): ";
        getline(cin, player2);
        if (player2.empty()) player2 = "Player 2";

        currentPlayerName = player1;
        currentPlayerSymbol = 'X';
    }

    void switchPlayer() {
        if (currentPlayerSymbol == 'X') {
            currentPlayerSymbol = 'O';
            currentPlayerName = player2;
        } else {
            currentPlayerSymbol = 'X';
            currentPlayerName = player1;
        }
    }

    void playGame() {
        cout << "\n==========================================================" << endl;
        cout << "                 *** TIC-TAC-TOE ***" << endl;
        cout << "==========================================================" << endl;
        setupPlayers();

        while (movesCount < 9) {
            displayBoard();
            cout << currentPlayerName << "'s turn (" << currentPlayerSymbol << "). ";
            cout << "Enter the position (1-9): ";

            int choice;
            if (!(cin >> choice) || choice < 1 || choice > 9) {
                cout << "Invalid input. Please enter a number between 1 and 9." << endl;
                clearInputBuffer();
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Position already occupied! Choose another." << endl;
                continue;
            }

            board[row][col] = currentPlayerSymbol;
            movesCount++;

            if (checkWin()) {
                displayBoard();
                cout << "\n**********************************************************" << endl;
                cout << "   Congratulations! " << currentPlayerName << " wins the game!" << endl;
                cout << "**********************************************************\n" << endl;
                return;
            }

            switchPlayer();
        }

        displayBoard();
        cout << "\n**********************************************************" << endl;
        cout << "                    It's a draw!" << endl;
        cout << "**********************************************************\n" << endl;
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}