#ifndef _MAKEFILE_
#define _MAKEFILE_
#include <string>
#include <iostream>
#include "target.h"

const int maxTargets = 20;

struct Makefile {     // You may add fields and methods as you 
                      // see fit. Do *not* change the provided methods.



  Makefile(std::ostream &out = std::cout);
  
  ~Makefile();

  void addDepend(const std::string &t, const std::string &d);

  void changeTarget(const std::string &t);

  void rebuild(const std::string &t);
};

#endif
