#include <iostream>
#include <list>


using namespace std;

/** list is a doubly linked list in short **/


class MyData
{
  private:
	  int data;
  public:
	  int getData() const
          {
	    return data;
	  }
	  MyData(int val): data(val) { cout<<"Constructor invoked"<<endl; }
	  MyData (const MyData &other) 
          {
	     cout<<"Copy constructor invoked"<<endl;
	     data = other.data;
	  }
	  MyData& operator =(const MyData &other)
	  {
	      cout<<"Assignment operator invoked"<<endl;
	      data = other.data;
	      return *this;
	  }
	  friend ostream& operator<<(ostream &os, const MyData &d)
          {
	       cout<<"<< operator overloaded"<<endl;
	       os<<d.data;
	       return os;
	  }
};

bool cmp(MyData &d1, MyData &d2)
{
  return d1.getData() < d2.getData();
}

bool cmp1(MyData &d1, MyData &d2)
{

  return d1.getData() == d2.getData() ;
}
void print_values(list<MyData> &data1)
{
  for(auto &elm : data1)
  {
     cout<<elm.getData()<<endl;
  }
}

int main()
{
  list<MyData> data1;
  MyData d1 {16};
  MyData d2(7);
  list<MyData> data2{12,21}; //emplace constructor
  //cout<<"Assignment operator"<<endl;
  d1 = d2;
  
  data1 = data2;


  print_values(data1);

  cout<<"Checking insert at the beginning of the list"<<endl;
  list<MyData>::iterator it = data1.begin();

  data1.insert(it, {52}); 
 
  cout<<"Traversing each element to show the element after inserting element in the beginning"<<endl; 
  print_values(data1);

  cout<<"Checking push_back just like vector"<<endl;

  data1.push_back(d2);
  data1.push_back({32423});

  print_values(data1);

  cout<<"Checking ..push_front for list"<<endl; 
  data1.push_front({1000});
  data1.push_front({1002});

  print_values(data1);
  
  cout<<"Checking pop_back for list"<<endl;
  data1.pop_back(); 
  print_values(data1);
  
  cout<<"Checking overloaded insertion operator"<<endl;
  cout<<d1<<endl;
 
  cout<<"Checking pop_front for list"<<endl;
  data1.pop_front();
  print_values(data1);
  
  cout<<"Checking is list empty"<<endl;
  cout<<data1.empty()<<endl;

  cout<<"Number of elements in list = "<<data1.size()<<endl;
  
  cout<<"Front d1 value print using .front() "<<endl;
  //auto dx = data1.front();
  //cout<<dx.getData()<<endl;

  cout<<data1.front().getData()<<endl;

  cout<<"back list value print using .back() "<<endl;
  cout<<data1.back().getData()<<endl;

  cout<<"Print each value of the data  list"<<endl;
  print_values(data1);

  cout<<"Print each of the data list data2"<<endl;
  print_values(data2);

  cout<<"Swap list with another list"<<endl;
   
  data2.swap(data1);

  cout<<"Data 2 --values are "<<endl;
  print_values(data2);

  cout<<"Data 1.. values are "<<endl;
  print_values(data1);
  
  cout<<"Reverse Data2 items"<<endl;
  data2.reverse();

  cout<<"Data2 items are now "<<endl;
  print_values(data2);

  cout<<"Data2 items checking sort "<<endl;
  data2.sort(cmp);
  print_values(data2);
  
  
  //splice
  cout<<"Checking splice() "<<endl;

  //splice() transfers the element from one list to another
  //Data1 is 12, 21
  //Data2 is 7,12,21,52,1000
  cout<<"splice so that Data1 is 12,21,52,1000,21"<<endl;
  //you can increment the iterator using advance method.
  // constexpr void advance( InputIt& it, Distance n );
  it = data1.begin();
  advance(it,1); // now it points to 21 i.e. second element.
  list<MyData>::iterator it2;
  it2 = data2.begin();
  advance(it2,2); // now it points to 3rd element
  data1.splice(it, data2,it2,data2.end()); //splice transfer range.
  cout<<"Check data1 after splicing"<<endl;
  print_values(data1);

  cout<<"Check data2 after splicing--note that after splicing the data2 items are changed--i.e. transferred out"<<endl;
  print_values(data2); //7, 12

  // you can also use next to increment the iterator. 

  //it = data1.begin();
  // it++;
  // it++; //points to 3rd element i.e. 52
  cout<<"splice data2 so that 7,<52>, and 12 comes"<<endl; //splice just one element from one list to another
  //it2 = data2.begin();
  //it2++;
  data2.splice(next(data2.begin(),1), data1,next(data1.begin(),2));
  print_values(data2); 

  cout<<"splice data2 at begin ..with list of data1"<<endl; //splice entire list data1 at the beginning.
  data2.splice(data2.begin(), data1);
  print_values(data2);

  cout<<"Checking..merge..for list"<<endl;
  cout<<"First the two list needs to be merged"<<endl;
  data1.push_front({100});
  data1.push_back({23});
  data1.push_back({2});
  data1.push_back({100});
  data1.sort(cmp);
  data2.sort(cmp);
  
  cout<<"Data1 list after sorting"<<endl;
  print_values(data1);
  cout<<"Data2 list after sorting"<<endl;
  print_values(data2); 

  data1.merge(data2,cmp);
  cout<<"Checking data1 after merge with data2"<<endl;
  print_values(data1); 

  cout<<"Checking data2 --passed for merging"<<endl;
  print_values(data2); //note that after merging the data2 is empty

  cout<<"Checking unique values now "<<endl;
  data1.unique(cmp1); //cmp1 is different for sorting - for unique cmp1 is checking == and for sorting it is checking < 
  print_values(data1); 
  return 0;

}

