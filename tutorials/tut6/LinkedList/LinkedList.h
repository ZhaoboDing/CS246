#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

class LinkedList {
	static int count;
	
	struct Node{
		int value;
		Node *next;

		// Constructors
		Node(int value, Node *next = nullptr);
	    Node(int begin, int end);

		// THE BIG 5: Which is which?
	    Node(const Node &n);
	    Node(Node &&n);
	    Node &operator=(const Node &n);
	    Node &operator=(Node &&n);
	    ~Node();

	    // Gets the last Node
	    Node *last();
	};

	int numNodes;
	Node *head;
	Node *tail;

public:
    // Constructors
    LinkedList();
	LinkedList(int amount, int what); // fill constructor

    // Copy ctor
    LinkedList(const LinkedList &list);
    // Move ctor
    LinkedList(LinkedList &&list);
    // Copy operator=
    LinkedList &operator=(const LinkedList &list);
    // Move operator=
    LinkedList &operator=(LinkedList &&list);
    // Destructor
    ~LinkedList();

    void insertHead(int value); // insert Node at front
    void insertTail(int value); // insert Node at back

    // Remove the Node at index
    void remove(int index);

    // Returns the size of the LL
    int size() const;

	static int getCount();

	// appends the linked list on the rhs to the end of the lhs
	LinkedList &operator+=(const LinkedList &rhs);

	// creates a new linked list that is the result of appending
	// the rhs to the end of the lhs
	LinkedList operator+(const LinkedList &rhs) const;

    // Pretty prints the LL
	// the friend keyword allows access of LinkedList's private fields
    friend std::ostream &operator<<(std::ostream &out, const LinkedList &rhs);

};


#endif
