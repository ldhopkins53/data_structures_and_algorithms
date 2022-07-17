#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <random>

template <typename T, std::size_t U>
void display_array(const std::array<T, U> &input_arr) {
  for (const T &i : input_arr) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

template <typename T, std::size_t U>
void merge(std::array<T, U> &input_arr, std::size_t left, std::size_t mid,
           std::size_t right) {
  auto len_1 = mid - left + 1;
  auto len_2 = right - mid;

  T left_array[len_1], right_array[len_2];

  for (auto i = 0; i < len_1; ++i) {
    left_array[i] = input_arr.at(left + i);
  }
  for (auto i = 0; i < len_2; ++i) {
    right_array[i] = input_arr.at(mid + i + 1);
  }

  std::size_t a = 0, b = 0, c = left;
  while (a < len_1 && b < len_2) {
    if (left_array[a] <= right_array[b])
      input_arr.at(c++) = left_array[a++];
    else
      input_arr.at(c++) = right_array[b++];
  }

  while (a < len_1) {
    input_arr.at(c++) = left_array[a++];
  }
  while (b < len_2) {
    input_arr.at(c++) = right_array[b++];
  }
}

template <typename T, std::size_t U>
void merge_sort(std::array<T, U> &input_arr, std::size_t left,
                std::size_t right) {
  if (left >= right)
    return;
  auto mid = left + ((right - left) / 2);
  merge_sort(input_arr, left, mid);
  merge_sort(input_arr, mid + 1, right);
  merge(input_arr, left, mid, right);
}

int main() {

  // populate vector
  std::array<int, 10> x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  display_array(x);

  // shuffle vector
  auto rng = std::default_random_engine{};
  std::shuffle(x.begin(), x.end(), rng);
  display_array(x);

  // sort vector
  merge_sort(x, 0, x.size() - 1);
  display_array(x);
  return 0;
}
