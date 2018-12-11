#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
public:
  Rook(const char* position, bool white);
private:
  void printName();
  bool isValidMove(const char* destination, ChessPiece* board[][8]); //can be private?
};

#endif
