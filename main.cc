#include <iostream>
#include <vector>
#include "array.hh"

int main (int argc, char *argv[])
{
  std::vector<int> shape = {2, 3};
  Array<int> arr = Array<int>(shape);
  Array<int> b = Array<int>(std::vector<int>({3}));
  b[0] = 3;
  b[1] = 2;
  b[2] = 1;
  arr[0] = b;
  arr = arr * 2;
  std::cout << arr << std::endl;
  arr.transpose();
  std::cout << arr;
  return 0;
}
