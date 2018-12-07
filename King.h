#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class King : public ChessPiece {
public:
  King(const char* position, bool white);
  bool isValidMove(const char* destination, ChessPiece* board[][8]);
private:
  void printName();
};


#endif
