
#include "Helpers.h"
#include <iostream>
#include <cctype>
#include <cmath>

namespace chess {
  class ChessPiece {
  public:
    ChessPiece(const char* position, bool white);
    const char* getPosition();
    void setPosition(const char* position);
    void tryMove(const char* destination);
    const char* getSymbol();
    //make private as much stuff as possible
    //alternatively, make stuff helper functions
    bool isValidMove(const char* destination);
    void makeMove(const char* destination);
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
    bool white_;
  };
}
