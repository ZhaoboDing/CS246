#ifndef MY_DRAWING_AREA_H
#define MY_DRAWING_AREA_H

#include <gtkmm/drawingarea.h>
#include <vector>
#include <string>

class MyDrawingArea : public Gtk::DrawingArea {
public:
	enum class Colour { BLACK, WHITE, RED, GREEN, BLUE, YELLOW };
	const static int MAX_WIDTH;
	const static int MAX_HEIGHT;

	MyDrawingArea();
	virtual ~MyDrawingArea();
	void drawRectangle( Colour, int x, int y, int width, int height ); 
	// Colour of rectangle, coordinates of upper-left corner, width and height of rectangle
	void drawText( int x, int y, std::string msg );
	// Message to write, and position of upper-left corner.

protected:
	// Override default signal handler:
	bool on_draw( const Cairo::RefPtr<Cairo::Context>& cr ) override;

private:
	struct RGB {
		int r,g,b;
		RGB(int r = 0, int g = 0, int b = 0 );
	};

	struct Rectangle {
		Colour c; // colour of filled rectangle
		int x, y; // position of upper-left corner
		int width, height; // width and height 
		Rectangle( Colour c, int x, int y, int width, int height );
	};

	struct Message {
		int x, y;
		std::string msg;
		Message( int x, int y, std::string msg );
	};

	int index( Colour ); // returns the index value associated with the Colour

	void draw_rectangle( const Cairo::RefPtr<Cairo::Context>& cr, Colour c, int x, int y, int width, int height );
	void draw_text( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, const std::string & s );

	static void createColours(); // initializes RGB values for the enumerated colours
	static std::vector<MyDrawingArea::RGB> colours; // set of RGB values
	std::vector<MyDrawingArea::Rectangle> rectangles; // rectangles to draw
	std::vector<MyDrawingArea::Message> messages; // messages to draw
};

#endif // MY_DRAWING_AREA_H
