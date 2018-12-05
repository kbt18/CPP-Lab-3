
#include "Pawn.h"

namespace chess {
  Pawn::Pawn(const char* position, bool white) : ChessPiece(position, white) {}

  bool Pawn::isValidMove(const char* destination, ChessPiece* board[][8]) {
    if (!ChessPiece::isValidMove(destination, board))
      return false;

    if (!isSameFile(destination) && !isTakingMove(destination, board))
      return false;
    //else is same file or is taking move

    if (white_) {
      if (position_[1] > destination[1])
        return false;
    } else {
      if (position_[1] < destination[1])
        return false;
    }

    //dont bother with string to rank

    //must also work in opposite direction
    if (white_) {
      if (!is_first_move_) {
        if (stringToRank(destination) - stringToRank(position_) > 1)
          return false;
      } else if (stringToRank(destination) - stringToRank(position_) > 2) {
        return false;
      }
    } else {
      if (!is_first_move_) {
        if (stringToRank(position_) - stringToRank(destination) > 1)
          return false;
      } else if (stringToRank(position_) - stringToRank(destination) > 2) {
        return false;
      }
    }


    return true;
  }

  bool Pawn::isTakingMove(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(destination);
    int j = stringToFile(destination);

    if (board[i][j] == NULL)
      return false;

    if (!isSameDiag(destination))
      return false;

    //must also work in opposite direction
    if (white_) {
      if (stringToRank(destination) != stringToRank(position_) + 1)
        return false;
    } else {
      if (stringToRank(destination) != stringToRank(position_) - 1)
        return false;
    }


    return true;
  }

  void Pawn::setPosition(const char* p) {
    ChessPiece::setPosition(p);
    is_first_move_ = false;
  }
}
