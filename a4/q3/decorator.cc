#include "decorator.h"

Decorator::Decorator(Image *img): img{img} {}

Decorator::~Decorator() {
  delete img;
}
