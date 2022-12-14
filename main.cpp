#include <iostream>
#include <vector>
#include "String.cpp"

int main() {
  String<char> string(10, 'a');
  [std::vector<char> vector, int i] = string.GetSubstring<1, 4>();
  return 0;
}
