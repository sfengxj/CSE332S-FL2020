#pragma once

#include <vector>
#include <string>
#include<iostream>
#include <fstream>
#include <sstream>

class student {

    std::string name;
    int id;
    std::string pmajor; //Primary Major
    int year; //1=freshmen through 4=senior 5=graduated/super senior
    double bearbuckbalance; //How many bear bucks you have
    std::vector<std::string> minors; //Declared minors

};

bool student::operator<(const student s) const{
    if (id < s.id){
        return true;
	}

    return false;
}

int fileread(ifstream& ifs);