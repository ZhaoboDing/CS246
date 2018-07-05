#include <vector>
#include <utility>
#include "rotate.h"
#include "ppm.h"

rotate::rotate(Image *img): Decorator(img) {
  this->img = img;
}

void rotate::render(PPM &ppm) {
  img->render(ppm);
  std::swap(ppm.getHeight(), ppm.getWidth());
  int width = ppm.getWidth();
  int height = ppm.getHeight();

  std::vector<Pixel> &pxl = ppm.getPixels();
  std::vector<Pixel> tmp(width * height);
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      tmp[i * width + j] = pxl[(width - j - 1) * height + i];

  ppm.getPixels() = tmp;
}
