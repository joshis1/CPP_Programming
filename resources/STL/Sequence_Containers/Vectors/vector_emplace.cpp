#include <iostream>
#include <vector>

using namespace std;

class MyVectorData
{
 private:
	 int stateId;
	 string stateName;
 public:
	 MyVectorData(int state, string statex): stateId(state), stateName(statex)
         	{ 
		   cout <<"MyVectorData CTOR invoked"<<endl; 
		}
	 void GetAttributes(int &id, string &name)  {
                   id = stateId;
		   name = stateName;
		}
	 MyVectorData(const MyVectorData &rhs)  
	 {
            stateId = rhs.stateId;
	    stateName = rhs.stateName;    
            cout<<"MyVectorData Copy CTOR invoked"<<endl;
 	 }
};


int main()
{
  MyVectorData data(202, "HTTP POST Successful"); 
  int id;
  string state;

  data.GetAttributes(id,state);
  cout<<"Id  = "<<id<<" State = "<<state<<endl;

  vector<MyVectorData> vectorData;
  vectorData.reserve(10);
  cout<<"vectorData -- push_back"<<endl;
  MyVectorData temp(400,"Normal push..back..working..");
  vectorData.push_back(temp);
 
  cout<<"Calling emplace that will not call -- copy constructor --check this out--C++ 11"<<endl;
  vectorData.emplace_back(20,"Emplace..Working");
 
  cout<<"Iterating over items using for range loop"<<endl;

  for(auto &elm : vectorData)
  {
     elm.GetAttributes(id,state);
     cout<<"Id = "<<id<<" State = "<<state<<endl; 
  }
  return 0;
}
