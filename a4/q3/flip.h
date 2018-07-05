#ifndef FLIP_H
#define FLIP_H

#include "image.h"
#include "decorator.h"

class flip : public Decorator {
public:
  flip(Image *img);
  void render(PPM &ppm);
};

#endif
