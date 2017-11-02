#include "trie.hpp"

void printmapR(map<int, string> mymap) {
	map<int, string>::reverse_iterator rit;
	for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit) {
		cout << rit->second << endl;
	}
}

void suffixTrie::add(vector<string> str, int wt) {
	Node * currnode = &root;
	std::map<string, Node*>::iterator it;
	std::vector<string>::iterator word;
	for (word = str.begin() ; word != str.end(); ++word) {// loop through words in the vector
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
			if (currnode->numchild > maxchild && currnode != &root) {
				maxchild = currnode->numchild;
				maxword = currnode->currword;
			}
			currnode = child; // go to new child
		}
	}
	currnode->weight = wt;
}

Node* suffixTrie::go_to(vector<string> str) {
	Node * currnode = &root;
	std::map<string, Node*>::iterator it;
	std::vector<string>::iterator word;
	for (word = str.begin() ; word != str.end(); ++word) {// loop through words in the vector
		it = currnode->children.find(*word);
		if (it != currnode->children.end()) { // word exists in its children (map)
			currnode = it->second; // go to the child
		}
		else { // word is not a child of current node
			return NULL;
		}
    }
	return currnode;

}

map<int, string> suffixTrie::readfrom(Node* n) {
    map<int, string> sentence, subsentence;
	std::map<string, Node*>::iterator it;
	std::map<int, string>::iterator subit;
	// Base case (1): n is leaf node with weight
	if (n->numchild == 0 &&  n->weight > 0) {
		sentence[n->weight] = n->currword;
		return sentence; // return the word + weight in map
	}

	// Case 2: n is non-leaf node (has children)
	else{
		for (it = n->children.begin(); it != n->children.end(); ++it) { // for each child
			subsentence = readfrom(it->second); // recurse, read (sub)sentences starting from child, put in map
			for (subit = subsentence.begin(); subit != subsentence.end(); ++subit) { // for each string in subsentence
				sentence[subit->first] = (n->currword + " " + subit->second); // concatenate words, keep leaf weight and add to map
                }
        }

		if (n->weight >= 0) { // n is non non-leaf WITH weight
			sentence[n->weight] = n->currword; // treat like leaf node, add the word+weight to map
		}
		return sentence;
	}

	return sentence;
}

void suffixTrie::printChildren(vector<string> str) {
	Node * n = go_to(str);
    if (n == NULL) {
        cout << "No valid completion" << endl;
        return;
    }
	std::map<string, Node*>::iterator it;
	std::map<int, string>::iterator subit;
	map<int, string> sentences, allsentences; // allsentences will hold all sentences from all children
	for (it = n->children.begin(); it != n->children.end(); ++it) { // from each child
		sentences = readfrom(it->second); // read sentences
		for (subit = sentences.begin(); subit != sentences.end(); ++subit) { // then add to allsentences
			allsentences[subit->first] = (subit->second);
		}
	}
	printmapR(allsentences);

}

void suffixTrie::printmax() {
	cout << maxword << " " << maxchild << endl;
	return;
}

