#include "array.hh"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> shape = {3, 2};
  Array<int> arr = Array<int>(shape);
  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[1][0] = 3;
  arr[1][1] = 4;
  arr[2][0] = 5;
  arr[2][1] = 6;
  std::cout << arr << std::endl;
  Array<int> vec = Array<int>(std::vector<int>{2, 2});
  vec[0][0] = 1;
  vec[0][1] = 2;
  vec[1][0] = 3;
  vec[1][1] = 4;
  std::cout << vec << std::endl;
  Array<int> out = arr * vec;
  std::cout << out << std::endl;
  return 0;
}
