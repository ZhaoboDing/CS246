#ifndef MY_DRAWING_AREA
#define MY_DRAWING_AREA
#include <vector>
#include <string>
#include "MyWindow.h"

class MyDrawingArea: public Gtk::DrawingArea {
public:
	MyDrawingArea(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
	virtual ~MyDrawingArea();

	void drawRectangle( MyWindow::Colour, int x, int y, int width, int height ); 
	// Colour of rectangle, coordinates of upper-left corner, width and height of rectangle
	void drawText( int x, int y, std::string msg );
	// Message to write, and position of upper-left corner.

private:
	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

	struct RGB {
		int r,g,b;
		RGB(int r = 0, int g = 0, int b = 0 );
	};

	struct Rectangle {
		MyWindow::Colour c; // colour of filled rectangle
		int x, y; // position of upper-left corner
		int width, height; // width and height 
		Rectangle( MyWindow::Colour c, int x, int y, int width, int height );
	};

	struct Message {
		int x, y;
		std::string msg;
		Message( int x, int y, std::string msg );
	};

	static std::vector<MyDrawingArea::RGB> colours; // set of RGB values
	static void createColours(); // initializes RGB values for the enumerated colours

	unsigned int index( MyWindow::Colour ); // returns the index value associated with the Colour
	void draw_rectangle( const Cairo::RefPtr<Cairo::Context>& cr, MyWindow::Colour c, int x, int y, int width, int height );
	void draw_text( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, const std::string & s );

	Glib::RefPtr<Gtk::Builder> builder_;
	std::vector<MyDrawingArea::Rectangle> rectangles; // rectangles to draw
	std::vector<MyDrawingArea::Message> messages; // messages to draw
};

#endif