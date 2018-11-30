
#include "ChessBoard.h"
using namespace std;

namespace chess {
  ChessBoard::ChessBoard() {

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        board_[i][j] = NULL;

    board_[1][0] = new ChessPiece("A2", 0);
    board_[1][1] = new ChessPiece("B2", 0);
    board_[1][2] = new ChessPiece("C2", 0);
    board_[1][3] = new ChessPiece("D2", 0);
    board_[1][4] = new ChessPiece("E2", 0);
    board_[1][5] = new ChessPiece("F2", 0);
    board_[1][6] = new ChessPiece("G2", 0);
    board_[1][7] = new ChessPiece("H2", 0);

    board_[6][0] = new ChessPiece("A7", 1);
    board_[6][1] = new ChessPiece("B7", 1);
    board_[6][2] = new ChessPiece("C7", 1);
    board_[6][3] = new ChessPiece("D7", 1);
    board_[6][4] = new ChessPiece("E7", 1);
    board_[6][5] = new ChessPiece("F7", 1);
    board_[6][6] = new ChessPiece("G7", 1);
    board_[6][7] = new ChessPiece("H7", 1);

  }

  const char* ChessBoard::checkPiecePosition(int i, int j) {
    return board_[i][j]->getPosition();
  }

  void ChessBoard::displayBoard() {
    cout << endl << "   ";
    for (int i = 0; i < 8; i++)
      cout << "  " << (char)('A' + i) << "  ";
    cout << endl << endl;

    for (int i = 7; i >= 0; i--) {
      cout << i + 1 << "  ";
      for (int j = 0; j < 8; j++) {
        if (board_[i][j] == NULL) {
          cout << "  .  ";
        } else {
          cout << "  " << board_[i][j]->getSymbol() << "  ";
        }
      }
      cout << endl << endl;
    }
  }


  void ChessBoard::submitMove(const char* source, const char* destination) {

    if (!isValidPosition(source)) {
      cerr << source << " is not a valid board position.\n";
      throw(-1);
    } else if (!isValidPosition(destination)) {
      cerr << destination << " is not a valid board position.\n";
      throw(-1);
    }

    if (board_[stringToRank(source)][stringToFile(source)] == NULL) {
      cerr << "No piece located at " << source << endl;
      throw(-1);
    }
    //cout << stringToRank(source) << ',' << stringToFile(source) << endl;
    //change to boolean isValidMove
    board_[stringToRank(source)][stringToFile(source)]->tryMove(destination);

    makeMove(source, destination);
  }

  void ChessBoard::makeMove(const char* source, const char* destination) {
    board_[stringToRank(destination)][stringToFile(destination)] =
    board_[stringToRank(source)][stringToFile(source)];
    board_[stringToRank(source)][stringToFile(source)] = NULL;
    board_[stringToRank(destination)][stringToFile(destination)]->makeMove(destination);
  }

  void ChessBoard::resetBoard() {

  }
}
