// Standard template library - Array 
// Introduced in C++11.

// Array STL.

// Syntax: std::array<T,N> array;

// T is type and N is the size of the array.
// Array size is needed at the compile time.

// 1. std::array is a container that encapsulates fixed size arrays.
// 2. arraysize is needed at compile time.
// 3. Assign by value is called by value.  - 
// In C, the array is passed as pointer. However, in this STL,
// the array is passed as value.
// In standard C, you need to pass the size when you are passing the 
// pointer since you cannot get the size of array using pointer.
// 4. Access Elements
// a. at()
// b. [] // same like at() but preference is at() since ArrayOutofBounds Exception can be catch here.
// c . front()
// d .back()
// e. data() // gives access to the underlaying array.- you will get the pointer here.

#include <iostream>
#include <array>

using namespace std;

int main() {
	// Declare 
	std::array<int, 5> myarray;

	myarray.fill(10); // initialize each element with 10.

	//Initialization 
	std::array<int, 5> myarray1 = { 1,2,3,4,5 }; // Initializer list
	
	// uniform initialization
	
	std::array<int, 5> myarray2{ 1,2,3,4,5 };

	//give me third number
	std::cout << "Give me third element ";
	std::cout << myarray1.at(2) << std::endl;

	//give me the first element.
	std::cout << "Give me the first element ";
	std::cout << myarray1.front()<<std::endl;

	// give me the last element.
	std::cout << "Give me the last element ";
	std::cout << myarray1.back()<<std::endl;

	// Assign using initializer list
	std::array<int, 5> myarrayX;
	myarrayX = { 1, 2, 3, 4, 5 };

	return 0;
}
