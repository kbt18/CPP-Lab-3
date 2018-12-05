#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Helpers.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

namespace chess {
  class ChessPiece {
  public:
    friend class ChessBoard;
    ChessPiece(const char* position, bool white);
    const char* getPosition();

    const char* getSymbol();
    //make private as much stuff as possible
    //alternatively, make stuff helper functions
    virtual bool isValidMove(const char* destination, ChessPiece* board[][8]);
    bool isBlocked(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongDiag(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongRank(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongFile(const char* destination, ChessPiece* board[][8]);

  protected:
    const char* symbol_;
    virtual void setPosition(const char* p);
    char position_[3];
    bool isSameRank(const char* position);
    bool isSameFile(const char* position);
    bool isSameDiag(const char* position);
    bool white_;
    bool isKing_;
    bool isTakingMove(const char* target, ChessPiece* board[][8]);
    bool hasPlacedKingInCheck(ChessPiece* board[][8]);
  };
}

#endif
