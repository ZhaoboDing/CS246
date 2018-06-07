#include "bigInteger.h"
#include <iostream>

using std::cout;
using std::endl;

void dtor_test();
void copy_ctor_test();
void copy_assign_test();
void self_assign_test();
void move_ctor_test();
void move_assign_test();

int main() {
  dtor_test();        // Example: Destructor
  copy_ctor_test();   // Example: Copy ctor
  copy_assign_test(); // Example: Copy operator=
  self_assign_test(); // Example: Self-assignment
  move_ctor_test();   // Example: Move ctor
  move_assign_test(); // Example: Move operator=
}

void dtor_test() {
  BigInteger n1{23};
  BigInteger *pn2 = new BigInteger{21};
  cout << n1 << ' ' << *pn2 << endl;
  delete pn2;
}

void copy_ctor_test() {
  BigInteger *pn1 = new BigInteger{7};

  BigInteger n2{*pn1};

  delete pn1;
  cout << n2 << endl;
}

void copy_assign_test() {
  BigInteger *pn1 = new BigInteger{12};
  BigInteger n2;

  n2 = *pn1;

  delete pn1;
  cout << n2 << endl;
}

void self_assign_test() {
  BigInteger n1{42};

  // assign n1 to itself
  n1 = n1;

  cout << n1 << endl;
}

void move_ctor_test() {
  BigInteger n1{42};
  BigInteger n2{58};

  BigInteger n3(n1 + n2);

  cout << n3 << endl;
}

void move_assign_test() {
  BigInteger n1{42};
  BigInteger n2{58};

  BigInteger n3;

  n3 = n1 + n2;

  cout << n3 << endl;
}
