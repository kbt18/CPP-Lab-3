
#include "Pawn.h"

namespace chess {
  bool Pawn::isValidMove(const char* destination, ChessPiece* board[][8]) {
    if (!ChessPiece::isValidMove(destination, board))
      return false;

    if (!isSameFile(destination) || !isTakingMove(destination, board))
      return false;

    //check first move
    

    return true;
  }

  bool Pawn::isTakingMove(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(destination);
    int j = stringToFile(destination);

    if (board[i][j] == NULL);
      return false;

    if (!isSameDiag(destination))
      return false;

    if (stringToRank(destination) != stringToRank(position_) + 1)
      return false;

    return true;
  }
}
