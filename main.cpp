#include "trie.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  // Initialize trie up here

  // parse input lines until I find newline
  for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
    std::stringstream ss(line);
    std::string string_weight;
    ss >> string_weight;
    int weight = std::stoi(string_weight);
    // I am just going to put these words into a vector
    // you probably want to put them in your trie
    std::vector<std::string> words = {};
    for(std::string word; ss >> word;) {
      words.push_back(word);
    }
    // don't forget to do something with the weight
  }
  // parse query line
  std::string query;
  std::getline(std::cin, query);

  // Now we output some stuff... probably not this
  std::cout << "Query: " << query << std::endl;

  return 0;
}
