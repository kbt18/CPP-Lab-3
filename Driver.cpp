
#include "ChessBoard.h"
#include <iostream>
#include <string>

using namespace chess;
using namespace std;

int main() {
//   if (!isValidPosition("B8"))
//     std::cout << "invalid\n";
//   else
//     std::cout << "valid\n";

  ChessBoard testboard;
  string source;
  string destination;
  const char* c_source;
  const char* c_destination;
  while (true) {
    testboard.displayBoard();
    cout << "Move: ";
    cin >> source;
    cout << "Destination: ";
    cin >> destination;
    c_source = source.c_str();
    c_destination = destination.c_str();
    testboard.submitMove(c_source, c_destination);
  }
  testboard.displayBoard();

  //testboard.submitMove("A2", "B4");
  testboard.submitMove("A2", "A6");

  testboard.displayBoard();

  //testboard.submitMove("A4", "B7");

  return 0;
}
