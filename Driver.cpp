
#include "ChessBoard.h"
#include <iostream>

using namespace chess;
using namespace std;

int main() {
//   if (!isValidPosition("B8"))
//     std::cout << "invalid\n";
//   else
//     std::cout << "valid\n";

  ChessBoard testboard;
  testboard.displayBoard();

  testboard.submitMove("A2", "B4");

  return 0;
}
