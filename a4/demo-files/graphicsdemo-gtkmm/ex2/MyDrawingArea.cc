#include "MyDrawingArea.h"
using std::vector;
using std::string;

vector<MyDrawingArea::RGB> MyDrawingArea::colours;

MyDrawingArea::RGB::RGB( int r, int g, int b ) 
  : r{r}, g{g}, b{b} {}

MyDrawingArea::Rectangle::Rectangle( MyWindow::Colour c, int x, int y, int width, int height ) 
  : c{c}, x{x}, y{y}, width{width}, height{height} {}

MyDrawingArea::Message::Message( int x, int y, std::string msg )
  : x{x}, y{y}, msg{msg} {}

MyDrawingArea::MyDrawingArea( BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder )
			: Gtk::DrawingArea{cobject}, builder_{builder}
{
	if ( colours.size() == 0 ) createColours();
} 

MyDrawingArea::~MyDrawingArea() {
	rectangles.clear();
	messages.clear();
} // MyDrawingArea::~MyDrawingArea

unsigned int MyDrawingArea::index( MyWindow::Colour c ) {
	return static_cast<unsigned int>(c);
}

void MyDrawingArea::createColours() {
	colours.emplace_back( MyDrawingArea::RGB{ 0, 0, 0 } );       // BLACK
	colours.emplace_back( MyDrawingArea::RGB{ 255, 255, 255 } ); // WHITE
	colours.emplace_back( MyDrawingArea::RGB{ 255, 0, 0 } );     // RED
	colours.emplace_back( MyDrawingArea::RGB{ 0, 255, 0 } );     // GREEN
	colours.emplace_back( MyDrawingArea::RGB{ 0, 0, 255 } );     // BLUE
	colours.emplace_back( MyDrawingArea::RGB{ 255, 255, 0 } );   // YELLOW
} // MyDrawingArea::createColours

void MyDrawingArea::drawRectangle( MyWindow::Colour c, int x, int y, int width, int height ) {
	rectangles.push_back( MyDrawingArea::Rectangle{c,x,y,width,height} );
	queue_draw(); // Request re-drawing. 
}

void MyDrawingArea::drawText( int x, int y, string msg ) {
	messages.push_back( MyDrawingArea::Message{x,y,msg} );
	queue_draw(); // Request re-drawing. 
}

bool MyDrawingArea::on_draw( const Cairo::RefPtr<Cairo::Context>& cr ) {
	cr->save();
	cr->set_source_rgb( 200, 200, 200 );
	cr->rectangle( 0, 0, MyWindow::MAX_WIDTH, MyWindow::MAX_HEIGHT );
	cr->fill();
	cr->restore();

	for ( auto it : rectangles ) {
		draw_rectangle( cr, it.c, it.x, it.y, it.width, it.height );
	} // for

	for ( auto it : messages ) {
		draw_text( cr, it.x, it.y, it.msg );
	} // for
	return true;
} // MyDrawingArea::on_draw

void MyDrawingArea::draw_rectangle( const Cairo::RefPtr<Cairo::Context>& cr, MyWindow::Colour c, int x, int y, int width, int height) {
	cr->save();
	unsigned int i = index(c);
	cr->set_source_rgb( colours[i].r, colours[i].g, colours[i].b );
	cr->rectangle( x, y, width, height);
	cr->fill();
	cr->restore();
} // MyDrawingArea::draw_rectangle

void MyDrawingArea::draw_text( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, const string & s ) {
	cr->save();
	// http://developer.gnome.org/pangomm/unstable/classPango_1_1FontDescription.html
	Pango::FontDescription font;

	font.set_family( "Monospace" );
	font.set_weight( Pango::WEIGHT_BOLD );

	// http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
	auto layout = create_pango_layout( s );
	layout->set_font_description(font);

	int text_width;
	int text_height;

	layout->get_pixel_size(text_width, text_height); //get the text dimensions
	cr->move_to(x, y); // Position the text
	layout->show_in_cairo_context( cr );
	cr->restore();
} // MyDrawingArea::draw_text