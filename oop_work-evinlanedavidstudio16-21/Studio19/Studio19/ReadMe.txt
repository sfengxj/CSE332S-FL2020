studio 19 answers here

1) Evin Jaff, Lane Bohrer, David Moon

2) To test the new read, we created a new text file, put a vector of chars into it, and read it again.

3) The visitor pattern decouples related operations from being defined inside the object by having the visitor define the functions
within themself. The visitor will call the specific operation on the members of the class, and the object will call accept within itself to access, 
which will then call the visitor and then scope into the specific operation itself.

4) The visitor patterns allows us to add the external functionality of read. Because it's implemented differently for each file type, implementing each
	without adding complexity to the interface. This delegation keeps the code cleaner and interface smaller, while adding overall functionality.

5) A negative consequence of the visitor pattern is that adding new classes gets cumbersome because adding new file types means changing the visitor each time. 
	In situations where new file types are expected to be added, using a visitor pattern will make that addition more difficult and should maybe be avoided.