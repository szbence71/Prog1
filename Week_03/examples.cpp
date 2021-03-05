#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try {
	using namespace Graph_lib;
	
	Point t1(200, 50);
	Simple_window win(t1, 1200, 800, "Labor 3");
	
	Graph_lib::Arc arc1(Point(150, 100), 100, 50, 45, 175);
	win.attach(arc1);
	arc1.set_color(Color::red);
	arc1.set_angle1(-15);
	arc1.set_angle2(270);
	arc1.set_angles(-175, -5);
	
	// win.wait_for_button();
	
	Graph_lib::Arc arc2(Point(200, 200), 50, 90, -175, -5);
	arc2.set_color(Color::green);
	arc2.set_fill_color(Color::blue);
	win.attach(arc2);
	
	// win.wait_for_button();
	
	Box box1(Point(350, 350), 100, 80);
	win.attach(box1);
	// win.wait_for_button();
	
	Box box2(Point(450, 350), 200, 100, 25);
	win.attach(box2);
	// win.wait_for_button();
	
	Arrow arrow1(Point(100,500), Point(400,450));
	win.attach(arrow1);
	Arrow arrow2(Point(300,300), Point(250,250));
	win.attach(arrow2);
	arrow2.set_color(Color::red);
	arrow2.set_fill_color(Color::green);
	arrow2.set_style(Line_style::dot);
	//win.wait_for_button();	
	
	Graph_lib::Rectangle rect1(Point(500,150),150,150);
	win.attach(rect1);
	Arrow nwr(nw(rect1), Point(nw(rect1).x-30, nw(rect1).y-30));
	win.attach(nwr);
	Arrow nr(n(rect1), Point(n(rect1).x, n(rect1).y-30));
	win.attach(nr);
	
	Arrow ner(ne(rect1), Point(ne(rect1).x+30, ne(rect1).y-30));
	win.attach(ner);
	Arrow er(e(rect1), Point(e(rect1).x+30, e(rect1).y));
	win.attach(er);
	Arrow ser(se(rect1), Point(se(rect1).x+30, se(rect1).y+30));
	win.attach(ser);
	Arrow sr(s(rect1), Point(s(rect1).x, s(rect1).y+30));
	win.attach(sr);
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
