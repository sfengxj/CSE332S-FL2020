// studio9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "declarations.h"

using namespace std;

int main()
{
    // Integers: 2 56 -67 100 13 0 
    vector<int> cache = { 2, 56, - 67, 100, 13, 0 };
    //std::cout << "Hello World!\n";

    vector<int> v_i; //push back
    forward_list<int> fl_i; // push front
    list<int> l_i; // push front or back
    deque<int> d_i; // push front or back

    for(unsigned int i =0; i<cache.size(); ++i){
        v_i.push_back(cache[i]);
        l_i.push_back(cache[i]);
        d_i.push_back(cache[i]);
	}

    for (int i=cache.size()-1; i>=0; --i){
        fl_i.push_front(cache[i]);
	}

    for(unsigned int i=0; i<cache.size(); ++i){
        cout << v_i[i] << ", " << fl_i.front() << ", " << ", " << d_i[i] << endl;
        fl_i.pop_front();
	}

    sort(v_i.begin(), v_i.end());
    sort(d_i.begin(), d_i.end());

    cout << "Sort: " << endl;

    for (unsigned int i = 0; i < cache.size(); ++i) {
        cout << v_i[i] << " , " << d_i[i] << endl;
        
    }

    reverse(v_i.begin(), v_i.end());
    reverse(d_i.begin(), d_i.end());
    reverse(l_i.front(), l_i.end());

    cout << "Reverse: " << endl;

    for (unsigned int i = 0; i < cache.size(); ++i) {
        cout << v_i[i] << " , " << d_i[i] << l_i.front() << endl;
        l_i.pop_front();
    }

    return 0;
}
