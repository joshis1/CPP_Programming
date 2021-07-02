/*
* 
############################################
 Primitive Types -- Basically Types.
############################################

 1) Arithmetic and void 

 Arithmetic -> integral and floating points.

 Integral types -> bool, char, wchar_t, char16_t, char32_t, short, int, long

 floating point -> float, double.

 void is a special type used with pointers and functions.

 ################################################################
 Modifiers --> something that modifies the meaning of type.
 ################################################################

 modifier examples -> signed, unsigned, short, long
 not all type can be changed or modified.
 signed, unsigned modifiers cannot be added to floating points.

 ################################################################
 Qualifiers --> All types can be qualified with qualifiers.
 ################################################################
 
 Qualifiers can be added to any data type - example - 
 const, volatile, static. 

 >> All types occupy memory and can hold a range of values.

 >> Memory requirement may change with the platform.

 Datatype size ->
 bool, char - is 1 byte only.

 wchar_t is 2 bytes

 range of fundamental types

 <climits> -> check this file
 INT_MIN, INT_MAX

 <cfloat> -> check this file
 FLT_MIN, FLT_MAX

*/

#include <iostream>

int main()
{
  signed int i = 0;   //signed is a modifier here, it is modifying type int
  unsigned int k = 0; //unsigned is a modifier here, it is modifying type int.

  /** Honestly this is all illegal to add such modifiers to bool **/
  //unsigned bool b = false; // illegal combination - modifier to bool.
  //signed bool bt = true; //illegal combination - modifier to bool.
  // long bool x = true; --> this will throw a compilation error.
  // short bool x = true; --> this will throw a compilation error.
  /* bool modifers end **/

  /* You cannot add signed, unsigned modifiers to floating point types */
  // unsigned float fx = 2.14f; -- don't add modifiers to floating point types.


  /* Variable declaration - type followed by a variable name
     int a, b, c; --> multiple variable with the same type.
     better to initialize variable during declaration to avoid bugs.
     some compilers won't allow to read un-initialized variable.
     variable is also called identifier.
  */

  /* scalar types vs. vector types
   int a; char ch; bool flag; float fx; double dx; are scalar types

   vector types - Arrays are vector types.

   C++ 11 -- allows uniform initialization for both scalar and vector types.
  
  */

  // C++ 98 way of initializing primitive types

  // scalar types initialization
  int old_i = 1;

  // true, false are keywords in C++.
  bool old_flag = true; // can be true, false or 0.
  bool old_flag_tra = 0; // will become false -- bad way of doing though.
  std::cout << "After assigning zero to bool = " << old_flag_tra << std::endl; //0 -- false
  old_flag_tra = -1;
  std::cout << "After assigning -1 to bool = " << old_flag_tra << std::endl; // 1 --true

  float fx = 1.244f; //floating point needs a literal f in the end.
  std::cout<<"Print the floating point value = " << fx << std::endl; //1.244

  double dx = 24.2342;
  std::cout << "Print the double type value = " << dx << std::endl; //24.2342

  //All arrays are vector types in C++
  int arr[5]; //un-initialized array.
  int arx[5] = { 1,2,3,4,5 };

  /* C++ 11 has uniform initialization 
  for scalar and vector types -- see below.
  */

  int newx  { 1 };
  int newarray[5]{ 1,2,3,4,5 };


  return 0;
}