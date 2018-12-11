#include "Bishop.h"

Bishop::Bishop(const char* position, bool white) : ChessPiece(position, white) {
  if (white == 0) {
    isWhite_ = false;
    symbol_ = "♝";
  } else {
    isWhite_ = true;
    symbol_ = "♗";
  }
}

bool Bishop::isValidMove(const char* destination, ChessPiece* board[][8]) {

  if (!ChessPiece::isValidMove(destination, board))
    return false;

  if (!isSameDiag(destination))
    return false;

  return true;
}

void Bishop::printName() {
  if (isWhite_)
    std::cout << "White's Bishop ";
  else
    std::cout << "Black's Bishop ";
}
