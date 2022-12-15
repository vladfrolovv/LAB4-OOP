#include <iostream>
#include <vector>
#include "String.cpp"

using namespace std;

int main() {
  String<char> string(10, 'a');
  string.Output();

  std::vector<char> vector = string.GetSubstring<1, 2>();
  String<char> mainSubstring(vector);
  mainSubstring.Output();

  mainSubstring += string;
  mainSubstring.Output();
  mainSubstring.Append<true, 'b'>();
  mainSubstring.Append<false, 'c'>();
  mainSubstring.Output();

  mainSubstring *= 3;
  mainSubstring.Output();

  return 0;
}
