#include <iostream>
#include <string>
#include "makefile.h"
using namespace std;

int main() {
  string s, t;
  Makefile m;
  while (cin >> s) {
    if (s[s.length() - 1] ==  ':') {  // Indicate dependency
      cin >> t;
      m.addDepend(s.substr(0, s.length() - 1), t);
    }
    else if (s == "touch") { // Update leaf file
      cin >> t;
      m.changeTarget(t);
    }
    else if (s == "make") { // Build target
      cin >> t;
      m.rebuild(t);
    }
    else if (s == "q") { // Quit
      break;
    }
  }
}
