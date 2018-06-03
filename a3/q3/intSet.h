#ifndef _INTSET_H_
#define _INTSET_H_
#include <iostream>
struct intSet {
    // You may add fields and methods as you see fit
    // Do *not* change the provided methods.
  
  
  intSet(); // constructor
  intSet(const intSet& is); // copy constructor
  ~intSet();  // destructor
  intSet(intSet &&is); // move constructor
  intSet &operator=(const intSet& is); // copy assignment operator
  intSet &operator=(intSet &&is); // move assignment operator
  void swap(intSet &is); // method to swap is fields with this object
  intSet operator|(const intSet &other); // Set union
  intSet operator&(const intSet &other); // Set intersection.
  bool operator==(const intSet &other);  // Set equality.
  bool isSubset(const intSet &s);  // True if s is a subset of *this
  bool contains(int e);     // True if *this contains e
  void add(int e);          // Add e to this set.
  void remove(int e);       // Remove e from this set.
};

//output operator for intSet
std::ostream& operator<<(std::ostream& out, const intSet& is);
#endif
