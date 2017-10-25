/*
 * TicTacToe v1.0
 * Eric Fan on 10/9/17
 * Allows a two player game of TicTacToe.
 * Input format: Row + Column (e.g. A1, C3)
 */

#include <iostream>
using namespace std;

bool isWin(int player, int board[3][3]);
void printArr(int array[3][3]);
void clear(int array[3][3]);

int main() {
  int board[3][3]; // init phase
  int turn = 0, xWins = 0, oWins = 0;
  clear(board);
  while (true) { // game phase
    char coordinates[3];
    cout << "Make a move: ";
    cin >> coordinates;
    int row = toupper(coordinates[0]) - 65, column = coordinates[1] - 49;
    if (row >= 0 && row <= 2 && column >= 0 && column <= 2 && board[row][column] == 2) {
      board[row][column] = turn++ % 2;
      printArr(board);
    } else cout << "Invalid input. ";
    char c = '\0';
    if (isWin(0, board)) {
      cout << "X wins! X has " << ++xWins << " wins. O has " << oWins << " wins. Play again? (Y/N): ";
      clear(board);
      cin >> c;
      turn = 0;
    } else if (isWin(1, board)) {
      cout << "O wins! X has " << xWins << " wins. O has " << ++oWins << " wins. Play again? (Y/N): ";
      clear(board);
      cin >> c;
      turn = 0;
    } if (turn == 9) {
      cout << "Draw. X has " << xWins << " wins. O has " << oWins << " wins. Play again? (Y/N): ";
      clear(board);
      cin >> c;
      turn = 0;
    } if (toupper(c) == 'N') break;
  } cout << "Game over." << endl;
}

bool isWin(int player, int board[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // check rows
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // check columns and (below) diagonals
  } if (board[0][0] == player && board[1][1] == player && board[2][2] == player || board[2][0] == player && board[1][1] == player && board[0][2] == player) return true;
  return false;
}

void printArr(int array[3][3]) {
  cout << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) { // 0 represents X, 1 represents O
      if (array[i][j] == 0) cout << 'X' << (j != 2 ? '|' : '\n');
      else if (array[i][j] == 1) cout << 'O' << (j != 2 ? '|' : '\n');
      else cout << ' ' << (j != 2 ? '|' : '\n');
    } if (i != 2) cout << "-----" << endl;
  } cout << endl;
}

void clear(int array[3][3]) { // 2 represents blank space in board[][]
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) array[i][j] = 2;
}
