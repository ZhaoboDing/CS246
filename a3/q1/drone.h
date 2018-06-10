#ifndef __DRONE_H__
#define __DRONE_H__
#include <iostream>

struct Position {
	int ew, ns;
	Position(int ew = 0, int ns = 0);
};

const int maxSteps = 50;

struct Drone {
	// You may add fields and methods as you see fit
	// Do *not* change the provided methods.

	static const int fuel = maxSteps;

	Position pos;
	int dirc; // 0 for North, 1 for East, 2 for South and 3 for West
	int dist; // the distance Drone has travelled
	bool visited[fuel * 2 + 1][fuel * 2 + 1];

	Drone();
	~Drone();
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
