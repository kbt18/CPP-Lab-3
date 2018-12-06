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

}
