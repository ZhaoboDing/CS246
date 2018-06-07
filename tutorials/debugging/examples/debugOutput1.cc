#include <iostream>

#define DPRT( title, expr ) \
{ std::cerr << #title "\t\"" << __PRETTY_FUNCTION__ << "\" " << expr << " in " \
    << __FILE__ << " at line " << __LINE__ << std::endl; }

int test( int a, int b ) {
	DPRT( ENTER, "a:" << a << "b:" << b );
	if ( a < b ) DPRT( a < b, "a:"<< a <<"b:"<< b ); 
	DPRT( , a + b ); // empty title
	DPRT( HERE, "" ); // empty expression 
	DPRT( EXIT, a );
	return a;
}

int main() {
	test( 3, 4 );
	return 0;
}
