Lab 5 ReadMe
Names: Evin Jaff, Lane Bohrer, David Moon

Work Breakdown:
	All of this code was written by all of us together on group Zoom calls. LiveShare hosting was rotated to different people during different work sessions.

Design Choices:
	We chose to not allow file names over 20 characters. If given one, we take first 20 characters.
	We did not let examples of file with names such as "file.txt.img" be accepted.

Tests:
	With the code in Lab5.cpp, we tested use of all the commands. 
	We tested touch, cat (with and without append), display, and ls by creating, writing to, and displaying a file and its info.
	We also tested rename by creating a file, writing to it, and then renaming it and displaying it to make sure it was renamed correctly.
	We used the same method to test copy, checking to make sure that it was a deep copy.
	Finally, we removed files and used ls to make sure they had been deleted. Here, we were careful to avoid memory leaks, and made sure that the file was both removed from the file system and the pointer deleted.

	While testing, we ran into was the program crashing when trying to ds or ls -m after a call to cat. This was because we didn't close the file in cat, so making sure the file got closed in each control path fixed it.
	
	While testing, when we tried to cat a txt or img file without any content, it returned an error message. This was resolved through an if statement check in CatCommand.cpp, where we checked to see whether the user gave an adequate input while appending to save and close the file without giving index out of bound issues

	We fixed a lot of type conversion warning with static casts to match types expected in methods called by the Unit Tests.

	When testing the password proxy, we checked the functionality of touching a password protected file, writing and reading it, and what happens with a wrong password. We also checked that a copied password protected file has the same password as the original.
	We ran into an issue of seeing an extra blank command being inputted and a resulting error message, but we solved it by changing our cin extraction to a getline() call. This also allows for passwords with spaces.

	As our extra credit, we added functionality for a grep command. We tested this by creating multiple files with a given phrase,some without, and some with only one word of the phrase. Calling grep only printed the names of those files with the exact phrase included.