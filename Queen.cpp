#include "Queen.h"

namespace chess {

  Queen::Queen(const char* position, bool white) : ChessPiece(position, white) {
    if (white == 0) {
      isWhite_ = false;
      symbol_ = "♛"; // colours are wrong way round
    } else {
      isWhite_ = true;
      symbol_ = "♕";
    }
  }

  bool Queen::isValidMove(const char* destination, ChessPiece* board[][8]) {
    printName();

    if (!ChessPiece::isValidMove(destination, board))
      return false;

    return true;
  }

  void Queen::printName() {
    if (isWhite_)
      std::cout << "White's Queen ";
    else
      std::cout << "Black's Queen ";
  }

}
