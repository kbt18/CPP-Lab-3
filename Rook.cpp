#include "Rook.h"

namespace chess {

  Rook::Rook(const char* position, bool white) : ChessPiece(position, white) {
    if (white == 0) {
      white_ = false;
      symbol_ = "♜"; // colours are wrong way round
    } else {
      white_ = true;
      symbol_ = "♖";
    }
  }

  bool Rook::isValidMove(const char* destination, ChessPiece* board[][8]) {
    if (!ChessPiece::isValidMove(destination, board))
      return false;

    if (isSameDiag(destination))
      return false;

    return true;
  }

}
