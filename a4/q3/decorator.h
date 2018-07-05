#ifndef DECORATOR_H
#define DECORATOR_H

#include "image.h"
#include "ppm.h"

class Decorator : public Image {
protected:
  Image *img;

public:
  Decorator(Image *img);
  virtual ~Decorator();
  virtual void render(PPM &ppm) = 0;
};

#endif
