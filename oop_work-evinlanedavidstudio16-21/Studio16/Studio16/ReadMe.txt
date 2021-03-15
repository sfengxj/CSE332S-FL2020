Answer studio 16 questions here
1. Evin Jaff, Lane Bohrer, David Moon

2.
	a. To create an interface in C++:
		first make a class with pure virtual methods.
		the interface contains member variables
		use the interface by creating another class that overrides the virtual methods.
3.
	a. interface interitance, as TextFile inherits publicly from AbstractFile
	b. private as we will not be inheriting them anywhere

4. Created a vector of characters, and appended it to the file, and we then read the appended characters. We did realize through this test
	that we had to print everything out on one line and line break after that.

5.  In order to allow any abstract file type, we change the object we create into a pointer to the Abstract class, so that it can be interacted with as an arbitrary file type