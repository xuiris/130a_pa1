#include "trie.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

    // Initialize trie up here
	suffixTrie trie;

    // parse input lines until I find newline
	for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
		std::stringstream ss(line);
		std::string string_weight;
		ss >> string_weight;
		int weight = std::stoi(string_weight);
	    // I am just going to put these words into a vector
		std::vector<std::string> words = {};
		for(std::string word; ss >> word;) {
			words.push_back(word);
		}
	    trie.add(words, weight);
	}


	 // parse query line
	std::string query;
	std::getline(std::cin, query);
	std::stringstream sss(query);
	std::vector<std::string> qwords = {};
	for(std::string word; sss >> word;) {
		qwords.push_back(word);
	}
    
    trie.printChildren(qwords);
    trie.printmax();
	return 0;
}
