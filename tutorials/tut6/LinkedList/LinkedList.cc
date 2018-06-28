#include <iostream>
#include <utility>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::ostream;

// must be given value from outside of the class,
// typicalling in the implementation file
int LinkedList::count = 0; // before any ctors are called

// 1. LinkedList Methods

// Default Constructor
LinkedList::LinkedList()
		: numNodes{0}, head{nullptr}, tail{nullptr} {

	++LinkedList::count;
}

// Fill Constructor
LinkedList::LinkedList(int amount, int what) {
	Node *n = new Node {what};
	numNodes = 0;
	head = n;
	tail = n;

	for (int i = 1; i < amount; ++i) {
		insertTail(what);
	}

	++LinkedList::count;
}

// Copy Constructor 
LinkedList::LinkedList(const LinkedList &list) : numNodes(list.numNodes) {
    if (list.head) {
        head = new Node{*list.head};
        tail = head->last();
    }
}

// Move Constructor
LinkedList::LinkedList(LinkedList &&list)
        : numNodes{list.numNodes}, head{list.head}, tail{list.tail} {
    list.head = nullptr;
    list.tail = nullptr;
}

// Copy Assignment Operator
LinkedList &LinkedList::operator=(const LinkedList &list) {
    LinkedList copy = list;

    using std::swap;

    swap(head, copy.head);
    swap(tail, copy.tail);
    swap(numNodes, copy.numNodes);

    return *this;
}


// Move Assignment Operator
LinkedList &LinkedList::operator=(LinkedList &&list) {
    using std::swap;

    swap(head, list.head);
    swap(tail, list.tail);
    swap(numNodes, list.numNodes);

    return *this;
}

// Destructor
LinkedList::~LinkedList() { delete head; }


// Adds a new node to the front of the LL.
void LinkedList::insertHead(int value) {
    head = new Node{value, head};
    if (!tail) {
        tail = head;
    }
    ++numNodes;
}

// Adds a new node to the end of the LL.
void LinkedList::insertTail(int value) {
    Node *temp = new Node{value};

    // if tail exists, make temp the new tail
    if (tail) {
        tail->next = temp;
        tail = temp;
    }
    else {
        // otherwise, temp is the only node and should be the head and the tail
        head = tail = temp;
    }
    ++numNodes;
}

// Remove the index'th element.
void LinkedList::remove(int index) {
    if (index < numNodes) {
        Node *temp = head;
        if (index == 0) { // First element
            head = head->next;
            temp->next = nullptr;
        }
        else { // Not first element
            int count = 0;
            while (count + 1 < index) { // Getting to the index'th element
                temp = temp->next;
                ++count;
            }

            // Removing the element from the LL.
            Node *cur = temp;
            temp = temp->next;
            cur->next = temp->next;
            temp->next = nullptr;
        }

        // This actually deletes the element.
        delete temp;
        --numNodes;
    }
}

// Returns the size of the LL.
int LinkedList::size() const { return numNodes; }

// Return the number of linked lists created
int LinkedList::getCount() {
	return count;
}

// Appends the linked list on th erhs to the end of the lhs
LinkedList &LinkedList::operator+=(const LinkedList &rhs) {
	LinkedList copy = rhs;

	if (!head) { // if the linked list is empty
		head = copy.head;
		tail = copy.tail;
	} else if (copy.head) { // if both the linked listand rhs
							// are not empty
		tail->next = copy.head;
		tail = copy.tail;
	}

	numNodes += copy.numNodes;
	copy.head = nullptr;
	copy.tail = nullptr;

	return *this;
}

// Creates a new linked list that is the result of appending
// the rhs to the end of the lhs
LinkedList LinkedList::operator+(const LinkedList &rhs) const {
	LinkedList first = *this;
	LinkedList last = rhs;

	first += last;
	return first;
}

// 2. LinkedList::Node methods

// Constructor
LinkedList::Node::Node(int value, LinkedList::Node *next)
        : value(value), next(next) {}

// Fill Construtor
LinkedList::Node::Node(int begin, int end) : value(begin) {
    // set dir to so that adding it to begin will result in
    //   eventually reaching end
    int dir = 1;
    if (begin < end) {
        dir = -1;
    }

    while (begin != end) {
        next = new Node{end, next};
        end += dir;
    }
}

// The Big Five
LinkedList::Node::Node(const LinkedList::Node &other) : value{other.value} {
    cout << "copying value of " << value << endl;
    if (other.next != nullptr) {
        next = new Node{*(other.next)}; // copy constructor
    }
}

LinkedList::Node &LinkedList::Node::operator=(const LinkedList::Node &other) {
    Node copy = other;

    Node *temp = next;
    next = copy.next;
    copy.next = temp;

    value = copy.value;

    return *this;
}

LinkedList::Node::~Node() { delete next; }

LinkedList::Node *LinkedList::Node::last() {
    if (next)
        return next->last();
    return this;
}


// 3. Other functions

// Prettyprints the LinkedList.
ostream &operator<<(ostream &out, const LinkedList &rhs) {
    LinkedList::Node *curr = rhs.head;
    if (curr) {
        out << curr->value;
        curr = curr->next;
    }
    while (curr) {
        out << " -> " << curr->value;
        curr = curr->next;
    }
    return out;
}
