#include "Knight.h"

using namespace std;
namespace chess {

  Knight::Knight(const char* position, bool white) : ChessPiece(position, white) {
    if (white == 0) {
      isWhite_ = false;
      symbol_ = "♞";
    } else {
      isWhite_ = true;
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

    if (abs(destination[0] - position_[0]) != 2 &&
    abs(destination[1] - position_[1]) != 2)
      return false;

    if (abs(destination[0] - position_[0]) > 2 ||
    abs(destination[1] - position_[1]) > 2)
      return false;

    return true;
  }

}
