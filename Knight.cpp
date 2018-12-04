#include "Knight.h"


namespace chess {

  Knight::Knight(const char* position, bool white) : ChessPiece(position, white) {
    if (white == 0) {
      white_ = false;
      symbol_ = "♞";
    } else {
      white_ = true;
      symbol_ = "♘";
    }
  }

  bool Knight::isValidMove(const char* destination, ChessPiece* board[][8]) {
    if (isSameDiag(destination))
      return false;
    if (isSameFile(destination))
      return false;
    if (isSameRank(destination))
      return false;



    return true;
  }

}
