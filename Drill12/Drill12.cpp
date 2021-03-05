#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
try {
	// Ablak
	Point t1(100,100);
	Simple_window win (t1, 700, 800, "My Window");
	win.wait_for_button();
	
	// X tengely
	Axis xa{Axis::x, Point{20, 230}, 560, 20, "x tengely"};
	win.attach(xa);
	win.wait_for_button();
	
	// Y tengely
	Axis ya{Axis::y, Point{300, 550}, 560, 20, "y tengely"};
	win.attach(ya);
	win.wait_for_button();
	
	// Hullám
	Function sine {sin, 0, 100, Point{20, 230}, 280, 25, 25};
	win.attach(sine);
	sine.set_color(Color::dark_red);
	sine.set_style(Line_style{Line_style::solid, 5});
	win.wait_for_button();
	
	// Háromszög
	Polygon poly;
	poly.add(Point{310, 150});
	poly.add(Point{410, 150});
	poly.add(Point{360, 50});
	poly.set_color(Color::yellow);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.wait_for_button();
	
	// Négyzet
	Rectangle r {Point{310, 150}, 100, 100};
	r.set_fill_color(Color::blue);
	win.attach(r);
	win.wait_for_button();
	
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100, 500});
	poly_rect.add(Point{300, 500});
	poly_rect.add(Point{300, 550});
	poly_rect.add(Point{100, 550});
	poly_rect.add(Point{50, 525});
	poly_rect.set_style(Line_style(Line_style::dash, 5));
	poly_rect.set_fill_color(Color::yellow);
	win.attach(poly_rect);
	win.wait_for_button();
	
	// Szöveg
	Text t {Point{300, 440}, "Hello, World!"};
	t.set_font(Font::times_bold);
	t.set_font_size(30);
	win.attach(t);
	win.set_label("Elso");
	win.wait_for_button();
	
	// Kép
	Image ii {Point{100, 50}, "h.jpg"};
	win.attach(ii);
	win.set_label("Masodik");
	win.wait_for_button();
	ii.move(294,339);
	win.set_label("Harmadik");
	
	// Kör
	Circle c {Point{100, 200}, 50};
	c.set_color(Color::red);
	Mark m {Point{100, 200}, 'x'};
	win.wait_for_button();
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{0, 700}, oss.str()};
	
	win.attach(c);
	win.attach(m);
	win.attach(sizes);
	win.set_label("Negyedik");
	win.wait_for_button();
}

catch(exception &e) {
	cerr << "exception" << e.what() << '\n';
	return 1;
}

catch(...) {
	cerr << "error \n";
	return 2;
}
