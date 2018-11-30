
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"
#include <iostream>

namespace chess {

  class ChessBoard {
  public:
    ChessBoard();
    friend class ChessPiece;
    const char* checkPiecePosition(int i, int j);
    void submitMove(const char* source, const char* destination);
    void displayBoard();
    void resetBoard();
    bool isOccupied(const char* position);
    bool isPieceBetween(const char* source, const char* destination);
    bool isPieceBetweenDiag(const char* source, const char* destination);
    bool isPieceBetweenRank(const char* source, const char* destination);
    bool isPieceBetweenFile(const char* source, const char* destination);
  private:
    void makeMove(const char* source, const char* destination);
    ChessPiece* board_[8][8];
  };



}

#endif
