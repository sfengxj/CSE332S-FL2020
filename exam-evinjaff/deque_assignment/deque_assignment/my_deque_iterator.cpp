// define my_deque_iterator here
#include <stdexcept>
#include "my_deque_iterator.h"
#include "my_deque.h"

my_deque_iterator::my_deque_iterator(int* curr, my_deque* my_deque) : curr(curr), d(my_deque) {

	if (curr == nullptr) {
		this->curr = nullptr;

	
	}

	if ( curr > d->get_rIndex() + d->get_mem() || curr < (d->get_mem() + d->get_lIndex())) {
		this->curr = nullptr;
	}
	return;

}

my_deque_iterator my_deque_iterator::operator+(int n) {
	if (!(n < 0)) {

		
		my_deque_iterator * point = new my_deque_iterator(curr + n, d);

		return *point;

		

	} else{
		return *(new my_deque_iterator((int*)nullptr, d));
	}

}

my_deque_iterator& my_deque_iterator::operator+=(int n) {

	if (n < 0){

		curr = nullptr;
		return *this;
	}

	this->curr += n;
	if (*curr > d->get_rIndex()) {
		curr = nullptr;
	}

	/*
	if (!(n <= 0) || !( *curr > this->d->get_rIndex()  ) ){

		//Construct new one
		//my_deque_iterator* point = new my_deque_iterator(this->curr + n, d);


		this->curr = this->curr + n;



		return *this;



	}
	else {
		return *(new my_deque_iterator((int*)nullptr, d));
	}
	*/


}

int& my_deque_iterator::operator *() {


	if (d == nullptr) {
		throw std::exception("not tracking # right now");
	}

	if (curr == nullptr) {
		throw std::exception("not tracking # right now");
	}

	if (curr >= d->get_mem() + d->get_rIndex() ) {
		throw std::exception("not tracking # right now");
	}

	else {
		return (*curr);
	}
}

bool my_deque_iterator::operator <(const my_deque_iterator comp) const {

	if (comp.curr == nullptr) {
		throw std::exception("can't compare");
	}

	/*
	if (curr == nullptr) {
		throw std::exception("can't compare");
	}
	*/
	/*
	if (curr > d->get_rIndex() + d->get_mem() || curr < (d->get_mem() + d->get_lIndex())) {
		throw std::exception("can't compare");
	}
	*/
	/*
	if (comp.curr > comp.d->get_rIndex() + comp.d->get_mem() || comp.curr <(comp.d->get_mem() + comp.d->get_lIndex())) {
		throw std::exception("can't compare");
	}
	*/



	if (this->d == comp.d) {
		bool truth = this->curr < comp.curr;

		int garbo = 0;

		return truth;
	}
	else {
		throw std::exception("can't compare");
	}

}

bool my_deque_iterator::operator ==(const my_deque_iterator comp) const {
	
	if (this->d == comp.d && this->curr == comp.curr) {
		return true;
	}
	else {
		return false;
	}
}

int* my_deque_iterator::get_mem()
{
	return curr;
}






