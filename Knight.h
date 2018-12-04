#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

namespace chess {
  class Knight : public ChessPiece {
  public:
    Knight(const char* position, bool white);
    bool isValidMove(const char* destination, ChessPiece* board[][8]); //can be private?
  private:

  };

}

#endif
