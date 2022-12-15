#include <iostream>
#include <vector>
#include "String.cpp"

using namespace std;

int main() {
  cout << "\t Created String" << endl;
  String<char> string(10, 'a');
  string.Output();

  cout << "\t Getting Substring of main string" << endl;
  std::vector<char> vector = string.GetSubstring<1, 2>();
  String<char> mainSubstring(vector);
  mainSubstring.Output();

  cout << "\t Adding Substring to main string" << endl;
  string += mainSubstring;
  string.Output();

  cout << "\t Appending" << endl;
  string.Append<true, 'b'>();
  string.Append<false, 'c'>();
  string.Output();

  cout << "\t String Repeater" << endl;
  string *= 3;
  string.Output();

  cout << "\t String Compare" << endl;
  cout << "\t string == Substring: " << (string == mainSubstring) << endl;
  cout << "\t string < Substring: " << (string < mainSubstring) << endl;
  cout << "\t string > Substring: " << (string > mainSubstring) << endl;

  String<char> _string(string);
  cout << "\t string == string: " << (string == _string) << endl;

  return 0;
}
