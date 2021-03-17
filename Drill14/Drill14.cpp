#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
using namespace Graph_lib;


class P{
public:
	virtual void pvf()=0;
};

class B1 : public P {
public:
	virtual void vf() { cout << "B1::vf()" << endl; }
	void f() { cout << "B1::f()" << endl; }
	void pvf() { cout << "B1::pvf()" << endl; }
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
	void vf() override { cout << "D1::vf()" << endl; }
	void f() { cout << "D1::f()" << endl; }
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2::pvf()" << endl; }
};

class D21 : public B2 {
	string s = "String";
	void pvf() override { cout << s << endl; }
};

class D22 : public B2 {
	int i = 420;
	void pvf() override { cout << i << endl; }
};

void f(B2& b1){
	b1.pvf();
};

int main()
{
	cout << "B1" << endl;
	B1 b1;
	b1.vf();
	b1.f();
	b1.pvf();
	cout << endl;

	cout << "D1" << endl;
	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();
	cout << endl;

	cout << "B1&" << endl;
	B1& b1b(d1);
	b1b.vf();
	b1b.f();
	b1b.pvf();
	cout << endl;

	cout << "D2" << endl;
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	cout << endl;

	cout << "D21" << endl;
	D21 d21;
	f(d21);

	cout << "D22" << endl;
	D22 d22;
	f(d22);

	return 0;
}
