
#include "mydrawingarea.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <string>
using std::string;

int main(int argc, char* argv[]) {
  auto app = Gtk::Application::create( argc, argv, "org.gtkmm.example" );
  Gtk::Window window;
  window.set_title( "Drawing text example" );
  window.set_default_size( MyDrawingArea::MAX_WIDTH, MyDrawingArea::MAX_HEIGHT );
  MyDrawingArea area;
  window.add( area );

  area.drawRectangle( MyDrawingArea::Colour::YELLOW, 0, 0, 20, 40 );
  area.drawRectangle( MyDrawingArea::Colour::GREEN, 20, 20, 30, 10 );
  area.drawRectangle( MyDrawingArea::Colour::BLACK, 200, 200, 30, 100 );
  area.drawRectangle( MyDrawingArea::Colour::WHITE, 400, 470, 30, 50 );
  area.drawText( 20, 30, "abc" );
  area.drawText( 120, 130, "def" );

  window.show_all();

  return app->run( window );
}
