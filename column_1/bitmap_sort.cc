#include <cmath>
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

/*
void sort_and_write(int max, std::ifstream in, std::ofstream out) {
  std::vector<int> ints;

  int e;
  while (in >> e) {
    ints.push_back(e);
  }

  std::sort(ints.begin(), ints.end());
  out << ints[0] << std::endl;
}*/

// `max` is an open bound
/*
void sort_and_write(int max, std::ifstream in, std::ofstream out) {
  bool* seen = new bool[max - 1];
  while (!in.eof()) {
    int e;
    in >> e;
    *(seen + e) = true;
  }

  for (int i = 0; i < max; i++) {
    if (seen[i]) {
      out << i << std::endl;
    }
  }
}*/

void sort_and_write(int max, std::ifstream in, std::ofstream out) {
  int bits_per_entry = sizeof(int) * 8;
  int num_entries = ceil(max * 1.0 / bits_per_entry);
  int* entries = new int[num_entries];

  while (!in.eof()) {
    int e;
    in >> e;
    int entry_index = floor(e * 1.0 / bits_per_entry);
    int offset = e % bits_per_entry;
    entries[entry_index] |= 1 << offset;
  }

  out << entries[0] << std::endl;
}

/*
void sort_and_write(int max, std::ifstream in, std::ofstream out) {
  std::bitset<10000000> mask;

  int e;
  while (in >> e) {
    mask.set(e);
  }

  out << mask.test(0) << std::endl;
}*/

/*
void sort_and_write(int max, std::ifstream in, std::ofstream out) {
  std::vector<bool> mask;

  for (int i = 0; i < max; i++) {
    mask.push_back(false);
  }

  while (!in.eof()) {
    int e;
    in >> e;
    mask[e] = true;
  }

  for (int i = 0; i < max; i++) {
    bool is_present = mask[i];
    if (is_present) {
      out << i << std::endl;
    }
  }
}*/

int main(int argc, char** argv) {
  int max = std::stoi(argv[1]);
  sort_and_write(max, std::ifstream(argv[2]),
    std::ofstream(argv[3]));
}