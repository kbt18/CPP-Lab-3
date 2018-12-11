
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "errors.h"
#include <iostream>

class ChessBoard {
public:
  ChessBoard();
  void submitMove(const char* source, const char* destination);
  // source is the square of the piece you wish to move.
  // destination is the square where you wish to move the piece at source.
  
  void displayBoard();
  void resetBoard();
private:
  void isValidMove(const char* source, const char* destination);
  bool isOccupied(const char* position);
  void changeTurn();
  bool isWhiteTurn_;
  bool isWhiteInCheck_;
  bool isBlackInCheck_;
  bool isKingInCheck(int& a, int& b);
  bool moveCouldTakeKing(const char* source, int& i, int& j);
  void makeMove(const char* source, const char* destination);
  ChessPiece* board_[8][8];
};

#endif
