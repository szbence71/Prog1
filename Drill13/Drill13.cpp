#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
using namespace Graph_lib;

int main()
{
	try{
		// 1. Feladat
		// ablak létrehozása
		Simple_window win(Point(100, 100), 800, 1000, "Drill13");


		// 2. Feladat
		// grid létrehozása, négyzetrácsozás
		const int g_size = 100;
		const int g_max = 800;
		Lines grid;
		for (int i = g_size; i < g_max; i+=g_size)
		{
			grid.add(Point(i,0), Point(i, g_max));
			grid.add(Point(0,i), Point(g_max, i));
		}
		win.attach(grid);

		// 3. Feladat
		// piros négyzetek elhelyezése egy átlóban
		Vector_ref<Rectangle> negyzetek;
		for (int i = 0; i < 8; i++)
		{
			negyzetek.push_back(new Rectangle(Point(i * g_size, i * g_size), g_size, g_size));
			negyzetek[negyzetek.size()-1].set_fill_color(Color::red);
			win.attach(negyzetek[negyzetek.size()-1]);
		}
		win.wait_for_button();

		// 4. Feladat
		// 3 kép beállítása megfelelő helyre, illetve 200x200-asra vágása
		Image kep(Point(200,0), "kep.jpg");
		Image kep2(Point(400,200), "kep.jpg");
		Image kep3(Point(600, 400), "kep.jpg");
		kep.set_mask(Point(200,200), 200, 200);
		kep2.set_mask(Point(200,200), 200, 200);
		kep3.set_mask(Point(200,200), 200, 200);
		win.attach(kep);
		win.attach(kep2);
		win.attach(kep3);

		// 5. feladat
		// egy kép végigléptetése mind a 64 négyzeten
		Image kep4(Point(0,0),"kep.jpg");
		kep4.set_mask(Point(200,200), 100, 100);
		win.attach(kep4);
		int ossz = 64; // Összesen 64 négyzet lett kirajzolva, ezeken lépked végig 
		int n = 1; // Már fentebb ki lett 1x rajzolva ezért nem 0
		int xx = 100; // X lépésköz
		int yy = 0; // Y lépésköz
		for(int i = 0; i < ossz; i++)
		{
			if(n == 8) // Ha eléri a 8-at az n változó (számláló), új sorba ugrik a kép
			{
				yy = yy + 100; // Eggyel lentebb kerül
				n = 0; // Számláló visszaállítása
				xx = - 700; // Az új sorban az első négyzetre kerül (800-700)
			}
			win.wait_for_button();
			kep4.move(xx, yy);
			n++; 
			yy = 0;
			xx = 100;
		}

		win.wait_for_button();
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
		keep_window_open();
	}
	catch(...)
	{
		cerr << "exception\n" << endl;
		keep_window_open();
	}

}