
#include "ChessPiece.h"

using namespace std;
namespace chess {

  ChessPiece::ChessPiece(const char* position, bool white) {

    if (isValidPosition(position))
      position_ = position;
    else {
      cerr << "invalid position\n";
      throw(-1);
    }
    if (white == 0) {
      white_ = 0;
      symbol_ = "♙";
    } else {
      white = 1;
      symbol_ = "♟";
    }

  }

  const char* ChessPiece::getPosition() {
    return position_;
  }

  void ChessPiece::setPosition(const char* position) {
    if (isValidPosition(position))
      position_ = position;
  }

  bool ChessPiece::isValidMove(const char* destination, ChessPiece* board[][8]) {
    if (!(isSameRank(destination) || isSameFile(destination) ||
      isSameDiag(destination))) {
        return false;
    }

    if (isPieceBetween(destination, board)) {
      return false;
    }

    return true;
  }

  bool ChessPiece::isPieceBetween(const char* destination, ChessPiece* board[][8]) {
    if (isPieceBetweenRank(destination, board) || isPieceBetweenFile(destination, board) ||
      isPieceBetweenDiag(destination, board))
        return true;
    return false;
  }

  bool ChessPiece::isPieceBetweenRank(const char* destination, ChessPiece* board[][8]) {
    int i = stringToRank(position_);
    int j = stringToFile(position_);

    int end = stringToRank(destination);

    for (; i < end - 1; i++) {
      if (board[i][j] != NULL);
        //return true;
    }

    return false;
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

  void ChessPiece::makeMove(const char* destination) {
    position_ = destination;
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
    return symbol_;
  }
}
