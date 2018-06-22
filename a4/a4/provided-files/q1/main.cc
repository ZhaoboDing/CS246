#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// You will need to make changes to this file

// Read and construct expression object.  Returns a pointer to a heap-allocated
// object (caller must delete it).
istream &operator>>(istream &in, Expr *&e) {
  while (cin >> s) {
    istringstream ss(s);
    int n;
    if (ss >> n) {
    }
    else if (s == "NEG" || s == "ABS") {
    }
    else if (s == "+" || s == "-" || s == "*" || s == "/") {
    }
    else if (s == "done") {
    }
    else {
    }
  }
  return in;
}

int main () {
  string s;

  Expr *e;
  cin >> e;

  // Command interpreter
  while (cin >> s) {
    if (s == "eval") {
    }
    else if (s == "set") {
    }
    else if (s == "unset") {
    }
    else if (s == "print") {
    }
  }
}
