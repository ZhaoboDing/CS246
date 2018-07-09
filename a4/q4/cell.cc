#include "cell.h"

const Direction dirc[8] = {Direction::N, Direction::NE, Direction::E, Direction::SE,
                 Direction::S, Direction::SW, Direction::W, Direction::NW};
const int moveX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int moveY[8] = {1, 1, 0, -1, -1, -1, 0, 1};
// for each direction, we store the corresponding movement by x-axis and y-axis

int getDirc(Direction d) {
  for (int i = 0; i < 8; i++)
    if (dirc[i] == d) return i;
}

Direction findDirc(int x, int y) {
  if (x > 0)
    x = 1;
  else if (x < 0)
    x = -1;
  if (y > 0)
    y = 1;
  else if (y < 0)
    y = -1;
  // Normalize x and y so that we can find the direction by move array

  for (int i = 0; i < 8; i++)
    if (moveX[i] == x && moveY[i] == y)
      return dirc[i];
}

Cell::Cell(size_t r, size_t c): r{r}, c{c}, colour{Colour::NoColour} {}

void Cell::setPiece(Colour colour) {
  this->colour = colour;
  State s;
  s.colour = colour;
  s.type = StateType::NewPiece;
  s.direction = Direction::N;
  this->setState(s);
}

void Cell::toggle() {
  if (colour == Colour::Black)
    colour = Colour::White;
  else if (colour == Colour::White)
    colour = Colour::Black;
}

void Cell::notify(Subject<Info, State> &whoFrom) {
  State s = whoFrom.getState();
  Info  i = whoFrom.getInfo();
  State ss;

  ss.colour = s.colour;
  if (s.type == StateType::NewPiece)
    ss.direction = findDirc(r - i.row, c - i.col);
    // for NewPiece, we cannot directly get the direction
  else
    ss.direction = s.direction;

  if (s.colour == colour) {
    // once we find a cell with same colour, we go back
    ss.type = StateType::Reply;
    ss.direction = dirc[(getDirc(ss.direction) + 4) % 8];
  }
  else if (s.type == StateType::Reply) {
    // Reply implies we have found a same-colour cell
    toggle();
    ss.type = StateType::Reply;
  }
  else
    ss.type = StateType::Relay;

  setState(ss);
}

Info Cell::getInfo() const {
  Info info;
  info.col = c;
  info.row = r;
  info.colour = colour;
  return info;
}
