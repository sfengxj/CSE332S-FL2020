
#include "my_deque.h"
#include "my_deque_iterator.h"
#include <iostream>
#include <string>

using namespace std;

//Base constructor
my_deque::my_deque(int inital_size) : origsize( inital_size ), size(inital_size), lindex(inital_size / half - 1), rindex(size / half), used(dequeconstants::no_stuff) {
    //Negative index
    if (inital_size < dequeconstants::no_stuff) {
        throw errors::negative_sizes;
    }
    else {
        this->queue = new int[inital_size];
    }

}


//copy constructor
my_deque::my_deque(const my_deque& d) : origsize(d.origsize), lindex(d.lindex), rindex(d.rindex), used(d.used), size(d.size) {
    if (d.size > 0) {
        //Has stuff 

        this->queue = new int[size];

        // copy elements
        for (size_t i = 0;i < d.size; ++i) {
            this->queue[i] = d.queue[i];

        }
    }
    else {
        //is empty


        this->queue = nullptr;
    }

}

//Destructor




int my_deque::get_size() {
    return size;
}

int my_deque::get_lIndex() {
    return this->lindex;
}

int my_deque::get_used() {
    return used;
}
//Get Right Index
int my_deque::get_rIndex() {
    return rindex;
}
//Get address of array
int* my_deque::get_mem() {
    return queue;
}

/*Operations*/
//Push value onto back
void my_deque::push_back(int v) {

    int oldsize = this->get_size();
   
    //Hit the end of the right and its lopsided
    cout << "rindex: " << rindex << endl;
    if (rindex >= size) {
        cout << "NEED TO FIX ARRAY" << endl;
        //double the array
        if (used >= size / 2) {
            std::cout << "Big" << std::endl;
            //Transfer array
            int* cache = new int[size*2];
            this->size = this->size * 2;
            //reallocate array

            int oldlindex = this->lindex;

            this->lindex = (oldsize - (this->used / 2) - 2);

            this->rindex = (oldsize + (this->used / 2)) - 1;

            for (unsigned int i = 0; i < size; i++) {
                //std::cout << ((size / (half)) + i) << std::endl;
                cache[(this->lindex + 1 + i)] = queue[oldlindex + 1 + i];
            }
            std::cout << "New size: " << size * x2 << std::endl;

            std::cout << "used: " << this->used << std::endl;

            std::cout << (oldsize + this->used - 2) << std::endl;

         

            this->queue = nullptr;

            this->queue = cache;

            std::cout << lindex << std::endl;
        }
        //Rebalance
        
        else {
            std::cout << "Rebalance" << std::endl;

           
            //rebalance array
            //if (this->used % 2 != 0) {
                int newlindex = (oldsize / 2 - this->used/2 - 2);
            //}
           
            

            for (unsigned int i = 0; i < size; i++) {
                //std::cout << ((size / (half)) + i) << std::endl;
                this->queue[newlindex + i + 1] = queue[lindex + 1 + i];

            }

           

            

            this->rindex = newlindex + this->used + 1;

            this->lindex =newlindex;

            cout << "size/2 " << (this->size / 2) << endl;

            std::cout << "rindex: " << oldsize / 2 + this->used / 2 << std::endl;

           
        }
        

    }

    //std::cout << "rindex: " << rindex << std::endl;

    std::cout << "used: " << this->used << std::endl;
    queue[rindex] = v;
    this->used++;
    this->rindex = rindex + 1;
    
    return;
}


