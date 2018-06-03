#ifndef _TARGET_H_
#define _TARGET_H_
#include <iostream>
#include <string>

const int maxDepends = 10;

struct Target {  // You may add fields and methods as you see fit
                      // Do *not* change the provided methods.
  

  Target(const std::string &name, std::ostream &out = std::cout);
  bool isLeaf() const;
  void addDepend(Target *d);
  void update(int time);
  int lastUpdated() const;
  void build();
};

#endif
