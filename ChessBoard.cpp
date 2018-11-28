
#include "ChessBoard.h"
using namespace std;

namespace chess {
  ChessBoard::ChessBoard() {

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        board_[i][j] = NULL;

    for (int i = 0; i < 8; i++) {
      board_[1][i] = new ChessPiece;
      board_[6][i] = new ChessPiece;
    }
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

    board_[stringToRank(source)][stringToFile(source)]->tryMove(destination);
  }

  void ChessBoard::resetBoard() {

  }
}
