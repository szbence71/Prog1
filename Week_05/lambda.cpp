#include <iostream>

void printhello(){
	std::cout<< "Hello C++ lambda" << std::endl;
}

/*

[] semmit nem kap el
[&] minden capture referenciával lesz
[=] minden capture érték szerint lesz
[&A, =B] referencia szerinti B érték szerinti lesz
[=, &A] A referencia szerinti lesz, minden más pedig érték szerinti
[*this]

*/

int main()
{
	[](){
		std::cout<< "Hello C++ lambda" << std::endl;
	}
	();
	printhello();

	[](){
		std::cout<< "Hello c++ lambda2" << std::endl;
	}
	();

	auto sum = [](double A, double B) {return A+B;};

	auto sum2 = [](double A, double B) -> double {return A+B;};

	std::cout << sum(3.25, 5.65) << std::endl;
	std::cout << sum2(3.25, 5.65) << std::endl;

	double pi = 3.1416;

	auto func = [pi]() {
		std::cout << "The value of pi is " << pi << std::endl;
	};

	auto func2 = [](double pi) {
		std::cout << "The value of pi is " << pi << std::endl;
	};

	func();
	func2(pi);
	
	return 0;
}