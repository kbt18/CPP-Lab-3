
#include "ChessBoard.h"
using namespace std;

namespace chess {
  ChessBoard::ChessBoard() {

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        board_[i][j] = NULL;

    // for (int i = 0; i < 8; i++) {
    //   char c1 = (char)(i + 'A');
    //   char c2 = (char)(i + 'A');
    //   const char* p1 = {c1 , '7', '\0'};
    //   const char* p2 = {c2 , '2', '\0'};
    //   //cout << p1 << ' ' << p2 << endl;
    //   board_[1][i] = new ChessPiece(p2);
    //   board_[6][i] = new ChessPiece(p1);
    //   cout << checkPiecePosition(6, i) << ' ';
    //   cout << checkPiecePosition(1, i) << endl;
    // }

    board_[1][0] = new ChessPiece("A2");
    board_[1][1] = new ChessPiece("B2");
    board_[1][2] = new ChessPiece("C2");
    board_[1][3] = new ChessPiece("D2");
    board_[1][4] = new ChessPiece("E2");
    board_[1][5] = new ChessPiece("F2");
    board_[1][6] = new ChessPiece("G2");
    board_[1][7] = new ChessPiece("H2");


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
    board_[stringToRank(source)][stringToFile(source)]->tryMove(destination);
  }

  void ChessBoard::resetBoard() {

  }
}
