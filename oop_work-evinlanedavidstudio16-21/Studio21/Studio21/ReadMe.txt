Studio 21 ReadMe.txt 

1) Evin Jaff, Lane Bohrer, David Moon

2) Declaring a virtual destructor in the base class ensures that the derived class destructors are called. In this case, the default destructor is sufficient.

3) Yes. Because the CommandPrompt allows the File System and File Factory to be set (and uses Abstract base classes) so it can easily accomodate different file systems that derive from the base class.

4) We tested our code by setting up a filesystem and filefactory, and then created a Command Prompt and set the created filesystems and file factories to the command prompt. Then, we created a file that points
to the file stored in the filesystem that will be created via the touch command. The file will then accept the visitor and then print its metadata to ensure that the file was created and that there is metadata.