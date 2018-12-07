
#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() {
  resetBoard();
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

  if (isValidMove(source, destination)) {
    cout << "moves from " << source << " to " << destination;
    if (!isOccupied(destination))
      cout << endl;
    else {
      int i = stringToRank(destination);
      int j = stringToFile(destination);
      cout << " taking ";
      board_[i][j]->printName();
      cout << endl;
    }
    makeMove(source, destination);
    changeTurn();
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
  if (!isValidPosition(source)) {
    cout << "Source is not valid!\n";
    return false;
  }

  if (!isValidPosition(destination)) {
    cout << "Destination is not valid!\n";
    return false;
  }

  if (strcmp(destination, source) == 0) {
    cout << "Destination cannot equal source!\n";
    return false;
  }

  if (!isOccupied(source)) {
    cerr << "There is no piece at position " << source << "!\n";
    return false;
  }

  int i_src = stringToRank(source);
  int j_src = stringToFile(source);

  if (isWhiteTurn_ && !board_[i_src][j_src]->isWhite_) {
    cout << "It is not Black's turn to move!\n";
    return false;
  } else if (!isWhiteTurn_ && board_[i_src][j_src]->isWhite_) {
    cout << "It is not White's turn to move!\n";
    return false;
  }


  if (!board_[i_src][j_src]->isValidMove(destination, board_)) {
    cout << "cannot move to " << destination << "!\n";
    return false;
  }

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

  board_[i_dest][j_dest] = board_[i_src][j_src];
  board_[i_src][j_src] = NULL;
  board_[i_dest][j_dest]->setPosition(destination);

}

void ChessBoard::resetBoard() {
  cout << "A new chess game is started!\n";

  isWhiteTurn_ = true;

  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      board_[i][j] = NULL;


  char position[3];
  position[2] = '\0';
  for (int i = 0; i < 8; i++) {
    position[0] = (char)('A' + i);
    position[1] = '2';
    board_[1][i] = new Pawn(position, 1);

    position[1] = '7';
    board_[6][i] = new Pawn(position, 0);
  }

  board_[0][0] = new Rook("A1", 1);
  board_[0][7] = new Rook("H1", 1);
  board_[7][0] = new Rook("A8", 0);
  board_[7][7] = new Rook("H8", 0);

  board_[0][1] = new Knight("B1", 1);
  board_[0][6] = new Knight("G1", 1);
  board_[7][1] = new Knight("B8", 0);
  board_[7][6] = new Knight("G8", 0);

  board_[0][2] = new Bishop("C1", 1);
  board_[0][5] = new Bishop("F1", 1);
  board_[7][2] = new Bishop("C8", 0);
  board_[7][5] = new Bishop("F8", 0);

  board_[0][3] = new Queen("D1", 1);
  board_[0][4] = new King("E1", 1);
  board_[7][3] = new Queen("D8", 0);
  board_[7][4] = new King("E8", 0);

}

bool ChessBoard::isKingInCheck(int& a, int& b) {
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
          if (moveCouldTakeKing(source, a, b))
            return true;
    }
  }

  return false;
}

bool ChessBoard::moveCouldTakeKing(const char* source, int& i, int& j) {
  char destination[3];
  char rank[1], file[1];

  for (i = 0; i < 8; i++) {
    rank[0] = ('1' + i);
    for (j = 0; j < 8; j++) {
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
