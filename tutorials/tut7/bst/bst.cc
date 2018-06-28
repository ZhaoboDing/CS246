#include<iostream>
#include<utility>
#include "bst.h"
using namespace std;

struct BST::Node {
	int val;
	Node* left;
	Node* right;

	bool insert(const int e);

	// ctor
	Node(int e);

	// big 5
	// dtor
	~Node();
	// copy ctor
	Node(const Node& other);
	// move ctor
	Node(Node&& other);
	// copy assignment
	Node& operator=(const Node& rhs);
	// move assignment
	Node& operator=(Node&& rhs);

	friend ostream& operator<<(ostream& out, const Node& rhs);
};


bool BST::Node::insert(const int e) {
	if (e < val) {
		if (left) {
			return left->insert(e);
		}

		left = new Node{e};
		return true;
	}

	else if (val < e) {
		if (right) {
			return right->insert(e);
		}

		right = new Node{e};
		return true;
	}

	else { // ==
		return false;
	}
	
}


// ctor
BST::Node::Node(const int e): val{e}, left{nullptr}, right{nullptr};


// big 5
// dtor
BST::Node::~Node();


// copy ctor
BST::Node::Node(const BST::Node& other);


// move ctor
BST::Node::Node(BST::Node&& other);


// copy assignment
BST::Node& BST::Node::operator=(const BST::Node& rhs);


// move assignment
BST::Node& BST::Node::operator=(BST::Node&& rhs);


ostream& operator<<(ostream& out, const BST::Node& rhs) {
	// recursively invoke operator<< on left and right children
	out << *(rhs.left) << ' ' << rhs.val << ' ' << *(rhs.right);
	return out;
}


// inserts and element if it does not 
// exist in the tree returns true if 
// the insertion was successful
bool BST::insert(const int e) {
	if (root) {
		return (root->insert(e) ? ++size : false);
	}

	root = new Node{e};
	return ++size;
}

// ctor
BST::BST(): size{0}, root{nullptr};

	
// big 5
// dtor
BST::~BST();


// copy ctor
BST::BST(const BST& other);


// move ctor
BST::BST(BST&& other);


// copy assignment
BST& BST::operator=(const BST& rhs);


// move assignment
BST& BST::operator=(BST&& rhs);


ostream& operator<<(ostream& out, const BST& rhs) {
	// callls operator<< for BST::Node
	out << "BST (size " << rhs.size << "):" << *(rhs.root);
	return out;
}


istream& operator>>(istream& in, BST& rhs) {
	int n;
	while(in >> n) {
		rhs.insert(n);
	}

	return in;
}
