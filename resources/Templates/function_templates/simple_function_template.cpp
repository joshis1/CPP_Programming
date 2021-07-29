#include <iostream>

template<typename T>

int max(T a, T b)
{
   return a < b;
}

int main(int argc, char **argv)
{
   std::cout<<::max(5,2)<<std::endl;
   std::cout<<::max(2.14, 2.34)<<std::endl;
   std::cout<<::max(static_cast<std::string>("ads"), static_cast<std::string>("yasdsf"))<<std::endl;
   std::cout<<::max(static_cast<double>(2.243) , 23.23424)<<std::endl;
	return 0;
} 
