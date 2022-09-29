#include "array.hh"
#include <stdexcept>
#include <vector>
#include <iostream>

template<class T>
Array<T>::operator T() const {
  return *(this->data[0]);
}


template<class T>
Array<T>::Array() {
  this->shape = std::vector<int>();
}

template<class T>
Array<T>::Array(std::vector<int> shape) {
  this->shape = shape;
  size_t numbers = 1;
  for (auto num : shape) numbers *= num;
  this->data = std::vector<T*>(numbers);
  for (int i = 0; i < numbers; i++) 
    this->data[i] = new int;
}

template<class T>
Array<T>::~Array() {
  this->shape.clear();
  this->data.clear();
}

template<class T>
Array<T>& Array<T>::operator[](std::size_t i) {
  std::vector<T*> out_data = std::vector<T*>();
  for (int j = i * this->data.size() / this->shape[0]; j < (i + 1) * this->data.size() / this->shape[0]; j++) {
    out_data.push_back(this->data[j]);
  }
  std::vector<int> out_shape = std::vector<int>();
  for (int j = 1; j < this->shape.size(); j ++){
    out_shape.push_back(this->shape[j]);
  }
  Array<T>* out = new Array();
  out->shape = out_shape;
  out->data = out_data;
  return *out;
}

template<class T>
Array<T> Array<T>::operator= (Array<T> val) {
  if (this->shape != val.shape) {
    throw std::length_error("Arrays shapes not equal");
  }
  for (int i = 0; i < this->data.size(); i++)
    *this->data[i] = *val.data[i];
  return *this;
}

template<class T>
Array<T> Array<T>::operator= (T val) {
  *this->data[0] = val;
  return *this;
};

template<class T>
Array<T> Array<T>::operator+ (T const& val) {
  for (auto x : this->data)
    *x = *x + val;
  return *this;
};

template<class T>
Array<T> Array<T>::operator+ (Array<T> val) {
  if (this->shape != val.shape) {
    throw std::length_error("Arrays shapes not equal");
  }
  for (int i = 0; i < this->data.size(); i++)
    *this->data[i] += *val.data[i];
  return *this;
}

template<class T>
Array<T> Array<T>::operator- (T const& val) {
  for (auto x : this->data)
    *x = *x - val;
  return *this;
};

template<class T>
Array<T> Array<T>::operator- (Array<T> val) {
  if (this->shape != val.shape) {
    throw std::length_error("Arrays shapes not equal");
  }
  for (int i = 0; i < this->data.size(); i++)
    *this->data[i] -= *val.data[i];
  return *this;
}

template<class T>
Array<T> Array<T>::operator* (T const& val) {
  for (auto x : this->data)
    *x = *x * val;
  return *this;
};

template<class T>
Array<T> Array<T>::operator* (Array<T> val) {
  // Something harder
  return *this;
}

template<class T>
Array<T> Array<T>::operator/ (T const& val) {
  for (auto x : this->data)
    *x = *x / val;
  return *this;
};

template<class T>
Array<T> Array<T>::operator/ (Array<T> val) {
  if (this->shape != val.shape) {
    throw std::length_error("Arrays shapes not equal");
  }
  for (int i = 0; i < this->data.size(); i++)
    *this->data[i] /= *val.data[i];
  return *this;
}

template<class T>
Array<T> Array<T>::transpose() {
  if (this->shape.size() != 2) {
    throw std::logic_error("Cannot transpose nparray with not 2 dimentions");
  }
  std::vector<int>* temp_shape = new std::vector<int>{this->shape[1], this->shape[0]};
  Array<T>* temp = new Array<T>(*temp_shape);
  for (int i = 0; i < this->shape[0]; i++) {
    for (int j = 0; j < this->shape[1]; j++) {
      (*temp)[j][i] = (*this)[i][j];
    }
  }
  return *temp;
}

