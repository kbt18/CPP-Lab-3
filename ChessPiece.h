#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Helpers.h"
#include <iostream>
#include <cctype>
#include <cmath>

namespace chess {
  class ChessPiece {
  public:
    ChessPiece(const char* position, bool white);
    const char* getPosition();
    void setPosition(const char* p);
    void tryMove(const char* destination);
    const char* getSymbol();
    //make private as much stuff as possible
    //alternatively, make stuff helper functions
    bool isValidMove(const char* destination, ChessPiece* board[][8]);
    bool isPieceBetween(const char* destination, ChessPiece* board[][8]);
    bool isPieceBetweenDiag(const char* destination, ChessPiece* board[][8]);
    bool isPieceBetweenRank(const char* destination, ChessPiece* board[][8]);
    bool isPieceBetweenFile(const char* destination, ChessPiece* board[][8]);

  private:
    bool isSameRank(const char* position);
    bool isSameFile(const char* position);
    bool isSameDiag(const char* position);
    const char* symbol_;
    const char* position_;
    bool white_;
  };
}

#endif
