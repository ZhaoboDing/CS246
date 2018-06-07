#include <cassert>

struct Car {
	unsigned int distance_ = 0;
	unsigned int distance() { return distance_; }
	unsigned int stoppingDistance() { return 5;}
};

unsigned int stoppingDistance( Car * carPtr ) {
	assert( carPtr != nullptr );
	unsigned int distance = carPtr->distance();
	assert( ("Internal error", distance > 0) );
	// do something with distance
	return distance;
}

int main() {
	Car fiat;
	unsigned int value = stoppingDistance( &fiat );
	return 0;
}