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

template <typename T> void cocktail_shaker_sort(std::vector<T> &input_vec) {
  bool is_sorted = false;
  while (!is_sorted) {
    is_sorted = true;
    for (auto i = 0; i < input_vec.size(); ++i) {
      bool flipped = false;
      for (auto j = input_vec.begin(); j < input_vec.end() - i - 1; ++j) {
        if (*j > *(j + 1)) {
          std::iter_swap(j, j + 1);
          is_sorted = false;
        }
      }
      if (is_sorted)
        return;

      for (auto j = input_vec.rbegin(); j < input_vec.rend() - i - 1; ++j) {
        if (*j < *(j + 1)) {
          std::iter_swap(j, j + 1);
          is_sorted = false;
        }
      }
      if (is_sorted)
        return;
    }
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
  cocktail_shaker_sort(x);
  display_vector(x);
  return 0;
}
