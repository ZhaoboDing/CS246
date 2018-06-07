#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

struct BigInteger {
  // Digits are listed in *reverse order*
  // So a BigInteger representing 123 have
  // {'3', '2', '1'} as the value of digits
  // Also, we are using char arrays to save space.
  char *digits;

  // As long as (size <= capacity) we are good
  int size;
  int capacity;

  // Constructors
  BigInteger(int value = 0);

  // Copy Constructor
  BigInteger(const BigInteger &in);

  // Copy Assignment Operator
  BigInteger &operator=(const BigInteger &in);

  // Destructor
  ~BigInteger();

  // Move Constructor
  BigInteger(BigInteger &&in);

  // Move Assignment Operator
  BigInteger &operator=(BigInteger &&in);

  // Addition
  // Note that lhs is implicitly *this.
  BigInteger operator+(const BigInteger &addent2) const;
};

// Print the BigInteger
std::ostream &operator<<(std::ostream &out, const BigInteger &in);

#endif
