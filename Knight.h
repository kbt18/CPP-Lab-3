#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

class Knight : public ChessPiece {
public:
  Knight(const char* position, bool white);
private:
  bool isValidMove(const char* destination, ChessPiece* board[][8]);
  void printName();
};

#endif
