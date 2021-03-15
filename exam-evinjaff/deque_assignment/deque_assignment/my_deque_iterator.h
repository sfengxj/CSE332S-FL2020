#pragma once
// declare my_deque_iterator here
class my_deque;

class my_deque_iterator {


	int* curr;
	my_deque* d;

public:

	my_deque_iterator(int* curr, my_deque* my_deque);

	int* get_mem();

	//Initialize “curr”and “deque” with the parameters accordingly.Determine which state the iterator is inand update if needed.


	my_deque_iterator operator + (int n);
	//Createand return a new my_deque_iterator that is advanced by n integers.If n is negative, an invalid my_deque_iterator should be returned.


	my_deque_iterator& operator += (int n);
	//Update the my_deque_iterator this function is called on to be advanced by n integers in the deque.Once again, if n is negative the iterator should be placed in an invalid state.After updating, return the my_deque_iterator this function is called on by reference.

	int& operator *();
	//Return a reference to the integer the my_deque_iterator is currently aliasing.If the iterator is not valid(it is invalid or past the end) an exception of type std::exception should be thrown.

	bool operator <(const my_deque_iterator comp) const;
	//If either of the my_deque_iterators this function acts on is in an invalid state or if they are not iterating over the same deque, throw an exception of type std::exception.Otherwise, return true if “this” is aliasing an integer that comes before the integer aliased by “compare_against” in the deque and false otherwise.A past the end iterator is larger than any valid iterator iterating over the same deque.

	bool operator ==(const my_deque_iterator comp) const;
	
	


	
	
};