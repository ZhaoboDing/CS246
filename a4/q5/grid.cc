#include <vector>
#include "grid.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

const Direction dirc[8] = {Direction::N, Direction::NE, Direction::E, Direction::SE,
                 Direction::S, Direction::SW, Direction::W, Direction::NW};
const int moveX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int moveY[8] = {1, 1, 0, -1, -1, -1, 0, 1};
// for each direction, we store the corresponding movement by x-axis and y-axis

int getDircNum(Direction d) {
  for (int i = 0; i < 8; i++)
    if (dirc[i] == d) return i;
}

void Grid::setObserver(Observer<Info, State> *ob) {
  this->ob = ob;
}

bool Grid::isFull() const {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (theGrid[i][j].getInfo().colour == Colour::NoColour)
        return false;

  return true;
}

Colour Grid::whoWon() const {
  int w = 0, b = 0;

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      // count number of cells of different colours
      Colour c = theGrid[i][j].getInfo().colour;
      if (c == Colour::Black)
        b++;
      else if (c == Colour::White)
        w++;
      else
        return Colour::NoColour;
    }

  if (w > b)
    return Colour::White;
  else if (w < b)
    return Colour::Black;
  else
    return Colour::NoColour; // NoColour implies tie
}

void Grid::init(size_t n) {
  size = n;
  td = new TextDisplay(n);
  gd = new GraphicDisplay(n);

  while (!theGrid.empty()) // Clear the grid
    theGrid.pop_back();

  for (int i = 0; i < n; i++) {
    std::vector<Cell> v;
    for (int j = 0; j < n; j++) {
      Cell c{i, j};
      v.emplace_back(c);
    }
    theGrid.emplace_back(v);
  }

  theGrid[n / 2 - 1][n / 2 - 1].setPiece(Colour::Black);
  theGrid[n / 2    ][n / 2    ].setPiece(Colour::Black);
  theGrid[n / 2 - 1][n / 2    ].setPiece(Colour::White);
  theGrid[n / 2    ][n / 2 - 1].setPiece(Colour::White);
  // Set the four initialized colours
}

void Grid::setPiece(size_t r, size_t c, Colour colour) {
  theGrid[r][c].setPiece(colour);
  State s;
  s.colour = colour;
  s.type = StateType::NewPiece;

  for (int i = 0; i < 8; i++) {
    s.direction = dirc[i];
    // we do a DFS-like notifying
    int a = r, b = c;
    int x = a + moveX[i];
    int y = b + moveY[i];
    while (0 <= x && x < size && 0 <= y && y < size && (x != r || y != c)) {
      if (theGrid[x][y].getInfo().colour == Colour::NoColour)
        break;

      theGrid[x][y].notify(theGrid[a][b]);

      Direction updated = theGrid[x][y].getState().direction;
      int XDirc = moveX[getDircNum(updated)];
      int YDirc = moveY[getDircNum(updated)];
      a = x; b = y; x += XDirc; y += YDirc;
    }
  }
}

void Grid::toggle(size_t r, size_t c) {
  theGrid[r][c].toggle();
}

Grid::~Grid() {
  delete td;
  delete gd;
  delete ob;
}

void Grid::draw() {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      Cell c = theGrid[i][j];
      gd->notify(c);
    }

  gd->draw();
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
  for (int i = 0; i < g.size; i++)
    for (int j = 0; j < g.size; j++) {
      Cell c = g.theGrid[i][j];
      g.td->notify(c);
    }

  out << *(g.td);
  return out;
}


