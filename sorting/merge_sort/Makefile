all:
	clang-format -i *.cpp
	g++ -g -F DWARF -std=c++17 merge_sort.cpp -o merge_sort.bin
	./merge_sort.bin
clean:
	rm -vf *.bin
