#include <iostream>

using namespace std;

//0,1,1, 2, 3, 4, 5, 9 

// 0,1,2,3,4,5,6,7,8

// 2 --> fab(2-1) + fab(2-2);
//

unsigned long int fab(unsigned long int n)
{
  if(n == 0) 
  {
  	return 0;
  }
  if(n == 1)
  {
    return 1;
  }

  return (fab(n-1) + fab(n-2));

}


int main(int argc, char **argv)
{ 
   for(int i = 0; i <= 50; i++)
    {
      cout<<"Fab of "<<i<<" is "<<fab(i)<<endl;
   }
   cout<<"Fab of 0 is = ";
   cout<<fab(0)<<endl;
   cout<<"Fab of 1 is = ";
   cout<<fab(1)<<endl;
   cout<<"Fab of 2 is = ";
   cout<<fab(2)<<endl;
   cout<<"Fab of 3 is = ";
   cout<<fab(3)<<endl;
   cout<<"Fab of 14 is = ";
   cout<<fab(14)<<endl;
   //cout<<fab(100)<<endl;
   cout<<"Fab of 40th "<<endl;
   cout<<fab(40)<<endl;
   return 0;	
}
