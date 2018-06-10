#include "drone.h"

int moveX[4] = {0, 1, 0,  -1};
int moveY[4] = {1, 0, -1, 0 };

int absolute(int x) {
	if (x > 0) return x; else return -x;
}

Position::Position(int ew, int ns) {
	this->ew = ew;
	this->ns = ns;
}

Drone::Drone() {
	dirc = 0; // Face north at the beginning
	dist = 0;

	for (int i = 0; i <= fuel * 2; i++)
		for (int j = 0; j <= fuel * 2; j++)
			visited[i][j] = false;
}

Drone::~Drone() {
	return;
}

void Drone::forward() {
	visited[pos.ew + fuel][pos.ns + fuel] = true;
	pos.ew += moveX[dirc];
	pos.ns += moveY[dirc];
	dist++;
}

void Drone::backward() {
	visited[pos.ew + fuel][pos.ns + fuel] = true;
	pos.ew -= moveX[dirc];
	pos.ns -= moveY[dirc];
	dist++;
}

void Drone::left() {
	dirc = (dirc + 3) % 4;
}

void Drone::right() {
	dirc = (dirc + 1) % 4;
}

Position Drone::current() const {
	return pos;
}

int Drone::totalDistance() const {
	return dist;
}

int Drone::manhattanDistance() const {
	return absolute(pos.ew) + absolute(pos.ns);
}

bool Drone::repeated() const {
	return visited[pos.ew + fuel][pos.ns + fuel];
}
