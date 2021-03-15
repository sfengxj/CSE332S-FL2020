#pragma once
// studio11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "studio.h"
using namespace std;


int main(int argc, char* argv[])
{
    vector<student> students;

    if (argc == 2) {
        ifstream ifs;
        ifs.open(argv[1]);


        fileread(ifs);
    }


    return 0;
}

int fileread(ifstream& ifs, vector<student>& vect) {
    if (ifs.is_open()) {
        string s;
        getline(ifs, s);
        isstream iss;
        
        iss.str(s);

        string            name;
        name = iss >>        s;
        int                 id;
        id = iss >>          s;
        string          pmajor;
        pmajor >>            s;
        int               year; 
        year >>              s;
        double bearbuckbalance; 
        bearbuckbalance >>   s;
        string          minors;
        minors >>            s;

    }
    else {
        return 1;
    }
}

