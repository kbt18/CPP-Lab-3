#include "Queen.h"

namespace chess {

  Queen::Queen(const char* position, bool white) : ChessPiece(position, white) {
    if (white == 0) {
      white_ = false;
      symbol_ = "♛"; // colours are wrong way round
    } else {
      white_ = true;
      symbol_ = "♕";
    }
  }

}
