#ifndef _MYWINDOW_H
#define _MYWINDOW_H
#include <gtkmm.h>

class MyDrawingArea;

class MyWindow: public Gtk::Window {
	public:
		enum class Colour { BLACK, WHITE, RED, GREEN, BLUE, YELLOW };
		const static int MAX_WIDTH;
		const static int MAX_HEIGHT;

		MyWindow( BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder );
		virtual ~MyWindow();

		void drawRectangle( MyWindow::Colour, int x, int y, int width, int height ); 
		// Colour of rectangle, coordinates of upper-left corner, width and height of rectangle
		void drawText( int x, int y, std::string msg );
		// Message to write, and position of upper-left corner.
#if 0
	protected:
		// Override default signal handler:
		bool on_draw( const Cairo::RefPtr<Cairo::Context>& cr ) override;
#endif
		
	private:
		Glib::RefPtr<Gtk::Builder> builder_;
		MyDrawingArea * drawingArea_;
		Gtk::Entry * commandEntry_;
		Gtk::ScrolledWindow * scwin_;

		void processCommand(); // triggered when client presses enter in Entry widget
		void onQuit();
};

#endif