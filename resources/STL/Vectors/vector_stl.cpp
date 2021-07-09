// std::vector

/*
* std::vector is a sequence container and also known as Dynamic array or Array List.
* Its size can grow and shrink dynamically, and no need to provide size at compile time.
* std::vector<T> vec;
* Sequence containers - the values will be stored sequentially i.e. one after another
*  Element Access
* at(), [], front(), back(), data()
* data() -- returns the pointer to the vector.
* Modifiers 
* insert(), replace(), push_back(), replace_back(), pop_back(), resize(), swap(), erase(), clear()
**
** vector capacity and size is very important
**  capacity grows basically doubles everytime we push_back() in it.
**  size () tells how many items are there.
*/

/** How to change the vector capacity **
/** We can change the vector capacity using - reserve()
**/


#include <iostream>
#include <vector>
#include <ctime>

int main()
{
	// Declarations
   std::vector<int> arr1;
   std::vector<int> arr2 (5,20); 
   std::vector<int> arr3 = {1,2,3,4,5}; // initialiser list
   std::vector<int> arr4 {1,2,3,4,5}; // uniform initialisation

   //Accessing elements
   arr2[3] = 10; 
   arr2.at(3) = 10;
   
   arr1.reserve(30); //reserver 30 so that capacity grows to 30 and we don't need to resize and copy elements
   
   const std::clock_t begin_time = clock();
   
   for(int i = 0; i < 32; i++)
   {
		arr1.push_back(i);
      std::cout<<"Array Size = "<<arr1.size()<<" Array Capacity = " <<arr1.capacity()<<std::endl;
   }
   std::cout<<float( clock() - begin_time)<<std::endl;  
 
   return 0;
}

