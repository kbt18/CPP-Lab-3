#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

namespace chess {
  class King : public ChessPiece {
  public:
    King(const char* position, bool white);
    bool isValidMove(const char* destination, ChessPiece* board[][8]);
  private:

  };

}

#endif
