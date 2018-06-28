#include <iostream>

class BST {
	struct Node;
	friend std::ostream& operator<<(std::ostream& out, const Node& rhs);

	size_t size;
	Node* root;

public:
	// inserts and element if it does not 
	// exist in the tree returns true if 
	// the insertion was successful
	bool insert(int e);

	// ctor
	BST();
	
	friend std::ostream& operator<<(std::ostream& out, const BST& rhs);
};

std::ostream& operator<<(std::ostream& out, const BST& rhs);
std::istream& operator>>(std::istream& in, BST& rhs);
