#include <iostream>
using namespace std;

class SudokuGame {
private:
    int board[3][3];
    int score;

public:
    SudokuGame() {
    score = 0;
      
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                board[i][j] = 0;
            }
        }
    }

    void displayBoard() {
        cout << "-------" << endl;
        for (int i = 1; i < 4 ;++i) {
            for (int j = 1; j < 4; ++j) {
                if (board[i][j] == 0)
                    cout << "| ";
                else
                    cout << "|" << board[i][j];
            }
            cout << "|" << endl;
            cout << "-------" << endl;
        }
    }

    bool isBoardFull() {
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                if (board[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    bool isValidMove(int row, int col, int num) {
        
        for (int i = 1; i < 4; ++i) {
            if (board[row][i] == num || board[i][col] == num)
                return false;
        }

        return true;
    }

    bool makeMove(int row, int col, int num) {
        if (board[row][col] == 0 && isValidMove(row, col, num)) {
            board[row][col] = num;
            return true;
        }
        return false;
    }

    void playGame() {
        while (!isBoardFull()) {
            displayBoard();
			score++;
            int row, col, num;
            cout << "Enter the row (1-3): ";
            cin >> row;
            cout << "Enter the column (1-3): ";
            cin >> col;
            cout << "Enter the number (1-9): ";
            cin >> num;

            if (makeMove(row, col, num)) {
               
                cout << "Move accepted." << endl;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
       }

        cout << "Congratulations! You solved the Sudoku puzzle!" << endl;
        cout << "Your score: " << score << endl;
    }
};

int main() {
    SudokuGame game;
    game.playGame();

    return 0;
}

