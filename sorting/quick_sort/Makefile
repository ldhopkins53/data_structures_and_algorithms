all:
	clang-format -i *.cpp
	g++ -g -F DWARF -std=c++17 quick_sort.cpp -o quick_sort.bin
	./quick_sort.bin
clean:
	rm -vf *.bin
