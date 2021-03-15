Answer the studio 17 questions here.

1) Evin Jaff, Lane Bohrer, David Moon

2) Testing code to verify implementation:
			AbstractFile* abstractfile = new ImageFile("rock");
			cout << "Name: " << abstractfile->getName() << endl;
			cout << "Size: " << abstractfile->getSize() << endl;
			vector<char> v = {'X',' ','X',' ','X',' ','X',' ', 'X', '3'};
			abstractfile->write(v);
			abstractfile->read();
	This correctly prints the name (rock), size (3), and expected output pattern from read(). This tests all the basic functionality that we wrote, especially read and write.

3) 	Biggest benefit of programming an interface: interface provides more flexibility in implementing a class vs concrete class