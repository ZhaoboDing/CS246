#include "textdisplay.h"
#include "subject.h"

TextDisplay::TextDisplay(int n): gridSize{n} {
  theDisplay.resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      theDisplay[i].emplace_back('-');

  theDisplay[n / 2 - 1][n / 2 - 1] = theDisplay[n / 2][n / 2] = 'B';
  theDisplay[n / 2 - 1][n / 2] = theDisplay[n / 2][n / 2 - 1] = 'W';
}

void TextDisplay::notify(Subject<Info, State> &whoNotified) {
  Info info = whoNotified.getInfo();
  if (info.colour == Colour::Black)
    theDisplay[info.row][info.col] = 'B';
  else if (info.colour == Colour::White)
    theDisplay[info.row][info.col] = 'W';
  else
    theDisplay[info.row][info.col] = '-';
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
  for (int i = 0; i < td.gridSize; i++) {
    for (int j = 0; j < td.gridSize; j++)
      out << td.theDisplay[i][j];
    out << std::endl;
  }

  return out;
}
