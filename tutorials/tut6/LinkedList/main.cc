#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list0;

    cout << "Size of list: " << list0.size() << endl;
    cout << list0 << endl;

    // Adding elements
    list0.insertHead(5);
    list0.insertHead(10);
    list0.insertTail(15);

    cout << "Size of list: " << list0.size() << endl;
    cout << list0 << endl;

    // Removing an element
    list0.remove(1);

    cout << "Size of list: " << list0.size() << endl;
    cout << list0 << endl;

	const LinkedList list1(4,5); // linked list with four 5's
	cout << "Size of list: " << list1.size() << endl; // prints 4
	cout << list1 << endl;

	LinkedList list2;
	LinkedList list3;
	LinkedList list4;

	cout << LinkedList::getCount() << endl; // prints 5
}
