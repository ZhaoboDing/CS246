#include <vector>
#include <utility>
#include "ppm.h"
#include "image.h"
#include "flip.h"

flip::flip(Image *img) : Decorator(img) {
  this->img = img;
}

void flip::render(PPM &ppm) {
  img->render(ppm);
  int width = ppm.getWidth();
  int height = ppm.getHeight();
  std::vector<Pixel> &pxl = ppm.getPixels();

  for (int i = 0; i < height; i++)
    for (int j = 0; j < width >> 1; j++) {
      int l = width * i + j;
      int r = width * i + width - j - 1;
      std::swap(pxl[l], pxl[r]);
    }
}

