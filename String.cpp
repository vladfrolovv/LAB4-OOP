#include "String.h"

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

template <typename T>
String<T>::String() : length(0) { }

template <typename T>
String<T>::String(int length, T filler) : length(length) {
  String<T>::AllocateString(length, filler);
}

template <typename T>
String<T>::String(std::vector<T> &filler) : length(filler.size()) {
  String<T>::AllocateString(filler);
}

template <typename T>
String<T>::String(String<T> &string) : length(string.length) {
  String<T>::AllocateString(string.symbols);
}

template <typename T>
std::vector<T> String<T>::AllocateString(int length) {
  String<T>::Clear();
  String<T>::symbols.resize(length);
  return String<T>::symbols;
}

template <typename T>
std::vector<T> String<T>::AllocateString(int length, T filler) {
  String<T>::Clear();
  String<T>::symbols.resize(length);
  for (int i = 0; i < length; i++) {
    String<T>::symbols[i] = filler;
  }

  return String<T>::symbols;
}

template <typename T>
std::vector<T> String<T>::AllocateString(std::vector<T> &filler) {
  String<T>::Clear();
  String<T>::symbols.resize(filler.size());
  for (int i = 0; i < filler.size(); i++) {
    String<T>::symbols[i] = filler[i];
  }

  return String<T>::symbols;
}

template <typename T>
int String<T>::GetLength() {
  return String<T>::length;
}

template <typename T>
bool String<T>::isEmpty() {
  return (String<T>::symbols.empty());
}

template <typename T>
bool String<T>::OutOfBounds(int index) {
  return !(index >= 0 && index < String<T>::length);
}

template <typename T>
void String<T>::Clear() {
  String<T>::symbols.clear();
}

template <typename T> template <int _from, int _length>
std::vector<T> String<T>::GetSubstring() {
  if (String<T>::isEmpty()) {
    std::cout << "ERROR: string is Empty" << std::endl;
    return std::vector<T>();
  }

  if (String<T>::OutOfBounds(_from)) {
    std::cout << "ERROR: index is Out Of Bounds" << std::endl;
    return std::vector<T>();
  }

  std::vector<T> substring;
  substring.resize(min(_length + _from, String<T>::GetLength()) - _from);
  for (int i = 0; i < substring.size(); i++) {
    substring[i] = String<T>::symbols[i + _from];
  }

  return substring;
}

template <typename T>
void String<T>::Output() {
  std::string output;
  for (int i = 0; i < String<T>::GetLength(); i++) {
    output += String<T>::symbols[i];
  }

  std::cout << output << std::endl;
}

template<typename T> template <bool left, T symbol>
std::vector<T> String<T>::Append() {
  std::vector<T> string = String<T>::symbols;
  String<T>::Resize(String<T>::symbols.size() + 1);
  if(!left) {
    String<T>::symbols[String<T>::symbols.size() - 1] = symbol;
  } else {
    for (int i = String<T>::symbols.size() - 2; i >= 0; i--) {
      String<T>::symbols[i + 1] = String<T>::symbols[i];
    }
    String<T>::symbols[0] = symbol;
  }

  return String<T>::symbols;
}

template <typename T>
String<T> &String<T>::operator*=(int n) {
  std::vector<T> base = String<T>::symbols;
  String<T>::Resize(String<T>::GetLength() * n);
  for (int i = 0; i < String<T>::GetLength(); i++) {
    String<T>::symbols[i] = base[i % n];
  }

  return *this;
}

template <typename T>
T String<T>::operator[](int index) {
  if (OutOfBounds(index) || String<T>::isEmpty()) {
    std::cout << "ERROR: index is out of bounds" << std::endl;
    return ' ';
  }

  return String<T>::symbols[index];
}

template <typename T>
String<T>& String<T>::operator+=(String<T> string) {
  std::vector<T> vectorL = String<T>::symbols;
  std::vector<T> vectorR = string.symbols;
  String<T>::Resize(vectorL.size() + vectorR.size());
  for (int i = 0; i < vectorL.size(); i++) {
    String<T>::symbols[i] = vectorL[i];
  }

  for (int i = vectorL.size(); i < String<T>::GetLength(); i++) {
    String<T>::symbols[i] = vectorR[i - vectorL.size()];
  }

  return *this;
}

template <typename T>
void String<T>::Resize(int to) {
  String<T>::symbols.resize(to);
  String<T>::length = to;
}