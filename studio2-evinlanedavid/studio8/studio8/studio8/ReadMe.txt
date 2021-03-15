1. Evin, David, Lane
2. C++'s default constructor sets values to zero, so when we write a constructor to do it, we get the same output
3. The member variables of a class are private by nature, and structs are public by nature. 
	This shows in the fact that we have to declare getX() and getY() as public functions to 
	be able to access the from a different (source) file.