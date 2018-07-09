#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H

#include <vector>
#include "window.h"
#include "observer.h"
#include "state.h"
#include "info.h"

class Cell;

class GraphicDisplay: public Observer<Info, State> {
  std::vector<std::vector<char>> theDisplay;
  const int gridSize;
  const int cellSize;
  Xwindow *win = nullptr;
public:
  GraphicDisplay(int n);

  ~GraphicDisplay();

  void notify(Subject<Info, State> &whoNotified) override;

  void draw();
};

#endif
