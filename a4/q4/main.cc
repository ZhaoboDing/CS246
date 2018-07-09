#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "state.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;
  int count = 0; // this will be used to determine the colour each turn

  try {
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      int count = 0;
      g.init(n);
      cout << g;
    }
    else if (cmd == "play") {
      int r = 0, c = 0;
      cin >> r >> c;
      if ((++count) & 1)
      // play black in odd turns and white in even turns
        g.setPiece(r, c, Colour::Black);
      else
        g.setPiece(r, c, Colour::White);
      cout << g;
      if (g.isFull()) {
        Colour winner = g.whoWon();
        if (winner == Colour::Black)
          cout << "Black Wins!" << endl;
        else if (winner == Colour::White)
          cout << "White Wins!" << endl;
        else
          cout << "Ties!" << endl;
        break;
      }
    }
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}
