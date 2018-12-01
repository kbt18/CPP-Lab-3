
#include "ChessPiece.h"

using namespace std;
namespace chess {

  ChessPiece::ChessPiece(const char* position, bool white) {

    if (isValidPosition(position))
      strcpy(position_, position);
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
    cerr << "piece position is " << position_ << endl;
    if (isSameRank(destination)) {
      cerr << "file move\n";
      if (isBlockedAlongRank(destination, board))
        return true;
    }

    if (isSameFile(destination)) {
      cerr << "rank move\n";
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

    if (j > end)
      swapValues(j, end);

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

    if (i > end)
      swapValues(i, end);

    i++;

    for (; i < end; i++)
      if (board[i][j] != NULL)
        return true;

    return false;
  }

  bool ChessPiece::isBlockedAlongDiag(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(position_);
    int j = stringToFile(position_);
    int endi = stringToRank(destination);
    int endj = stringToFile(destination);

    //left to right down
    if (i > endi && j < endj) {
      i--;
      j++;
      while (i > endi && j < endj) {
        if (board[i][j] != NULL)
          return true;
        i--;
        j++;
      }
    }

    //left to right up
    if (i < endi && j < endj) {
      i++;
      j++;
      while ((i < endi) && (j < endj)) {
        if (board[i][j] != NULL)
          return true;
        i++;
        j++;
      }
    }




    return false;
  }

  void ChessPiece::setPosition(const char* p) {
    strcpy(position_, p); //fuck this bug
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
