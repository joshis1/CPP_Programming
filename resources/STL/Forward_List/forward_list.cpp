/** 
 * forward_list is like a Singly Linked list
 *
 */


#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

class myData
{
  private:
	int stateId;
	string stateName;
  public:
         myData(int id, string name): stateId(id), stateName(name)
	 {
             cout<<"CTOR invoked "<<endl;
         }
	 myData(const myData &rhs) {

		 cout<<"Copy CTOR invoked "<<endl;
		 stateId = rhs.stateId;
		 stateName = rhs.stateName;
	}
        pair<int,string> getAttributes()
	{
           pair<int,string> stateIdName;
	   stateIdName.first = stateId;
	   stateIdName.second = stateName;

	   return stateIdName;
	}	
};	 

int main()
{
  forward_list<myData> sll;
  cout<<"create myData"<<endl;
  myData d1 { 5, "Hello"};
  cout<<"push_front my Data onto forward_list"<<endl;
  sll.push_front(d1); 
  cout<<"Check the contents"<<endl; 
  for(auto &elm : sll)
   {
        auto [id, name] = elm.getAttributes();
        cout<<"ID = "<<id<<" State Name "<<name<<endl;
   }
  
   cout<<"Testing---emplace_after"<<endl;
   auto  it = sll.before_begin();

   sll.emplace_after(it, 10, "Test"); 
  
   auto print = [](myData &item) { auto[id, name] = item.getAttributes(); cout<<"id is "<<id<<" state name = "<<name<<endl;  };
  
   cout<<"Check the contents afterwards"<<endl; 
   for_each(sll.begin(), sll.end(), print);


   cout<<": Insert after "<<endl;
   myData temp2 {2, "insert after"};
   sll.insert_after(sll.begin(),temp2);
  
   for_each(sll.begin(), sll.end(), print);

   //cout<<"Erase element"<<endl;
   //cout<<"Before erase size = "<<sll.size()<<" capacity = "<<sll.capacity()<<endl;
   //sll.erase_after(sll.begin());
   //cout<<"New Size is "<<sll.size()<<" capacity = "<<sll.capacity()<<endl; 
   //for_each(sll.begin(), sll.end(), print);

   cout<<"remove if using lambda function"<<endl;
   sll.remove_if([](myData &item) {  auto[id, name] = item.getAttributes(); if (id == 2) return true; return false;} );
   for_each(sll.begin(), sll.end(), print);

  return 0;
}
