#ifndef HELPERS_H
#define HELPERS_H

namespace chess {
  bool isValidPosition(const char* position);

  int stringToRank(const char* position);

  int stringToFile(const char* position);
}

#endif
