#include <iostream>
#include "std_lib_facilities.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

using namespace std;

template<typename C>
void print(const C& c)
{
	for(auto& a:c)
		cout << a << ' ';
	cout << endl;
	cout << endl;
}

template<typename T>
void incr(T& t, int n=1)
{
	for(auto& a:t)
		a+=n;
}

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 p = f1; p != e1; p++)
		*f2++ = *p;

	return f2;
}

int main()
{
	const int ten = 10;
	int arr[ten];

	for(int i = 0; i < ten; i++) {
		arr[i] = i;
	}

	array<int, ten> a;
	copy2(arr, arr+ ten, a.begin());
	cout << "array: " << endl;
	print(a);

	vector<int> v(ten);
	copy2(arr, arr+ ten, v.begin());
	cout << "vector: " << endl;
	print(v);

	list<int> l(ten);
	copy2(arr, arr+ ten, l.begin());
	cout << "list: " << endl;
	print(l);

	array<int, ten> a2=a;
	cout << "array_copy: " << endl;
	print(a2);

	vector<int> v2=v;
	cout << "vector_copy: " << endl;
	print(v2);

	list<int> l2=l;
	cout << "list_copy : " << endl;
	print(l2);

	incr(a2, 2);
	cout << "array_incr: " << endl;
	print(a2);

	incr(v2, 3);
	cout << "vector_incr: " << endl;
	print(v2);

	incr(l2, 5);
	cout << "list_incr: " << endl;
	print(l2);

	copy2(a2.begin(), a2.end(), v2.begin());
	copy2(l2.begin(), l2.end(), a2.begin());

	cout << "array vectorba: " << endl;
	print(v2);
	cout << "list arraybe: " << endl;
	print(a2);

	vector<int>::iterator serc;
	serc=find(v2.begin(), v2.end(), 3);
	if(serc != v2.end())
		cout << "A " << distance(v2.begin(), serc) << ". helyen van" << endl;
	else
		cout << "Nem talalhato a keresett elem!";

	list<int>::iterator serc2;
	serc2=find(l2.begin(), l2.end(), 27);
	if(serc2 != l2.end())
		cout << "A " << distance(l2.begin(), serc2) << ". helyen van" << endl;
	else
		cout << "Nem talalhato a keresett elem!" << endl;
}