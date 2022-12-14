#include <iostream>
#include <vector>
#include "String.cpp"

using namespace std;

int main() {
  String<char> string(10, 'a');

  std::vector<char> vector = string.GetSubstring<1, 2>();
  String<char> mainSubstring(vector);
  mainSubstring.Output();

  return 0;
}
