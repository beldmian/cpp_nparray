#include <iostream>
#include <vector>

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
    Array<T> operator- (Array<T> const&);
    Array<T> operator* (T const&);
    Array<T> operator* (Array<T> const&);
    Array<T> operator/ (T const&);
    Array<T> operator/ (Array<T> const&);

    Array<T> operator== (Array<T> const&);
    Array<T> operator!= (Array<T> const&);
    Array<T> operator< (Array<T> const&);
    Array<T> operator<= (Array<T> const&);
    Array<T> operator> (Array<T> const&);
    Array<T> operator>= (Array<T> const&);

    operator T() const;

    Array<T>& operator[] (size_t);
    Array<T> operator[] (size_t) const;

    Array<T> transpose();
};

template<typename T>
Array<T>::operator T() const {
  return *(this->data[0]);
}

template<typename T>
std::ostream& operator<< (std::ostream& o, Array<T> arr) {
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
};

template<typename T>
Array<T>::Array() {
  this->shape = std::vector<int>();
}

template<typename T>
Array<T>::Array(std::vector<int> shape) {
  this->shape = shape;
  size_t numbers = 1;
  for (auto num : shape) numbers *= num;
  this->data = std::vector<T*>(numbers);
  for (int i = 0; i < numbers; i++) 
    this->data[i] = new int;
}

template<typename T>
Array<T>::~Array() {
  this->shape.clear();
  this->data.clear();
}

template<typename T>
Array<T>& Array<T>::operator[](size_t i) {
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

template<typename T>
Array<T> Array<T>::operator= (Array<T> val) {
  if (this->shape != val.shape) {
    throw std::length_error("Arrays shapes not equal");
  }
  for (int i = 0; i < this->data.size(); i++)
    *this->data[i] = *val.data[i];
  return *this;
}

template<typename T>
Array<T> Array<T>::operator= (T val) {
  *this->data[0] = val;
  return *this;
};

template<typename T>
Array<T> Array<T>::operator+ (T const& val) {
  for (auto x : this->data)
    *x = *x + val;
  return *this;
};

template<typename T>
Array<T> Array<T>::operator+ (Array<T> val) {
  if (this->shape != val.shape) {
    throw std::length_error("Arrays shapes not equal");
  }
  for (int i = 0; i < this->data.size(); i++)
    *this->data[i] += *val.data[i];
  return *this;
}

template<typename T>
Array<T> Array<T>::operator- (T const& val) {
  for (auto x : this->data)
    *x = *x - val;
  return *this;
};

template<typename T>
Array<T> Array<T>::operator* (T const& val) {
  for (auto x : this->data)
    *x = *x * val;
  return *this;
};

template<typename T>
Array<T> Array<T>::operator/ (T const& val) {
  for (auto x : this->data)
    *x = *x / val;
  return *this;
};

int main (int argc, char *argv[])
{
  std::vector<int> shape = {2, 5, 3};
  Array<int> arr = Array<int>(shape);
  Array<int> b = Array<int>(std::vector<int>({3}));
  b[0] = 3;
  b[1] = 2;
  b[2] = 1;
  std::cout << b << std::endl;
  arr[0][0] = b;
  arr = (arr + 1) * 32;
  std::cout << arr;
  return 0;
}
