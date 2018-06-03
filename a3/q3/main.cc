#include "intSet.h"
#include <iostream>
#include <sstream>
using namespace std;

struct symbolTable {
  int size;
  int capacity;    
  intSet **table;
  
  symbolTable() : size{0}, capacity{0}, table{nullptr} {}
  ~symbolTable() {
    if (size) {
      for (int i=0; i<size; ++i) delete table[i];
      delete[] table;    
    }
  }
  void add() {
    if (size==capacity) realloc();
    table[size] = new intSet;
    ++size;
  }
  void add(int x) {
    if (size==capacity) realloc();
    table[size] = new intSet {*table[x]};
    ++size;
  }
  void copy(int i, int j) {
    *table[i] = *table[j];
  }
  void realloc() {
    if (capacity==0) {
      table = new intSet*[5];
      capacity = 5;
		return;
    }
    intSet** temp = new intSet*[capacity*2];
    capacity *= 2;
	 for (int i=0; i<size; ++i) temp[i]=table[i];
    delete[] table;
    table=temp;
  }  
};

void readIn(intSet* is) {
  int x;  
  while(true) {
    if (!(cin>>x)) {
      cin.clear();
      cin.ignore();
      return;
    } else {
      is->add(x);
    }
  }
}

intSet move() {
  intSet temp;
  readIn(&temp);
  return temp;
}

int main() { // Test harness for intSet functions.
  bool done = false;
  symbolTable t;
  while (!done) {
    char c;
    int lhs, rhs;
    // Valid commands: n,  p <ind>, & <ind1> <ind2>,
    //                 | <ind1> <ind2>, = <ind1> <ind2>,
    //                 s <ind1> <ind2>, c <ind1> <elem>,
    //                 a <ind1> <elem>, r <ind1> <elem>,
    //                 d <ind1>, < <ind> <ind>, m <ind>, q

    cin >> c; // Reads n, r, p, &, |, =, s, c, a, r, d, <, m, or q 
    if (cin.eof()) break;
    switch(c) {
      case 'n':
        // Create new intSet with next index
        // read in integers to add to it until hitting non int.
        t.add();
        readIn(t.table[t.size-1]);
        break;
      case 'p':
        // Print intSet at lhs.
        cin >> lhs;
        cout << *t.table[lhs] << endl;
        break;
      case '&':
        // Print intersection of lhs and rhs.
        cin >> lhs >> rhs; // reads in two indices
        cout << (*t.table[lhs] & *t.table[rhs]) << endl;
        break;
      case '|':
        // Print union of lhs and rhs.
        cin >> lhs >> rhs;
        cout << (*t.table[lhs] | *t.table[rhs]) <<endl;
        break;
      case '=':
        // Print 1 if lhs == rhs, 2 otherwise.
        cin >> lhs >> rhs;
        cout << (*t.table[lhs] == *t.table[rhs]) << endl;
        break;
      case 's':
        // Print 1 if rhs is subset of lhs, 0 otherwise.
        cin >> lhs >> rhs;
        cout << t.table[lhs]->isSubset(*t.table[rhs]) << endl;
        break;
      case 'c':
        // Print 1 if lhs contains element rhs, 0 otherwise.
        cin >> lhs >> rhs;
        cout << t.table[lhs]->contains(rhs) << endl;
        break;
      case 'a':
        // Add elem rhs to set lhs
        cin >> lhs >> rhs;
        t.table[lhs]->add(rhs);
        break;
      case 'r':
        // Remove elem rhs from set lhs
        cin >> lhs >> rhs;
        t.table[lhs]->remove(rhs);
        break;
      case 'q':
        // Quit
        done = true;
        break;
      case 'd':
        // Create a new intSet at next index copying 
        // intSet at index lhs.
        cin >> lhs;
        t.add(lhs);
        break;
      case '<':
        // Assign intSet at lhs to intSet at rhs.
        cin >> lhs >> rhs;
        t.copy(lhs,rhs);
        break;
      case 'm':
        // Read in integers until hitting non int and
        // create a new rvalue set from that, assigning 
        // rhs to that rvalue set.
        cin >> lhs;
        *t.table[lhs] = move();
        break;
    }
  }
}
