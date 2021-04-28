#include <string>
#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

struct Person {
	Person(){}
	Person(string fn, string ln, int a);
	string get_first_name() const { return first_name; }
	string get_last_name() const { return last_name; }
	int get_age() const { return age; }

private:
	string first_name;
	string last_name;
	int age;
};

Person::Person(string fn, string ln, int a) : first_name{fn}, last_name{ln}, age{a}
{
	if (a < 0 || a > 150) { throw runtime_error("Bad age range!"); }

	for(int i = 0; i < fn.size(); i++) {
		if(!isalpha(fn[i])) { throw runtime_error("Bad char in name!"); }
	}

	for(int i = 0; i < ln.size(); i++) {
		if(!isalpha(ln[i])) { throw runtime_error("Bad char in name!"); }
	}
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.get_first_name() << ' ' << p.get_last_name() << ' ' << p.get_age();
}

istream& operator>>(istream& is, Person& p)
{
	string i_fn = "";
	string i_ln = "";
	int i_a = 0;

	cout << "Enter your first name, last name and age!" << endl;
	is >> i_fn;
	if(i_fn != "quit") { 
		is >> i_ln;
		is >> i_a;
	}
	
	if(!is) { throw runtime_error("Unable to read into Person!"); }

	p=Person(i_fn, i_ln, i_a);
	return is;
}

vector<Person> vector_persons;
bool terminated = false;

int main()
{
	Person p1 {"Goofy", "", 63};
	cout << p1 << endl;

	Person p2;
	cin >> p2;
	cout << p2 << endl;

	cout << "Enter some data of persons" << endl;

	for(Person p; cin >> p; ) {
		if(p.get_first_name() == "quit") { 
			terminated = true;
			break; 
		}
		else { 
			vector_persons.push_back(p); 
		}
	}
	cout << endl;
	for (int i = 0; i < vector_persons.size(); i++) {
		cout << vector_persons[i] << endl;
	}
	if(terminated) { cout << "Successfully terminated..." << endl; }

	return 0;
}