CXX=clang++
CXX_FLAGS=-O3 -std=c++14 -Wfatal-errors

MAX_VALUE = 50000000
SIZE = 5000000
IN_FILE = ints.out
OUT_FILE = sorted_ints.out

bitmap_sort: bitmap_sort.cc
	mkdir -p bin
	$(CXX) $(CXX_FLAGS) -o bin/bitmap_sort bitmap_sort.cc
	/usr/bin/time --verbose bin/bitmap_sort $(MAX_VALUE) $(IN_FILE) $(OUT_FILE)

generate_ints: generate_ints.cc
	mkdir -p bin
	$(CXX) $(CXX_FLAGS) -o bin/generate_ints generate_ints.cc
	/usr/bin/time --verbose bin/generate_ints $(MAX_VALUE) $(SIZE) $(IN_FILE)