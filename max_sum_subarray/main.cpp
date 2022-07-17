#include <array>
#include <iostream>
#include <limits>

template <typename T, std::size_t U>
T find_max_subarray(const std::array<T, U> &arr) {
  auto local_max = 0;
  auto global_max = std::numeric_limits<int>::min();

  for (std::size_t i = 0; i < arr.size(); ++i) {
    local_max = std::max(arr[i], arr[i] + local_max);
    global_max = std::max(local_max, global_max);
  }
  return global_max;
}

int main() {
  const std::array x{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << find_max_subarray(x) << std::endl;
  return 0;
}
