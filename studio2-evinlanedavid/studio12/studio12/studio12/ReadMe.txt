1) Evin Jaff, Lane Bohrer, David Moon

2) A's constructor was called twice, once for A and once for B because B inherits from A. The same is true for the destructors
A() Construct
A() Construct
B() Construct
Hello World!
~B() Destruct
~A() Destruct
~A() Destruct

3) Output is what we expected (d calls A's method)
A() Construct
A() Construct
B() Construct
a
A$() Method
b
B$() Method
c
A$() Method
d
A$() Method
e
B$() Method
Hello World!
~B() Destruct
~A() Destruct
~A() Destruct

4) Output was the same 
A() Construct
A() Construct
B() Construct
a
A$() Method
b
B$() Method
c
A$() Method
d
B$() Method
e
B$() Method
Hello World!
~B() Destruct
~A() Destruct
~A() Destruct

5) The pointer calls work the same way as the reference calls
f
A$() Method
g
B$() Method
h
B$() Method