
#include "MyWindow.h"
#include <string>
using std::string;

int main(int argc, char* argv[]) {
	auto app = Gtk::Application::create( argc, argv, "org.gtkmm.example" );
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("sample.glade"); 
	MyWindow * window;
	builder->get_widget_derived( "topWindow", window ); 

	window->drawRectangle( MyWindow::Colour::YELLOW, 0, 0, 20, 40 );
	window->drawRectangle( MyWindow::Colour::GREEN, 20, 20, 30, 10 );
	window->drawRectangle( MyWindow::Colour::BLACK, 200, 200, 30, 100 );
	window->drawRectangle( MyWindow::Colour::RED, 400, 470, 30, 50 );
	window->drawText( 20, 30, "abc" );
	window->drawText( 120, 130, "def" );

	window->show_all();

	app->run( *window );
	delete window;
	return 0;
} // main
