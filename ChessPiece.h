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
    const char* getSymbol();
    //make private as much stuff as possible
    //alternatively, make stuff helper functions
    bool isValidMove(const char* destination, ChessPiece* board[][8]);
    bool isBlocked(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongDiag(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongRank(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongFile(const char* destination, ChessPiece* board[][8]);

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
