#include "trie.hpp"

void suffixTrie::add(vector<string> str, int wt) {
	Node * currnode = &root;
	std::map<string, Node*>::iterator it;
	std::vector<string>::iterator word;
	for (word = str.begin() ; word != str.end(); ++word) // loop through words in the vector
		it = currnode->children.find(*word);
		if (it != currnode->children.end()) { // word exists in its children (map)
			currnode = it->second; // go to it
		}
		else { // word is not a child of current node, create new one and place in children (map)
			Node * child = new Node;
			child->numchild = 0;
			child->currword = *word;
			child->weight = -1;
			currnode->children[*word] = child;
			currnode->numchild++;
			currnode = child; // go to new child
		}
		currnode->weight = wt;
}

Node* suffixTrie::go_to(vector<string> str) {
	Node * currnode = &root;
	std::map<string, Node*>::iterator it;
	std::vector<string>::iterator word;
	for (word = str.begin() ; word != str.end(); ++word) // loop through words in the vector
		it = currnode->children.find(*word);
		if (it != currnode->children.end()) { // word exists in its children (map)
			currnode = it->second; // go to the child
		}
		else { // word is not a child of current node
			return NULL;
		}
		return currnode;

}

map<int, string> suffixTrie::readfrom(Node* n) {
	map<int, string> sentence, subsentence;
	std::map<string, Node*>::iterator it;
	std::map<int, string>::iterator subit;
	// Base case (1): leaf node with weight
	if (n->numchild == 0) {
		sentence[n->weight] = (n->currword);
		return sentence;
	}

	// Case 2: non-leaf node (has children)
	else{
		for (it = n->children.begin(); it != n->children.end(); ++it) {
			subsentence = readfrom(it->second);
			subit = subsentence.begin();
			sentence[subit->first] = (n->currword + " " + subit->second);
		}
		if (n->weight >= 0) { // for non-leaf with weight
			sentence[n->weight] = n->currword;
		}
		return sentence;
	}

	return sentence;
}

