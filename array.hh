#include <vector>
#include <iostream>
#pragma once

template<typename T>
class Array {
  public:
    std::vector<int> shape;
    std::vector<T*> data;

    Array<T>();
    Array<T>(std::vector<int>);

    ~Array();

    Array<T> operator= (T);
    Array<T> operator= (Array<T>);

    Array<T> operator+ (T const&);
    Array<T> operator+ (Array<T>);
    Array<T> operator- (T const&);
    Array<T> operator- (Array<T>);
    Array<T> operator* (T const&);
    Array<T> operator* (Array<T>);
    Array<T> operator/ (T const&);
    Array<T> operator/ (Array<T>);

    Array<T> operator== (Array<T> const&);
    Array<T> operator!= (Array<T> const&);

    operator T() const;

    Array<T>& operator[] (std::size_t);

    Array<T> transpose();
};

template class Array<int>;

template<class T>
std::ostream& operator<< (std::ostream& o, Array<T> arr) {
  if ( arr.data.size() == 0 ) {
    o << "[]";
    return o;
  }
  if (arr.shape.size() == 0 ) {
    o << *arr.data[0];
    return o;
  }
  o << "[";
  if (arr.shape.size() == 1) {
    for(int i = 0; i < arr.shape[0] - 1; i++) {
      o << *arr.data[i] << ", ";
    }
    o << *arr.data[arr.data.size()-1];
  } else {
    for(int i = 0; i < arr.shape[0] - 1; i++) {
      o << arr[i] << ", ";
    }
    o << arr[arr.shape[0]-1];
  }
  o << "]";
  return o;
}

