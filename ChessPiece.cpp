
#include "ChessPiece.h"

using namespace std;
namespace chess {

  ChessPiece::ChessPiece(const char* position, bool white) {

    if (isValidPosition(position))
      position_ = position;
    else {
      cerr << "invalid position\n";
      throw(-1);
    }
    if (white == 0) {
      white_ = 0;
      symbol_ = "♙";
    } else {
      white = 1;
      symbol_ = "♟";
    }

  }

  const char* ChessPiece::getPosition() {
    return position_;
  }

  bool ChessPiece::isValidMove(const char* destination, ChessPiece* board[][8]) {

    if (!(isSameRank(destination) || isSameFile(destination) ||
      isSameDiag(destination))) {
        cerr << "not same rank, file or diagonal\n";
        return false;
    }

    if (isBlocked(destination, board)) {
      cerr << "piece is blocking move\n";
      return false;
    }

    return true;
  }

  bool ChessPiece::isBlocked(const char* destination, ChessPiece* board[][8]) {
    if (isSameRank(destination)) {
      cerr << "Rank move\n";
      if (isBlockedAlongRank(destination, board))
        return true;
    }

    if (isSameFile(destination)) {
      cerr << "File move\n";
      if (isBlockedAlongFile(destination, board))
        return true;
    }

    if (isSameDiag(destination)) {
      cerr << "Diagonal move\n";
      if (isBlockedAlongDiag(destination, board))
        return true;
    }

    return false;
  }

  bool ChessPiece::isBlockedAlongRank(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(position_);
    int j = stringToFile(position_);
    int end = stringToFile(destination);
    j++;

    for (; j < end; j++)
      if (board[i][j] != NULL)
        return true;

    return false;
  }

  bool ChessPiece::isBlockedAlongFile(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(position_);
    int j = stringToFile(position_);
    int end = stringToRank(destination);
    i++;

    for (; i < end; i++)
      if (board[i][j] != NULL)
        return true;

    return false;
  }

  bool ChessPiece::isBlockedAlongDiag(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(position_);
    int j = stringToFile(position_);
    i++;
    j++;

    int endi = stringToRank(destination);
    int endj = stringToFile(destination);

    while ((i < endi) && (j < endj)) {
      if (board[i][j] != NULL)
        return true;
      i++;
      j++;
    }

    return false;
  }

  void ChessPiece::setPosition(const char* p) {
    position_ = p;
  }

  bool ChessPiece::isSameRank(const char* position) {
    if (position[1] == position_[1])
      return true;
    return false;
  }

  bool ChessPiece::isSameFile(const char* position) {
    if (position[0] == position_[0])
      return true;
    return false;
  }

  bool ChessPiece::isSameDiag(const char* position) {
    if (abs(position[0] - position_[0]) == abs(position[1] - position_[1]))
      return true;
    return false;
  }

  const char* ChessPiece::getSymbol() {
    return symbol_;
  }
}
