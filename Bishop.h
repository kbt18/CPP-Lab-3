#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

namespace chess {
  class Bishop : public ChessPiece {
  public:
    Bishop(const char* position, bool white);

    bool isValidMove(const char* destination, ChessPiece* board[][8]); //can be private?
  private:
    void printName();
  };

}

#endif
