

namespace chess {

  bool isValidPosition(const char* position) {
    int char_count = 0;
    while (position[char_count] != '\0')
      char_count++;

    if (char_count != 2)
      return false;

    if (position[0] < 'A' || position[0] > 'H')
      return false;

    if (position[1] < '1' || position[1] > '8')
      return false;

    return true;
  }

  int stringToRank(const char* position) {
    return ((int)(position[1] - '1'));
  }

  int stringToFile(const char* position) {
    return ((int)(position[0] - 'A'));
  }

}
