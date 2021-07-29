#include <iostream>

using namespace std;


class MyInt {

private:
	int *data;

public:
	MyInt(int size) 
	{
           data = new int(size);
	   cout<<"Constructor invoked"<<endl;
	}

       ~MyInt()
	{
	   delete data;
	   data = nullptr;
	   cout<<"Destructor invoked"<<endl;
	 }

       int& operator *()
	{
	   cout<<"operator * overloaded invoked"<<endl;
	   return *(this->data);
	} 
};


int main()
{
 {
   MyInt p(10);
   *p = 100;
 }
   return 0;
}


