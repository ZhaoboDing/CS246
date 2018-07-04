#include "Card.h"
#include "EuchreDeck.h"
#include "Hand.h"
//#include "Table.h"
//#include "DiscardPile.h"
//#include "Command.h"
//#include "GameLogic.h"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int main( int argc, char *argv[] ) {
	int seed = 0;
	if ( argc > 1 ) seed = atoi( argv[1] );
	
	EuchreDeck d( seed );
	cout << "initial deck:\n" << d << endl;
	d.shuffle();
	cout << "shuffled deck:\n" << d << endl;

	vector<Hand*> hands;
	for ( int i = 0; i < 4; i++ ) {
		hands.emplace_back( d.createHand( i ) );
		cout << "hand: " << *hands.at(i) << endl;
		cout << "deck: " << d << endl;
	} // for
	d.createKitty();
	cout << "deck after kitty created:\n" << d << endl;
	cout << "top card of kitty = " << *(d.topCardOfKitty()) << endl;
	for ( auto it : hands ) delete it;
	hands.clear();

	d.reset();
	cout << "\ndeck after being reset:\n" << d << endl;

	d.shuffle();
	cout << "shuffled deck:\n" << d << endl;

	//GameLogic g;
	//g.start();
} // main
