#include <iostream>

using namespace std;

template <typename U>


class Addable
{
  	U x;
 public:
	Addable(U val): x{val} { cout<<"Constructor called" <<endl; }
        template <typename T>
	U add(T y);
};

U Addable::add(T y)
{
   x += y;
   return x;
}

int main()
{
 Addable<int> A {10}; 
  
  int x = A.add(static_cast<int>(10));
  cout<<x;
  return 0;
}
