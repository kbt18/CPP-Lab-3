#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"

class Queen : public ChessPiece {
public:
  Queen(const char* position, bool white);
private:
  void printName();
  bool isValidMove(const char* destination, ChessPiece* board[][8]);
};


#endif
