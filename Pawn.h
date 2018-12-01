#include "ChessPiece.h"

namespace chess {
  class Pawn : public ChessPiece {
  public:
    bool isValidMove(const char* destination, ChessPiece* board[][8]);
  private:
    bool is_first_move_ = true;
    bool isTakingMove(const char* destination, ChessPiece* board[][8]);
  }

}
