
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
    //cout << "source: " << source << endl;
    //cout << "destination: " << destination << endl;
    if (isValidMove(source, destination)) {
      cout << "Move was valid\n";
      makeMove(source, destination);
    } else {
      cerr << "NOT A VALID MOVE!\n";
    }

  }

  bool ChessBoard::isOccupied(const char* position) {
    int i = stringToRank(position);
    int j = stringToFile(position);

    if (board_[i][j] == NULL)
      return false;
    return true;
  }

  bool ChessBoard::isValidMove(const char* source, const char* destination) {
    if (!isValidPosition(source))
      return false;

    if (!isValidPosition(destination))
      return false;

    if (!isOccupied(source)) {
      cerr << "no piece at " << source << endl;
      return false;
    }

    int i_src = stringToRank(source);
    int j_src = stringToFile(source);

    if (!board_[i_src][j_src]->isValidMove(destination, board_))
      return false;

    return true;
  }

  void ChessBoard::makeMove(const char* source, const char* destination) {
    int i_src = stringToRank(source);
    int j_src = stringToFile(source);
    int i_dest = stringToRank(destination);
    int j_dest = stringToFile(destination);

    board_[i_dest][j_dest] = board_[i_src][j_src];
    board_[i_src][j_src] = NULL;
    cerr << "setting piece position to " << destination << endl;
    board_[i_dest][j_dest]->setPosition(destination);

    cerr << "piece position is now: " << board_[i_dest][j_dest]->getPosition() << endl;
  }

  void ChessBoard::resetBoard() {

  }
}
