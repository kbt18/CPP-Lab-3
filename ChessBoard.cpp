
#include "ChessBoard.h"
using namespace std;

namespace chess {
  ChessBoard::ChessBoard() {
    isWhiteTurn_ = true;

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        board_[i][j] = NULL;

    board_[0][0] = new Rook("A1", 1);
    board_[0][7] = new Rook("H1", 1);
    board_[0][1] = new Bishop("B1", 1);
    board_[0][6] = new Bishop("G1", 1);
    board_[0][2] = new Knight("C1", 1);
    board_[0][5] = new Knight("F1", 1);
    board_[3][2] = new King("C4", 1);
    board_[1][0] = new Pawn("A2", 1);
    board_[1][1] = new Pawn("B2", 1);
    board_[1][2] = new Pawn("C2", 1);
    board_[1][3] = new Pawn("D2", 1);
    board_[1][4] = new Pawn("E2", 1);
    board_[1][5] = new Pawn("F2", 1);
    board_[1][6] = new Pawn("G2", 1);
    board_[1][7] = new Pawn("H2", 1);

    board_[3][7] = new Queen("H4", 0);
    board_[4][7] = new Queen("H5", 0);
    board_[5][7] = new Queen("H6", 0);
    board_[6][0] = new Pawn("A7", 0);
    board_[6][1] = new Pawn("B7", 0);
    board_[6][2] = new Pawn("C7", 0);
    board_[6][3] = new Pawn("D7", 0);
    board_[6][4] = new Pawn("E7", 0);
    board_[6][5] = new Pawn("F7", 0);
    board_[6][6] = new Pawn("G7", 0);
    board_[6][7] = new Pawn("H7", 0);

  }

  void ChessBoard::displayBoard() {
    cout << endl << "   ";
    for (int i = 0; i < 8; i++)
      cout << "  " << (char)('A' + i) << "  ";
    cout << endl << endl;

    for (int i = 7; i >= 0; i--) {
      cout << i + 1 << "  ";
      for (int j = 0; j < 8; j++) {
        if (board_[i][j] == NULL) {
          cout << "  .  ";
        } else {
          cout << "  " << board_[i][j]->getSymbol() << "  ";
        }
      }
      cout << "  " <<  i + 1;
      cout << endl << endl;
    }

    cout << "   ";
    for (int i = 0; i < 8; i++)
      cout << "  " << (char)('A' + i) << "  ";
    cout << endl << endl;
  }


  void ChessBoard::submitMove(const char* source, const char* destination) {
    //cout << "source: " << source << endl;
    //cout << "destination: " << destination << endl;
    if (isValidMove(source, destination)) {
      cout << "Move was valid\n";
      makeMove(source, destination);
      changeTurn();
      if (isKingInCheck()) {
        isKingInCheck_ = true;
        if (isKingInCheckMate())
          cout << "King is in checkmate!\n";
      } else {
        isKingInCheck_ = false;
      }
    } else {
      cerr << "NOT A VALID MOVE!\n";
    }

  }

  void ChessBoard::changeTurn() {
    if (isWhiteTurn_)
      isWhiteTurn_ = false;
    else
      isWhiteTurn_ = true;
  }

  bool ChessBoard::isOccupied(const char* position) {
    int i = stringToRank(position);
    int j = stringToFile(position);

    if (board_[i][j] == NULL)
      return false;
    return true;
  }

  bool ChessBoard::isValidMove(const char* source, const char* destination) {
    if (!isValidPosition(source))
      return false;

    if (!isValidPosition(destination))
      return false;

    if (strcmp(destination, source) == 0) {
      cerr << "destination cannot equal source\n";
      return false;
    }

    if (!isOccupied(source)) {
      cerr << "no piece at " << source << endl;
      return false;
    }

    int i_src = stringToRank(source);
    int j_src = stringToFile(source);

    if (isWhiteTurn_ != board_[i_src][j_src]->isWhite_)
      return false;

    if (!board_[i_src][j_src]->isValidMove(destination, board_))
      return false;

    //check same colour at destination
    int i_dest = stringToRank(destination);
    int j_dest = stringToFile(destination);
    if (isOccupied(destination))
      if (board_[i_src][j_src]->isWhite_ == board_[i_dest][j_dest]->isWhite_) {
        cerr << "cannot take own pieces\n";
        return false;
      }

    return true;
  }

  void ChessBoard::makeMove(const char* source, const char* destination) {
    int i_src = stringToRank(source);
    int j_src = stringToFile(source);
    int i_dest = stringToRank(destination);
    int j_dest = stringToFile(destination);

    if (isOccupied(destination))
      cout << source << " takes " << destination << endl;

    board_[i_dest][j_dest] = board_[i_src][j_src];
    board_[i_src][j_src] = NULL;
    cerr << "setting piece position to " << destination << endl;
    board_[i_dest][j_dest]->setPosition(destination);

    cerr << "piece position is now: " << board_[i_dest][j_dest]->getPosition() << endl;
  }

  void ChessBoard::resetBoard() {

  }

  bool ChessBoard::isKingInCheck() {
    char source[3];
    char rank[1], file[1];

    for (int i = 0; i < 8; i++){
      rank[0] = ('1' + i);
      for (int j = 0; j < 8; j++) {
        file[0] = ('A' + j);
        source[0] = file[0];
        source[1] = rank[0];
        source[2] = '\0';
          if (board_[i][j] != NULL)
            if (moveCouldTakeKing(source))
              return true;
      }
    }

    return false;
  }

  bool ChessBoard::isKingInCheckMate() {
    char source[3];
    char rank[1], file[1];

    if (isKingInCheck_) {
      //try all possible valid moves
      for (int i = 0; i < 8; i++){
        rank[0] = ('1' + i);
        for (int j = 0; j < 8; j++) {
          file[0] = ('A' + j);
          source[0] = file[0];
          source[1] = rank[0];
          source[2] = '\0';
            if (board_[i][j] != NULL)
              if (moveUnchecksKing(source))
                return false;
        }
      }
    }

    return true;
  }

  bool ChessBoard::moveUnchecksKing(const char* source) {
    char destination[3];
    char rank[1], file[1];

    for (int i = 0; i < 8; i++) {
      rank[0] = ('1' + i);
      for (int j = 0; j < 8; j++) {
        file[0] = ('A' + j);
        destination[0] = file[0];
        destination[1] = rank[0];
        destination[2] = '\0';
        if (isValidMove(source, destination)) {
          makeMove(source, destination);
          if (!isKingInCheck()) {
            makeMove(destination, source);
            return true;
          }
          makeMove(destination, source);
        }
      }
    }

    return false;
  }

  bool ChessBoard::moveCouldTakeKing(const char* source) {
    char destination[3];
    char rank[1], file[1];
    //changeTurn();

    for (int i = 0; i < 8; i++) {
      rank[0] = ('1' + i);
      for (int j = 0; j < 8; j++) {
        file[0] = ('A' + j);
        destination[0] = file[0];
        destination[1] = rank[0];
        destination[2] = '\0';
        if (board_[i][j] != NULL)
          if (board_[i][j]->isKing_)
            if (isValidMove(source, destination)) {
              cout << "A king is in check!\n";
              return true;
            }
      }
    }

    return false;
  }
}
