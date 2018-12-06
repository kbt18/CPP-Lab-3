#include "King.h"

using namespace std;
namespace chess {

  King::King(const char* position, bool white) : ChessPiece(position, white) {
    isKing_ = true;
    if (white == 0) {
      isWhite_ = false;
      symbol_ = "♚"; // colours are wrong way round
    } else {
      isWhite_ = true;
      symbol_ = "♔";
    }
  }

  bool King::isValidMove(const char* destination, ChessPiece* board[][8]) {
    if (!ChessPiece::isValidMove(destination, board))
      return false;

    if (abs(destination[0] - position_[0]) > 1)
      return false;

    if (abs(destination[1] - position_[1]) > 1)
      return false;

    return true;
  }


}
