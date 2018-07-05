#ifndef SEPIA_H
#define SEPIA_H

#include "image.h"
#include "decorator.h"

class sepia : public Decorator {
public:
  sepia(Image *img);
  void render(PPM &ppm);
};

#endif
