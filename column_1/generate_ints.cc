#include <cstdlib>
#include <set>
#include <random>
#include <fstream>

// `max` is an open boundary
void generate_unique_ints(int max, int size, std::ofstream out) {
  std::set<int> set;
  for (int i = 0; i < size; i++) {
    int e = rand() % max;
    while (set.count(e) > 0) {
      e = rand() % max;
    }
    set.insert(e);
    out << e << std::endl;
  }
}

void generate_unique_ints_memoized(int max, int size, std::ofstream out) {
  int* values = new int[max];
  for (int i = 0; i < max; i++) {
    values[i] = 0;
  }

  std::set<int> set;
  for (int i = 0; i < size; i++) {
    int e = rand() % max;
    while (values[e] != 0) {
      e = (e + values[e]) % max;
    }
    int next_index = (e + 1) % max;
    values[e] = 1 + values[next_index];
    if (set.count(e) > 0) {
      throw std::runtime_error("Got a duplicate value!");
    }
    out << e << std::endl;
  }
}

int main(int argc, char** argv) {
  int max = std::stoi(argv[1]),
    size = std::stoi(argv[2]);
  generate_unique_ints_memoized(max, size, std::ofstream(argv[3]));
  //generate_unique_ints(max, size, std::ofstream(argv[3]));
}