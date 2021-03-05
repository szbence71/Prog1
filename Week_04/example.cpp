#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try{
	using namespace Graph_lib;
	
	Point t1(200, 50);
	Simple_window win(t1, 1200, 800, "Labor 4");
	
	Smiley s1(Point (600, 400), 150);
	win.attach(s1);
	s1.set_fill_color(Color::yellow);
	
	win.wait_for_button();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}
