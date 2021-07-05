//using structured bindings to unpack bundled return values.

// Enabling C++17 in visual studio.

#include <iostream>


std::pair<int, int> divide_remainder(int dividend, int divisor)
{
	std::pair<int, int> x;
	x.first = dividend / divisor;
	x.second = dividend % divisor;

	return x;
}

int main()
{
	//structured unpacking.
	auto [fraction, result] = divide_remainder(16, 3);

	std::cout << "Fraction is " << fraction<<std::endl;
	std::cout << "result is " << result<<std::endl;
	return 0;
}