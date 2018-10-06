# 8queens
Example for the 8 queens problem

# How to build the project
We need to specify additional environment variables in order
to use gcc8.2.

kdir -p build && cd build && cmake -DCMAKE_C_COMPILER=/opt/local/bin/gcc -DCMAKE_CXX_COMPILER=/opt/local/bin/g++ .. && make
