#include <iostream>

unsigned factorial_TR(int x, int y)
{
	if (x==0){
		return y;
	}

	return factorial_TR(x - 1, x*y);
}

unsigned int factorial(int x)
{
	return factorial_TR(x, 1);
}

int main()
{
	std::cout << factorial(3) << std::endl;
	return 0;
}