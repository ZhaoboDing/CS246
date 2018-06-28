#include "MyWindow.h"
#include "MyDrawingArea.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

const int MyWindow::MAX_WIDTH = 500;
const int MyWindow::MAX_HEIGHT = 520;


MyWindow::MyWindow( BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder ): Gtk::Window{cobject}, builder_{builder} {
	set_title( "Drawing example" );
	//set_default_size( MyWindow::MAX_WIDTH, MyWindow::MAX_HEIGHT );

	builder_->get_widget_derived( "drawingarea", drawingArea_ ); 
	builder_->get_widget( "scrolledwindow", scwin_ );
	builder_->get_widget( "entry", commandEntry_ ); 
	drawingArea_->set_size_request( MyWindow::MAX_WIDTH, MyWindow::MAX_HEIGHT );
	scwin_->set_min_content_height( MyWindow::MAX_HEIGHT );
	scwin_->set_min_content_width( MyWindow::MAX_WIDTH );
	scwin_->set_policy( Gtk::PolicyType::POLICY_ALWAYS, Gtk::PolicyType::POLICY_ALWAYS );

	Glib::RefPtr<Gtk::Action>::cast_dynamic( builder_->get_object( "action_quit" ))-> 
		signal_activate().connect( sigc::mem_fun( *this, &MyWindow::onQuit )); 
		
	// Tie the Gtk::Entry signal generated when <Enter> pressed to MyWindow::processCommand
	commandEntry_->signal_activate().connect(
		sigc::mem_fun( *this, &MyWindow::processCommand ));

	//show_all_children();
	show_all();
} // MyWindow::MyWindow

MyWindow::~MyWindow() {}

void MyWindow::onQuit() { hide(); } 

void MyWindow::processCommand() {
	std::cout << "command: " << commandEntry_->get_text() << endl;
	drawText( 100, 200, commandEntry_->get_text() );
	commandEntry_->set_text( "" );
} // MyWindow::processCommand

void MyWindow::drawRectangle( MyWindow::Colour c, int x, int y, int width, int height ) {
	drawingArea_->drawRectangle( c, x, y, width, height );
}

void MyWindow::drawText( int x, int y, string msg ) {
	drawingArea_->drawText( x, y, msg );
}
