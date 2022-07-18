#include <iostream>
#include <vector>
#include <set>

using namespace std;


class MyData
{
	private:
		int x;
	public:
		int getX()
		{
		   return x;
		}
		MyData(int val): x(val) { cout<<"Constructor invoked--"<<endl; }
		MyData(const MyData &rhs)  { cout<<"Copy Constructor Invoked"<<endl; x = rhs.x; } 
               // bool operator<(const MyData &lhs) const  { return lhs.x < x; }
};


int main(int argc, char **argv)
{
  
  //MyData d1(5);

  cout<<"Calling vector push back"<<endl;
  vector<MyData> vx;
  vx.reserve(10);
  vx.push_back(1);
  cout<<"Calling vector emplace_back"<<endl;
  vx.emplace_back(15);

  //set<MyData> mySet;
  //cout<<"mySet emplace invoking"<<endl;
  //mySet.emplace(20);
  return 0;
}
