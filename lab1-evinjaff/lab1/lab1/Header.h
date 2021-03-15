/* Header.h: header file that declares function, enums, and inclusions
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
//Default header guard
#pragma once

//Configure program I/O
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

//Add vector data type
#include <vector>

//Functions in Program
int main(int argc, char** argv);
int readfile(vector <string>& A, char* filename);
void errmessage(int err);

//Enumerating Function return values

enum { success, File_failed_to_open=1, Invalid_arguments=2};
//Success -> All good!
//Error 1 -> couldn't open file