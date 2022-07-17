#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

template <typename T> void display_vector(const std::vector<T> &input_vec) {
  for (const T &i : input_vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T> void insertion_sort(std::vector<T> &input_vec) {
  auto i = 1;
  while (i < input_vec.size()) {
    auto j = i;
    while (j > 0 && input_vec[j] < input_vec[j - 1]) {
      std::swap(input_vec[j - 1], input_vec[j]);
      --j;
    }
    ++i;
  }
}

int main() {

  // populate vector
  std::vector<int> x(10);
  std::iota(x.begin(), x.end(), 0);
  display_vector(x);

  // shuffle vector
  auto rng = std::default_random_engine{};
  std::shuffle(x.begin(), x.end(), rng);
  display_vector(x);

  // sort vector
  insertion_sort(x);
  display_vector(x);
  return 0;
}
