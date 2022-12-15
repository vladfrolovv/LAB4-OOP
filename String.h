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
    String(std::vector<T> &from);
    String(String<T> &from);

  public:
    std::vector<T> symbols;
    int length;

    std::vector<T> AllocateString(int length);
    std::vector<T> AllocateString(std::vector<T> &from);
    std::vector<T> AllocateString(int length, T filler);

    T operator[](int index);
    String<T>& operator+=(String<T> string);
    String<T>& operator*=(int n);
    bool operator==(String<T> string);
    bool operator>(String<T> string);
    bool operator<(String<T> string);

    template<bool left, T s> std::vector<T> Append();
    template<int _from, int _length> std::vector<T> GetSubstring();


    void Clear();
    int GetLength();
    void Resize(int to);

    bool isEmpty();
    bool OutOfBounds(int index);

    void Output();

};

#endif //LAB4_OOP_STRING_H
