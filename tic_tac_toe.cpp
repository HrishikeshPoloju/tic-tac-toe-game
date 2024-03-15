// draw the Tic Tac Toe board
// Get user input 
// check input is valid (Check if the input is within bounds and the chosen cell is empty)
// check if the game has been won
// check if the game ended in a tie

#include<iostream>
#include<vector>
using namespace std;
void drawBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
       cout << '\n';
    }
}
bool checkWin(const vector<vector<char>>& board, char marker) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) ||
            (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker)) {
            return true;
        }
    }
    if ((board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) ||
        (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker)) {
        return true;
    }
    return false;
}

bool checkTie(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '_') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '_')); 
    char currentPlayer = 'X'; 

    while (true) {
       cout << "Current board:\n";
        drawBoard(board);

        int row, col;
       cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
       cin >> row >> col;

        
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '_') {
           cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
           cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (checkTie(board)) {
           cout << "It's a tie!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

   cout << "Final board:\n";
    drawBoard(board);

    return 0;
}
