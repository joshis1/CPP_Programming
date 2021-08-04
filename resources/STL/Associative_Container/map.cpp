/* std::map is a sorted associative container that contains 
 * key-value pairs with unique keys. Keys are sorted by using the comparison 
 * function Compare. Search, removal, and insertion operations have logarathmic complexity.
 * Maps are usually implemented as red-black-trees
*/

/** https://en.cppreference.com/w/cpp/container/map **/
/** https://stackoverflow.com/questions/68645539/how-to-use-emplace-in-map-for-custom-class **/

/** If you don't provide move constructor then emplace will call copy constructor, 
 * the other way is called - piecewise_construct, this uses real emplace i.e. in place construction
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyData
{
	private:
		int age;
      string name;
   public:
      int getAge() const
      {
         return age;
      }
      string& getName()
      {
        return name; 
      }
      MyData(int age_val, string name_val): age(age_val), name(name_val) 
      {
         cout<<"Constructor invoked"<<endl;
      }
      bool operator <(const MyData &other) const
      {
         return age < other.age;
      }
      MyData(const MyData& other)
      {
         cout<<"Copy constructor invoked"<<endl;
         age = other.age;
         name = other.name;
      }
      // provide move constructor if you want copy constructor to be avoided for emplace
      MyData(MyData &&other) noexcept:
       age(std::move(other.age)), name(std::move(other.name))
      {
        cout<<"Move constructor invoked"<<endl;
      }
};

int main(int argc, char **argv)
{
   std::map<MyData, vector<string>> studentClasses;
   vector<string> v;
   v.push_back("class 9th");
   MyData d1 {39, "Shreyas"s};
   studentClasses.insert(std::make_pair(d1,v));
   std::map<int, vector<string>> test;
   test.insert(std::make_pair(1,v));
   
   auto const &pair = studentClasses.insert_or_assign(MyData{36, "Neha"s}, std::vector{"class 5th"s}); 
   cout<<( pair.second ? "inserted" : "assigned ")<<endl; 
   cout<<"Read the key getAge value"<<endl;
   cout<<(pair.first)->first.getAge()<<endl;  
   cout<<"Read the value -- first data in vector"<<endl;
   cout<<(pair.first)->second.at(0)<<endl; 
   cout<<"Checking emplace"<<endl;   
   cout<<"Note here is that since you have not provided the move constructor, it will invoke copy constructor"<<endl;
   studentClasses.emplace(MyData{32, "SJ"s}, std::vector{"working"s});
  
   cout<<"Checking emplace using piecewise_construct"<<endl;
   studentClasses.emplace(std::piecewise_construct, std::forward_as_tuple(32, "SJ"s), std::forward_as_tuple(std::vector{"working"s}));

	return 0;
}


