#include "String.h"

template <typename T>
String<T>::String() : length(0) { }

template <typename T>
String<T>::String(int length, T filler) : length(length) {
  String<T>::AllocateString(length, filler);
}

template <typename T>
String<T>::String(std::vector<T> *filler) : length(length) {
  String<T>::AllocateString(filler);
}

template <typename T>
String<T>::String(String<T> &string) : length(length) {
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
std::vector<T> String<T>::AllocateString(std::vector<T> *filler) {
  String<T>::Clear();
  String<T>::symbols.resize(filler->size());
  for (int i = 0; i < filler->size(); i++) {
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

template <typename T>
T String<T>::operator[](int index) {
  if (OutOfBounds(index) || String<T>::isEmpty()) {
    std::cout << "ERROR: index is out of bounds" << std::endl;
    return ' ';
  }

  return String<T>::symbols[index];
}

template <typename T> template <int from, int length>
std::tuple<std::vector<T>, int> String<T>::GetSubstring() {
  if (String<T>::isEmpty()) {
    return { new std::vector<T>, 0 };
  }

  return this;
}
