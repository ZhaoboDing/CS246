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

		return (left = new Node{e});
	}

	else if (val < e) {
		if (right) {
			return right->insert(e);
		}

		return (right = new Node{e});
	}

	else { // ==
		return false;
	}
	
}


// ctor
BST::Node::Node(const int e): val{e}, left{nullptr}, right{nullptr} {}


// big 5
// dtor
BST::Node::~Node() {
	// recursively call dtor on children
	delete left;
	delete right;
}


// copy ctor
BST::Node::Node(const BST::Node& other): 
	val{other.val}, 
	// recursively call copy ctor on children
	left{other.left ? new Node{*(other.left)} : nullptr},
	right{other.right ? new Node{*(other.right)} : nullptr} {}


// move ctor
BST::Node::Node(BST::Node&& other): 
	val{other.val},
	left{other.left},
	right{other.right} {
	other.left = nullptr;
	other.right = nullptr;	
}


// copy assignment
BST::Node& BST::Node::operator=(const BST::Node& rhs) {
	// copy and swap idiom
	// calls copy ctor
	Node n = rhs;

	// swap fields
	swap(val, n.val);
	swap(left, n.left);
	swap(right, n.right);

	return *this;
	// when function ends
	// dtor is called on n
}


// move assignment
BST::Node& BST::Node::operator=(BST::Node&& rhs) {
	swap(val, rhs.val);
    swap(left, rhs.left);
    swap(right, rhs.right);

	return *this;
}


ostream& operator<<(ostream& out, const BST::Node& rhs) {
	// recursively invoke operator<< on left and right children
	if (rhs.left) {
		out << *(rhs.left) << ' ';
	}

	out << rhs.val;

	if (rhs.right) {
		out << ' ' << *(rhs.right);
	}

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
BST::BST(): size{0}, root{nullptr} {}

	
// big 5
// dtor
BST::~BST() {
	// calls the dtor for Node
	delete root;
}


// copy ctor
BST::BST(const BST& other):
	size{other.size},
	root{new Node{*(other.root)}} {}


// move ctor
BST::BST(BST&& other):
	size{other.size},
	root{other.root} {
	other.root = nullptr;
}


// copy assignment
BST& BST::operator=(const BST& rhs) {
	// copy and swap idiom
	// copys copy ctor
	BST b = rhs;

	// swap fields
	swap(size, b.size);
	swap(root, b.root);

	return *this;
	// when function ends
	// dtor is called on b
}


// move assignment
BST& BST::operator=(BST&& rhs) {
	swap(size, rhs.size);
	swap(root, rhs.root);

	return *this;
}


ostream& operator<<(ostream& out, const BST& rhs) {
	// callls operator<< for BST::Node
	out << "BST (size " << rhs.size << "):";
	if (rhs.root) {
		out << ' ' << *(rhs.root);
	}

	return out;
}


istream& operator>>(istream& in, BST& rhs) {
	int n;
	while(in >> n) {
		rhs.insert(n);
	}

	return in;
}
