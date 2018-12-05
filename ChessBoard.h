
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <iostream>

namespace chess {

  class ChessBoard {
  public:
    friend class ChessPiece;
    ChessBoard();
    void submitMove(const char* source, const char* destination);
    bool isValidMove(const char* source, const char* destination);
    void displayBoard();
    void resetBoard();
    bool isOccupied(const char* position);
  private:
    bool isKingInCheck();
    bool moveCouldTakeKing(const char* source);
    void makeMove(const char* source, const char* destination);
    ChessPiece* board_[8][8];
  };
}

#endif
