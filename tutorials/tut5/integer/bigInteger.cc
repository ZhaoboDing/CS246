#include "bigInteger.h"
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::swap;
using std::to_string;

// Refer to biginteger.h for data definition

// Output operator
ostream &operator<<(ostream &out, const BigInteger &in) {
  for (int i = in.size - 1; i >= 0; --i) {
    out << in.digits[i];
  }
  return out;
}

BigInteger::BigInteger(int value) {
  string val = to_string(value);
  int len = val.length();
  size = len;
  capacity = len;
  digits = new char[capacity];
  for (int i = 0; i < size; ++i) {
    digits[(size - 1) - i] = val[i];
  }
}

// Copy Constructor
BigInteger::BigInteger(const BigInteger &in)
    :digits{new char[in.capacity]}, size{in.size}, capacity{in.capacity}{
  for (int i = 0; i < size; ++i) {
    digits[i] = in.digits[i];
  }
  cout << "Copy constructor" << endl;
}

// Copy Assignment Operator
BigInteger &BigInteger::operator=(const BigInteger &in) {
  if (this != &in) {
    BigInteger copy = in;

    swap(digits, copy.digits);
    size = copy.size;
    capacity = copy.capacity;
  }

  cout << "Copy assignment operator" << endl;
  return *this;
}

// Destructor
BigInteger::~BigInteger() { delete[] digits; }

// Move Constructor
BigInteger::BigInteger(BigInteger &&in)
    : digits{in.digits}, size{in.size}, capacity{in.capacity}{
  in.digits = nullptr;
  cout << "Move ctor for BigInteger = " << *this << endl;
}

// Move Assignment Operator
BigInteger &BigInteger::operator=(BigInteger &&in) {
  // Typically, the self assignment check is not required.
  // but added here to prevent someone actually performs
  // a self-assignment
  if (this != &in) {
    size = in.size;
    capacity = in.capacity;
    delete[] digits;
    digits = in.digits;
    in.digits = nullptr;
  }
  cout << "Move assignment operator" << endl;
  return *this;
}

// Add function
BigInteger BigInteger::operator+(const BigInteger &rhs) const {
  // left hand side is impilitly *this.
  // I'm making this definition to make it explicit
  // Usually you don't have to do this.
  const BigInteger &lhs = *this;

  BigInteger retVal;
  retVal.size = (lhs.size > rhs.size) ? lhs.size : rhs.size;
  retVal.capacity = (lhs.capacity > rhs.capacity) ? lhs.capacity : rhs.capacity;
  // add one to the capacity to prevent overflow in case of carrying
  retVal.capacity++;
  delete [] retVal.digits;
  retVal.digits = new char[retVal.capacity];
  char carry = 0;
  for (int i = 0; i < retVal.size; i++) {
    char lhs_digit = ((i < lhs.size) ? lhs.digits[i] : '0') - '0';
    char rhs_digit = ((i < rhs.size) ? rhs.digits[i] : '0') - '0';
    char sum = lhs_digit + rhs_digit + carry;
    char nextCarry = 0;
    if (sum > 9) {
      sum -= 10;
      nextCarry = 1;
    }
    retVal.digits[i] = sum + '0';
    carry = nextCarry;
  }
  // Take care of last carrying
  // e.g. 11 + 89 = 100
  if (carry == 1) {
    retVal.digits[retVal.size] = '1';
    retVal.size++;
  }
  return retVal;
}
