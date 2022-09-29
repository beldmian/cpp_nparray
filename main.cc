#include <iostream>
#include <vector>
#include "array.hh"

int main (int argc, char *argv[]) {
  std::vector<int> shape = {3, 2};
  Array<int> arr = Array<int>(shape);
  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[1][0] = 3;
  arr[1][1] = 4;
  arr[2][0] = 5;
  arr[2][1] = 6;
  std::cout << arr << std::endl;
  Array<int> new_arr = arr.transpose();
  std::cout << new_arr;
  return 0;
}
