Studio 20 ReadMe.txt

1) Evin Jaff, Lane Bohrer, David Moon

2) It's important to delete the pointer because it's dynamically allocated and won't be deleted at the end of main unless specifically deleted by a destructor. If not deleted it will cause a memory leak and memory leaks make us sad.

4) We tested our implementation by creating a sample setup with the PasswordProxy. We attempted to read and write, which demonstrated to us that the password checker worked and that files were being properly written and accessed by testing length of the vectors.