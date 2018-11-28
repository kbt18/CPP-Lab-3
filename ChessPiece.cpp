
#include "ChessPiece.h"


namespace chess {

  ChessPiece::ChessPiece() {
    symbol = "♟";
  }

  void ChessPiece::setPosition(const char* position) {
    if (isValidPosition(position))
      position_ = position;
  }

  void ChessPiece::tryMove(const char* destination) {
    if (!isSameRank(destination) || !isSameFile(destination) ||
      !isSameDiag(destination)) {
        std::cerr << "invalid destination\n";
        throw (-1);
    }

    if (isPieceBetween(destination)) {
      std::cerr << "cant jump over pieces\n";
      throw(-1);
    }

  }

  const char* ChessPiece::getSymbol() {
    return symbol;
  }


}
