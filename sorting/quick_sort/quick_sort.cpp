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

template <typename T>
std::size_t partition(std::vector<T> &input_vec, std::size_t low,
                      std::size_t high) {
  auto pivot_value = input_vec[(low + high) / 2];
  auto left = low - 1;
  auto right = high + 1;
  while (true) {
    do {
      ++left;
    } while (input_vec[left] < pivot_value);
    do {
      --right;
    } while (input_vec[right] > pivot_value);
    if (left >= right)
      return right;
    std::swap(input_vec[left], input_vec[right]);
  }
}

template <typename T>
void quick_sort(std::vector<T> &input_vec, std::size_t low, std::size_t high) {
  if (low < 0 || high < 0 || low >= high) {
    return;
  }
  auto p = partition(input_vec, low, high);
  quick_sort(input_vec, low, p);
  quick_sort(input_vec, p + 1, high);
}

int main() {

  // populate vector
  std::vector<int> x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  display_vector(x);

  // shuffle vector
  auto rng = std::default_random_engine{};
  std::shuffle(x.begin(), x.end(), rng);
  display_vector(x);

  // sort vector
  quick_sort(x, 0, x.size() - 1);
  display_vector(x);
  return 0;
}
