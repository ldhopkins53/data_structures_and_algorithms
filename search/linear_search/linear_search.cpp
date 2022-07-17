#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
auto linear_search(const std::vector<T> &input_vec, const T &value)
    -> decltype(input_vec.begin()) {
  auto cur = input_vec.begin();
  while (cur < input_vec.end()) {
    if (*cur == value)
      return cur;
    ++cur;
  }
  return cur;
}

int main() {
  std::vector<int> x(10);
  std::iota(x.begin(), x.end(), 0);
  auto target_iter = linear_search(x, 5);
  std::cout << "5 is at index " << std::distance(x.cbegin(), target_iter)
            << std::endl;
  return 0;
}
