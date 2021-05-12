#include "std_lib_facilities.h"

template<typename T> 
struct S {
	S() {}
	S(T x) : val(x) {}

	T& get();
	const T& get() const;

	void set(const T& x);
	T& operator=(const T&);

private:
	T val;
};

template<typename T> T& S<T>::get() { return val; }

template<class T> const T& S<T>::get() const { return val; }

template<typename T> void S<T>::set(const T& x) { val = x; }

template<class T> T& S<T>::operator=(const T& x) {
	val = x;
	return val;
}

template<class T> istream& operator>>(istream& is, S<T>& ss) {
	T v;
	cin >> v;
	if(!is) { return is; }
	ss = v;
	return is;
}

template<class T> void read_val(T& v) { cin >> v; }

int main()
{
	S<int> s_int(10);
	S<char> s_char('a');
	S<double> s_double(3.14);
	S<string> s_string("asd");
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	S<vector<int>> svec(vec);

	cout << "Kiiratas:" << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
	for(int i = 0; i < svec.get().size(); i++) {
		cout << "svec[" << i << "] = " << svec.get()[i] << endl;
	}
	cout << endl;

	// set() használata értékek beállításához
	s_int.set(100);
	s_char.set('b');
	s_double.set(2.54);
	s_string.set("dsa");
	vec[0]=3;
	vec[1]=2;
	vec[2]=1;
	svec.set(vec);

	cout << "Kiiratas set() hasznalata utan:" << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
	for(int i = 0; i < svec.get().size(); i++) {
		cout << "svec[" << i << "] = " << svec.get()[i] << endl;
	}
	cout << endl;

	// = operator használata értékek beállításához
	s_int = 1000;
	s_char = 'c';
	s_double = 420;
	s_string = "das";
	vec[0]=2;
	vec[1]=3;
	vec[2]=1;
	svec = vec;

	cout << "Kiiratas = operator hasznalata utan:" << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
	for(int i = 0; i < svec.get().size(); i++) {
		cout << "svec[" << i << "] = " << svec.get()[i] << endl;
	}
	cout << endl;

	cout << "Felhasznalo altal megadhato ertekek (read_val):" << endl;
	cout << endl;
	cout << "s_int = ";
	read_val(s_int);
	cout << "s_char = ";
	read_val(s_char);
	cout << "s_double = ";
	read_val(s_double);
	cout << "s_string = ";
	read_val(s_string);

	cout << endl;
	cout << "Felhasznalo altal megadott ertekek kiiratasa" << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;

	cout << endl;
	cout << "Felhasznalo altal megadhato ertekek (>>):" << endl;
	cout << "s_int = ";
	cin >> s_int;
	cout << "s_char = ";
	cin >> s_char;
	cout << "s_double = ";
	cin >> s_double;
	cout << "s_string = ";
	cin >> s_string;

	cout << endl;
	cout << "Felhasznalo altal megadott ertekek kiiratasa" << endl;
	cout << "s_int = " << s_int.get() << endl;
	cout << "s_char = " << s_char.get() << endl;
	cout << "s_double = " << s_double.get() << endl;
	cout << "s_string = " << s_string.get() << endl;
}