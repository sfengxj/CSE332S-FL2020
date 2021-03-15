#pragma once



class my_deque_iterator;

enum dequeconstants { no_stuff = 0, empty = 1, half = 2, x2 = 2 };
enum errors { negative_sizes = 1 };

// declare your my_deque class here
class my_deque {
public:
    int size;
    int rindex;
    int lindex;
    int* queue;
    int used;
    const int origsize;


    /* Constructors & Destructors */
    //Base constructor
    my_deque(int inital_size);
    //copy constructor
    my_deque(const my_deque& d);
    //Destructor
    //~my_deque();

    /* Getters */
    //Get size
    int get_size();
    //Get Left Index
    int get_lIndex();
    //Get Right Index
    int get_rIndex();
    //Get amount of used elements
    int get_used();
    //Get address of array
    int* get_mem();

    /*Operations*/
    //Push value onto back
    void push_back(int v);
    //Push value onto front
    void push_front(int v);
    //Pop back element
    int pop_back();
    //Pop front element
    int pop_front();

    /*Operator*/
 
    int& operator[](const int index);

    my_deque_iterator begin();
    my_deque_iterator end();

    //Indexing operator - figure out why it hates arrays
    //int & ​operator[](const int i) const;




};

