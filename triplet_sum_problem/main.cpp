#include <iostream>
#include <algorithm>
#include <array>

template <typename T>
void display_iterable(T begin, T end)
{
	while (begin != end)
	{
		std::cout << *begin << ' ';
		++begin;
	}
	std::cout << std::endl;
}

template <typename T, std::size_t U>
void solve(const std::array<T, U> &input_array)
{
	return;
}

template <typename T, typename U>
std::pair<T, T> find_tuple(T begin, T end, U target)
{
	while (begin != end)
	{
		auto cur = *begin + *end;
		if (cur < target) ++begin;
		else if (cur > target) --end;
		else return {begin, end};
	}
	return {end, end};
}

int main()
{
	std::array x{ 1, 4, 45, 6, 10, 8 }; 
	display_iterable(std::begin(x), std::end(x));
	std::sort(std::begin(x), std::end(x));
	display_iterable(std::begin(x), std::end(x));

	auto target_sum = 22;
	for (auto i = std::begin(x); i != std::end(x); ++i)
	{
		auto new_target = target_sum - *i;
		auto tuple = find_tuple(i+1, std::end(x), new_target);
		if (tuple.first == tuple.second) continue;
		std::cout << *i << ' ' << *tuple.first << ' ' << *tuple.second << std::endl;
		break;
	}
	return 0;
}
