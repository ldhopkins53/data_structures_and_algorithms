#include <array>
#include <iostream>

template <typename T, std::size_t U>
T find_max_difference(const std::array<T, U> &arr) {
  auto current_min = arr[0];
  auto max_diff = arr[1] - arr[0];
  for (auto i = 1; i < arr.size(); ++i) {
    max_diff = std::max(max_diff, arr[i] - current_min);
    if (arr[i] < current_min)
      current_min = arr[i];
  }
  return max_diff;
}

int main() {
  const std::array x{1, 2, 90, 10, 110};
  std::cout << find_max_difference(x) << std::endl;
  return 0;
}
