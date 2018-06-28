#include "mydrawingarea.h"
using namespace std;

const int MyDrawingArea::MAX_WIDTH = 500;
const int MyDrawingArea::MAX_HEIGHT = 500;
vector<MyDrawingArea::RGB> MyDrawingArea::colours;

MyDrawingArea::RGB::RGB(int r, int g, int b ) 
  : r{r}, g{g}, b{b} {}

MyDrawingArea::Rectangle::Rectangle( Colour c, int x, int y, int width, int height ) 
  : c{c}, x{x}, y{y}, width{width}, height{height} {}

MyDrawingArea::Message::Message( int x, int y, std::string msg )
  : x{x}, y{y}, msg{msg} {}

MyDrawingArea::MyDrawingArea() {
  Gtk::Allocation allocation = get_allocation();
  allocation.set_width( MyDrawingArea::MAX_WIDTH );
  allocation.set_height( MyDrawingArea::MAX_HEIGHT );
  if ( colours.size() == 0 ) createColours();
} // MyDrawingArea::MyDrawingArea

MyDrawingArea::~MyDrawingArea() {
  rectangles.clear();
}

int MyDrawingArea::index( Colour c ) {
  return static_cast<int>(c);
}

void MyDrawingArea::createColours() {
  colours.emplace_back( RGB{ 0, 0, 0 } );       // BLACK
  colours.emplace_back( RGB{ 255, 255, 255 } ); // WHITE
  colours.emplace_back( RGB{ 255, 0, 0 } );     // RED
  colours.emplace_back( RGB{ 0, 255, 0 } );     // GREEN
  colours.emplace_back( RGB{ 0, 0, 255 } );     // BLUE
  colours.emplace_back( RGB{ 255, 255, 0 } );   // YELLOW
} // MyDrawingArea::createColours

void MyDrawingArea::drawRectangle( Colour c, int x, int y, int width, int height ) {
  rectangles.push_back( Rectangle{c,x,y,width,height} );
}

void MyDrawingArea::drawText( int x, int y, string msg ) {
  messages.push_back( Message{x,y,msg} );
}

bool MyDrawingArea::on_draw( const Cairo::RefPtr<Cairo::Context>& cr ) {
  cr->save(); // remember our previous state since we're changing colours
  for ( auto it : rectangles ) {
    draw_rectangle( cr, it.c, it.x, it.y, it.width, it.height );
  } // for
  cr->restore(); // put it back 

  for ( auto it : messages ) {
    draw_text( cr, it.x, it.y, it.msg );
  } // for

  return true;
} // MyDrawingArea::on_draw

void MyDrawingArea::draw_rectangle( const Cairo::RefPtr<Cairo::Context>& cr, Colour c, int x, int y, int width, int height) {
  int i = index(c);
  cr->set_source_rgb( colours[i].r, colours[i].g, colours[i].b );
  cr->rectangle( x, y, width, height);
  cr->fill();
}

void MyDrawingArea::draw_text( const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, const string & s ) {
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
} // MyDrawingArea::draw_text
