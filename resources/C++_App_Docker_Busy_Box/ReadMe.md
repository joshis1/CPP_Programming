 
This is just a basic hello world sort of docker build program.
The idea here is to put your binary i.e. compile c code in the busy box.
 
 
The catch here is that you need to compile your C++ code statically.
Otherwise, you need to put/install all the dynamic libraries in the docker image.
 
 Compile this statically so that all dependencies are updated.
#g++ --static -o test.out test.cpp
