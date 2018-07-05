#include "sepia.h"
#include "ppm.h"

unsigned int min(unsigned int x, unsigned int y) {
  if (x < y) return x; else return y;
}


sepia::sepia(Image *img): Decorator(img) {
  this->img = img;
}

void sepia::render(PPM &ppm) {
  img->render(ppm);
  std::vector<Pixel> &pxl = ppm.getPixels();

  for (auto itr = pxl.begin(); itr != pxl.end(); itr++) {
      Pixel tmp;
      tmp.r = itr->r * 0.393 + itr->g * 0.769 + itr->b * 0.189;
      tmp.g = itr->r * 0.349 + itr->g * 0.686 + itr->b * 0.168;
      tmp.b = itr->r * 0.272 + itr->g * 0.534 + itr->b * 0.131;
      itr->r = min(tmp.r, 255);
      itr->g = min(tmp.g, 255);
      itr->b = min(tmp.b, 255);
  }
}