//Push value onto front
void my_deque::push_front(int v) {
    //std::cout << "rindex: " << rindex << std::endl;
    int oldsize = this->get_size();
    //Hit the end and its lopsided
    if (lindex < 0) {
        int junk = 0;
        //double the arrays
 

        if (used >= size / 2) {
            std::cout << "Big" << std::endl;
            //Transfer array
            int* cache = new int[size * 2];
            this->size = this->size * 2;
            //reallocate array
            int rindex = 0;

            if (this->used % 63 == this->used / 63 - 1) {

                for (unsigned int i = 0; i <= used; i++) {
                    //std::cout << ((size / (half)) + i) << std::endl;
                    cout << lindex + 1 + i << " => " << (oldsize - (this->used / 2) - 1) + 1 + i << endl;
                    cache[(oldsize - (this->used / 2) - 1) + 1 + i] = queue[lindex + 1 + i];
                }

                this->lindex = (oldsize - (this->used / 2) - 1);
            }
            else {
                 for (unsigned int i = 0; i <= used; i++) {
                    //std::cout << ((size / (half)) + i) << std::endl;
                    cout << lindex + 1 + i << " => " << (oldsize - (this->used / 2) - 1) + 1 + i << endl;
                    cache[(oldsize - (this->used / 2) - 1) + 1 + i] = queue[lindex + 1 + i];
                }

                this->lindex = (oldsize - (this->used / 2) - 1);
            }

            //cout << "NEW LINDEX: " << this->lindex << endl;

            this->rindex = (oldsize + (this->used / 2));

            this->queue = nullptr;

            this->queue = cache;

        }
       


        //Rebalance
        else {

            std::cout << "Rebalance" << std::endl;
            //rebalance array
            //if (this->used % 2 != 0) {
            

            int newlindex = this->size/2 - this->used/2;

            int newrindex = this->size / 2 + this->used / 2;
            //}
            
            int k = 0;
            for (unsigned int i = this->lindex; i  <= rindex; i++) {
                //std::cout << ((size / (half)) + i) << std::endl;
                this->queue[newlindex + k] = queue[i];
                cout << "for" << endl;

                k++;

            }

            if (rindex != 0) {
                ++newrindex;
            }

            this->lindex = (oldsize / 2 - this->used / 2) - 1;

            this->rindex = newrindex;
    
            

            cout << "size/2 " << (this->size / 2) << endl;

            std::cout << "rindex: " << oldsize / 2 + this->used / 2 << std::endl;


        }


    }

    

    std::cout << "Push: " << std::endl;
    queue[lindex] = v;
    this->used++;
    lindex = lindex - 1;
  
    

   
}
//Pop back element
int my_deque::pop_back() {
    if (this->size <1 || this->used < 1) {
        char* message = "Invalid Pop";
        throw std::out_of_range(message);
    }
    
    int oldlindex = this->lindex;
    int oldrindex = this->rindex;

    if (this->used <= this->size / 8 && this->size >= 2*this->origsize ) {// && this->size > 2*this->origsize) {
        std::cout << "Reize that " << std::endl;

        if (this->used <= this->size / 8 && this->size >= 2 * this->origsize) {
            std::cout << "no backwards" << endl;
        }

        //Resize for loop
        int* cache = new int[size/2];

        for (int i = 0; i < size; i++) {
            cache[size / 4 - this->used / 2 - 2 + i + 2] = this->queue[oldlindex + i + 1];
        }

        this->queue = cache;

        this->lindex = size / 4 - this->used/2 - 1;
        this->rindex = this->lindex + this->used + 1;
        this->size /= 2;


    }


    int r = queue[rindex-1];
    queue[rindex-1] = 0;
    rindex = rindex - 1;
    this->used--;
    return r;
}
//Pop front element
int my_deque::pop_front() {
    if (this->size < 1 || this->used < 1) {
        char* message = "Invalid Pop";
        throw std::out_of_range(message);
    }

    int oldlindex = this->lindex;
    int oldrindex = this->rindex;

    if (this->used <= this->size / 8 && this->size >= 2 * this->origsize) {// && this->size > 2*this->origsize) {
        //std::cout << "Reize that " << std::endl;

        if (this->used <= this->size / 8 && this->size >= 2 * this->origsize) {
            std::cout << "no backwards" << endl;
        }

        //Resize for loop
        int* cache = new int[size / 2];

        for (int i = 0; i <= used+1; i++) {
            cache[size / 4 - this->used / 2 - 2 + i + 1] = this->queue[oldlindex + i + 1];
        }

        this->queue = cache;

        this->lindex = size / 4 - this->used / 2 - 2;
        this->rindex = this->lindex + this->used + 1;
        this->size /= 2;


    }

    int r = queue[lindex+1];
    queue[lindex+1] = 0;
    lindex++;
    //std::cout << "lindex: " << lindex << std::endl;
    this->used = used -1;


    return r;
}
   
//Indexing operators
int& my_deque::operator[](int index) {
    if ( index > this->used-1) {
        char* message = "Invalid index";
        throw std::out_of_range(message);
    }
    else {
        return queue[lindex + index + 1];
    }
}

my_deque_iterator my_deque::begin() {
    if (this->get_used() <= 0) {
        return end();
    }
     

    int mylindex = this->lindex + 1;

    return *(new my_deque_iterator(&(mylindex), this));


    //return *(new my_deque_iterator(&(mylindex), this));
}




my_deque_iterator my_deque::end() {
    return my_deque_iterator(0, 0);
}