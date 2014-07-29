all : unordered_map unordered_set make_heap make_heap_pointor vector sort
vector : vector.cc
	g++ -o $@  vector.cc
unordered_map : unordered_map.cc
	g++ -o $@  unordered_map.cc
unordered_set : unordered_set.cc
	g++ -o $@  unordered_set.cc
make_heap: make_heap.cpp
	g++ -Wno-write-strings -ggdb -o $@ make_heap.cpp
make_heap_pointor : make_heap_pointor.cpp
	g++ -Wno-write-strings -ggdb -o $@ make_heap_pointor.cpp

sort: sort.cpp
	g++ -Wno-write-strings -ggdb -o $@ sort.cpp

clean:
	rm -rf unordered_map unordered_set make_heap make_heap_pointor vector sort
