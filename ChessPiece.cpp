
#include "ChessPiece.h"

using namespace std;
namespace chess {

  ChessPiece::ChessPiece(const char* position) {
    symbol = "♟";
    if (isValidPosition(position))
      position_ = position;
    else {
      cerr << "invalid position\n";
      throw(-1);
    }
  }

  const char* ChessPiece::getPosition() {
    return position_;
  }

  void ChessPiece::setPosition(const char* position) {
    if (isValidPosition(position))
      position_ = position;
  }

  void ChessPiece::tryMove(const char* destination) {
    if (!(isSameRank(destination) || isSameFile(destination) ||
      isSameDiag(destination))) {
        std::cerr << "invalid destination\n";
        throw (-1);
    }

    // if (isPieceBetween(destination)) {
    //   std::cerr << "cant jump over pieces\n";
    //   throw(-1);
    // }
  }

  bool ChessPiece::isSameRank(const char* position) {
    if (position[1] == position_[1])
      return true;
    return false;
  }

  bool ChessPiece::isSameFile(const char* position) {
    if (position[0] == position_[0])
      return true;
    return false;
  }

  bool ChessPiece::isSameDiag(const char* position) {
    if (abs(position[0] - position_[0]) == abs(position[1] - position_[1]))
      return true;
    return false;
  }

  const char* ChessPiece::getSymbol() {
    return symbol;
  }
}
