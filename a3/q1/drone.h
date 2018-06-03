#ifndef __DRONE_H__
#define __DRONE_H__
#include <iostream>

struct Position {
  int ew, ns;
  Position( int ew = 0, int ns = 0);
};

const int maxSteps = 50;
extern bool fail;

struct Drone {
    // You may add fields and methods as you see fit
    // Do *not* change the provided methods.
  

  Drone();
  ~Drone() {
    if (fail) std::cout << "Failure" << std::endl;
  }
  void forward(); 
  void backward(); 
  void left();
  void right();
  Position current() const;
  int totalDistance() const;
  int manhattanDistance() const;
  bool repeated() const;
};

#endif
