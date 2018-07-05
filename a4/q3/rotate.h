#ifndef ROTATE_H
#define ROTATE_H

#include "image.h"
#include "decorator.h"

class rotate : public Decorator {
public:
  rotate(Image *img);
  void render(PPM &ppm);
};

#endif
