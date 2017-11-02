// CS 130A PA1, Suffix Trie
// Iris Xu  9893025

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

class Node {
	public:
		map<string, Node*> children; //contains each child word and pointer to it
		int numchild; // number of children
		string currword; // word stored in node
		int weight; // only matters for leaf node
};

class suffixTrie {
	public:
		void add(vector<string> str, int wt); // adds new phrase with vector of words, puts weight at the leaf, OW nodes have weight = -1
		Node* go_to(vector<string> str); // returns pointer to node at the end of phrase, NULL if phrase dne in trie
		map<int, string> readfrom(Node* n); //feed in start node to read sentences from (complete the phrase from that node)
		void printmax();
        void printChildren(vector<string> str);

	private:
		Node root;
		string maxword;
		int maxchild = 0;
};

void printmapR(map<int, string> mymap);
