#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Helpers.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

namespace chess {
  class ChessPiece {
  protected:
    friend class ChessBoard;
    const char* symbol_;
    char position_[3];
    bool isWhite_;
    bool isKing_;

    ChessPiece(const char* position, bool white);
    const char* getPosition();
    const char* getSymbol();
    virtual bool isValidMove(const char* destination, ChessPiece* board[][8]);
    virtual void printName();
    virtual void setPosition(const char* p); // why is this virtual?
    bool isSameRank(const char* position);
    bool isSameFile(const char* position);
    bool isSameDiag(const char* position);
    bool isBlocked(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongDiag(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongRank(const char* destination, ChessPiece* board[][8]);
    bool isBlockedAlongFile(const char* destination, ChessPiece* board[][8]);
    bool isTakingMove(const char* target, ChessPiece* board[][8]);
    bool hasPlacedKingInCheck(ChessPiece* board[][8]);
  };
}

#endif
