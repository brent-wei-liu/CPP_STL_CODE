all : unordered_map unordered_set make_heap vector
vector : vector.cc
	g++ -o $@  vector.cc
unordered_map : unordered_map.cc
	g++ -o $@  unordered_map.cc
unordered_set : unordered_set.cc
	g++ -o $@  unordered_set.cc
make_heap: make_heap.cpp
	g++ -Wno-write-strings -ggdb -o $@ make_heap.cpp
clean:
	rm -rf unordered_map unordered_set make_heap vector
