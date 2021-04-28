#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

//function
double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	using namespace Graph_lib;

	//Ablak
	Simple_window win {Point{100, 100}, 600, 600, "Function Graphs"}; 

	//x tengely
	Axis xa(Axis::x, Point{100, 300}, 400, 20, "x");
	xa.set_color(Color::red);
	win.attach(xa);

	//y tengely
	Axis ya(Axis::y, Point{300, 500}, 400, 20, "y");
	ya.set_color(Color::red);
	win.attach(ya);

	//deklarálások
	const int minrange = -10; //function range min
	const int maxrange = 11; //function range max
	const int num_points = 400;
	const int xscale = 20; 
	const int yscale = 20;
	const Point o {300, 300}; //origo

	//vízszintes
	Function fct_one {one, minrange, maxrange, o, num_points, xscale, yscale};
	win.attach(fct_one);
	win.wait_for_button();

	//átló
	Function fct_slope {slope, minrange, maxrange, o, num_points, xscale, yscale};
	Text slope_label{Point{100, 380}, "x/2"};
	win.attach(fct_slope);
	win.attach(slope_label);
	win.wait_for_button();

	//parabola
	Function fct_square {square, minrange, maxrange, o, num_points, xscale, yscale};
	win.attach(fct_square);
	win.wait_for_button();

	//cos hullám
	Function fct_cos {cos, minrange, maxrange, o, num_points, xscale, yscale};
	fct_cos.set_color(Color::blue);
	win.attach(fct_cos);
	win.wait_for_button();

	//átló cos hullám
	Function fct_sloping_cos {sloping_cos, minrange, maxrange, o, num_points, xscale, yscale};
	win.attach(fct_sloping_cos);

	win.wait_for_button();
}