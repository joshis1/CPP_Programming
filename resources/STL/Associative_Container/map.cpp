#include <iostream>
#include <map>

using namespace std;

class MyData
{
	private:
		int age;
      string name;
   public:
      int getAge()
      {
         return age;
      }
      string& getName()
      {
        return name; 
      }
};

int main(int argc, char **argv)
{
	return 0;
}


