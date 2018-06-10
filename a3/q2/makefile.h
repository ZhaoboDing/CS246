#ifndef _MAKEFILE_
#define _MAKEFILE_
#include <string>
#include <iostream>
#include "target.h"

const int maxTargets = 20;

struct Makefile {     // You may add fields and methods as you 
                      // see fit. Do *not* change the provided methods.
  std::ostream *out = &std::cout;
  Target *fileList[maxTargets];
  int fileNum;

  int sysClock;
  
  Target *getFileByName(const std::string &f, bool add = false);

  Makefile(std::ostream &out = std::cout);
  
  ~Makefile();

  void addDepend(const std::string &t, const std::string &d);

  void changeTarget(const std::string &t);

  void rebuild(const std::string &t);
};

#endif
