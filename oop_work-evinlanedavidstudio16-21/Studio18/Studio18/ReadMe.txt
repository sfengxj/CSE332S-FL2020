studio 18 answers here

1) Evin Jaff, Lane Bohrer, David Moon

2) Why is a factory system better than concrete file classes that have to be modified?
	Adding a new file type with the current setup means that all new functions would have to be written within and known about by the concrete file system. 
	A factory method would allow for adding new file types without this dependency of needing to alter the file system itself. 
	This change will allow new file types to be added without changing the code for the file system.

3) Advantages/disadvantages of abstract factory pattern:
	Advantages include that when a new file type is added, the file system code does not need to be modified to accommodate it. It also abstracts away the underlying implementation of how files are created from the client code.
	Disadvantages include that separating the code out like this makes it less intuitive and easy to read. Also, if the client code needs a different specific implementation, it has no ability to alter how files are created.
	Overall, this sacrifice of readability for flexibility is widely agreed to be worth it.

4) We wrote code that tested creating, opening, writing, and reading, and outputs were as expected. See main() for exact code. We created a filesystem and filefactory, and then created files using the file factory. We then tested adding them to the filesystem and reading them to ensure that our implementation worked.

5) Now that createFile has been abstracted completely to the factory method, the file system has no dependency on specific file type. All of its methods work with a generic pointer to an abstract file.