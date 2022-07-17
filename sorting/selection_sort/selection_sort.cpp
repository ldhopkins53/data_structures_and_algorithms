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

template <typename T> void selection_sort(std::vector<T> &input_vec) {
  for (auto i = 0; i < input_vec.size(); ++i) {
    auto min_place = i;
    for (auto j = i + 1; j < input_vec.size(); ++j) {
      if (input_vec[min_place] > input_vec[j])
        min_place = j;
    }
    std::swap(input_vec[i], input_vec[min_place]);
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
  selection_sort(x);
  display_vector(x);
  return 0;
}
