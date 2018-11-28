
#include "Helpers.h"
#include <iostream>
#include <cctype>

namespace chess {
  class ChessPiece {
  public:
    ChessPiece();
    void setPosition(const char* position);
    void tryMove(const char* destination);
    const char* getSymbol();
    bool isValidMove(const char* destination);
    bool isSameRank(const char* position);
    bool isSameFile(const char* position);
    bool isSameDiag(const char* position);
    bool isPieceBetween(const char* destination);
    bool isPieceBetweenDiag(const char* destination);
    bool isPieceBetweenRank(const char* destination);
    bool isPieceBetweenFile(const char* destination);
  private:
    const char* symbol;
    const char* position_;
  };
}