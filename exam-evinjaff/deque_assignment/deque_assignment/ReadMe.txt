Answer any exam questions here
Name: Evin Jaff
WUSTL ID: 473830

Code used to test copy constructor:

	deque <int> d; //Make empty deque

	d.push_back(3); //push a 3

	deque <int> newd(d); //Construct a new deque

	d.push_back(5); //push a 5 onto the original

	//List Both addresses
	cout << &d << endl; 
	cout << &newd << endl;

	//Call the destructor on d
	d.~deque();

	cout << newd[0] << endl; //Will output 3 if deep
	
	cout << newd[1] << endl; //This will throw an error if it is a deep copy

The addresses were both separate, which means that it was a deep copy, since a new object was created. This is further verified by the ability to call
elements on the new deque after d is destructed.


Notes about development:

Unit Tests were extremely buggy:
The Unit Tests were doing this weird thing where they wouldn't refresh. So whenever I thought that my unit tests should pass, I had to call debug on the unit tests and it would then finally recognize that the code passes.
Also, upon launching Unit Tests sometimes refuse to run unless you use Debug to run the tests without breakpoints. I tried multiple RDP configurations, using Urbauer Laptops and the VMWare Workspace but it didn't seem to fix anything. The tester seems to throw internal exceptions when it happens

I had to test in chunks of tests at a time, and using debug, I was able to determine that most of the tests work. I have attached a photo for reference. Try to run unit tests on just the ones in green checkmarks. They will eventually pass if you keep hitting "Continue." I think the "\" and "/" difference in the filesystem causes VS to throw exceptions but I'm not sure.
Additionally, I ran the tests on the command line and they seemed to also work withou errors throwing, so it seems like it's more on VS having buggy unit testing.

Heap Corruption Error:
I ran into an issue in my destructor where if I called delete on my array similar to how we did in class, it would return a heap corruption error. This only seemed to throw in Visual Studio; when executing tests on the command line, it seemed to perform as normal.


	