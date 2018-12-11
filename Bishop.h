#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class Bishop : public ChessPiece {
public:
  Bishop(const char* position, bool white);
private:
  bool isValidMove(const char* destination, ChessPiece* board[][8]);
  void printName();
};


#endif
