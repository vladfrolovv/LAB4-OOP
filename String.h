#ifndef LAB4_OOP_STRING_H
#define LAB4_OOP_STRING_H

#include <iostream>
#include <vector>

template<class T>
class String {
  public:
    // constructors
    String();
    String(int length, T filler);
    String(std::vector<T> *from);
    String(String<T> &from);

  public:
    std::vector<T> symbols;
    int length;

    std::vector<T> AllocateString(int length);
    std::vector<T> AllocateString(std::vector<T> *from);
    std::vector<T> AllocateString(int length, T filler);

    T operator[](int index);
    template<int from, int length> std::tuple<std::vector<T>, int> GetSubstring();


    void Clear();
    int GetLength();

    bool isEmpty();
    bool OutOfBounds(int index);
};

#endif //LAB4_OOP_STRING_H
