#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
  Pawn(const char* position, bool white);

private:
  bool isValidMove(const char* destination, ChessPiece* board[][8]); 
  void printName();
  bool is_first_move_;
  bool isTakingMove(const char* destination, ChessPiece* board[][8]);
  void setPosition(const char* p);
};

#endif
