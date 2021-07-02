/* In Standard C++, we don't specify .h
 iostream is enough.
*/

// single line comment

/* This is a multiple 
line comment */

//iostream is class object for input and output.
#include <iostream>

int main()
{
	using namespace std;

	/** << is insertion object
	* and it inserts the data on to the output stream.
	* you can cascade << operator.
	* endl is a manipulator and it affects the output
	* endl flushed the output buffer.
	**/
	cout << "Hello World" << endl;
	//instead of namespace, you can use the fully qualified name using scope resolution operator ::
	std::cout << "Using fully qualified name - i.e. including namespace";
	return 0;
}

/*
  Build solution in visual studio builds all the projects inside the solution.
  Build project just builds the current project.
  C++ compiler generates multiple compilation error messages for a single error.
*/

/* C++ build steps 
 Pre-processing -> performed by pre-processor.
 any statement starting with # will get replaced with 
 file content.

macros are expanded.

compilation ->
code is checked for correct syntax.
Then it is converted into object code.

Finally, it will generate an obj file.

Linking - 
All the object code is linked with the standard library.
The output of linking is an executable file.
*/