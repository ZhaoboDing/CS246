#include "subject.h"
#include "graphicdisplay.h"

GraphicDisplay::GraphicDisplay(int n): gridSize{n}, cellSize{499 / n - 1} {
  theDisplay.resize(n);
  win = new Xwindow(500, 500);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      theDisplay[i].emplace_back('-');

  theDisplay[n / 2 - 1][n / 2 - 1] = theDisplay[n / 2][n / 2] = 'B';
  theDisplay[n / 2 - 1][n / 2] = theDisplay[n / 2][n / 2 - 1] = 'W';
}

GraphicDisplay::~GraphicDisplay() {
  delete win;
}

void GraphicDisplay::notify(Subject<Info, State> &whoNotified) {
  Info info = whoNotified.getInfo();
  if (info.colour == Colour::Black)
    theDisplay[info.row][info.col] = 'B';
  else if (info.colour == Colour::White)
    theDisplay[info.row][info.col] = 'W';
  else
    theDisplay[info.row][info.col] = '-';
}

void GraphicDisplay::draw() {
  for (int i = 0; i < gridSize; i++)
    for (int j = 0; j < gridSize; j++) {
      int x = j * (cellSize + 1) + 1;
      int y = i * (cellSize + 1) + 1;
      if (theDisplay[i][j] == 'B')
        win->fillRectangle(x, y, cellSize, cellSize, Xwindow::Black);
      else if (theDisplay[i][j] == 'W')
        win->fillRectangle(x, y, cellSize, cellSize, Xwindow::White);
      else
        win->fillRectangle(x, y, cellSize, cellSize, Xwindow::Blue);
    }

  int winSize = gridSize * (cellSize + 1) + 1;
  for (int i = 0; i <= gridSize; i++) {
    win->fillRectangle(i * (cellSize + 1), 0, 1, winSize, Xwindow::Red);
    win->fillRectangle(0, i * (cellSize + 1), winSize, 1, Xwindow::Red);
  }
}

