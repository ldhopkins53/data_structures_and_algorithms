#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

template <typename T> void display_vector(const std::vector<T> &input_vec) {
  for (const auto &i : input_vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T>
auto binary_search(const std::vector<T> &input_vec, const T &value)
    -> decltype(input_vec.begin()) {
  auto left = input_vec.begin();
  auto right = input_vec.end();
  while (left < right) {
    auto mid = left + std::distance(left, right) / 2;
    if (*mid < value)
      left = mid + 1;
    else if (*mid > value)
      right = mid - 1;
    else
      return mid;
  }
  return input_vec.end();
}

int main() {
  std::vector<int> x(10);
  std::iota(x.begin(), x.end(), 0);
  const std::vector<int> targets = {0, 5, 9, 10, 20};
  for (const auto target : targets) {
    auto target_iter = binary_search(x, target);
    if (target_iter == x.end()) {
      std::cout << target << " is not in the array" << std::endl;
    } else {
      std::cout << target << " is at index "
                << std::distance(x.cbegin(), target_iter) << std::endl;
    }
  }
  return 0;
}
