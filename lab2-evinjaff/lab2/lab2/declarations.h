/* declarations.h: header file that declares general functions, enums, and other general inclusions
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
 //Default header guard
#pragma once

//Configure program I/O
#include <iostream>
#include <fstream>
#include <sstream> 
#include <algorithm>


//Add vector/string types
#include <vector>
#include <string>

//Functions in Program
int main(int argc, char** argv);
int makelowercase(std::string &s);
void errmessage(int e); // err message helper
void usageFunction(char * exename);

//Enum values for handling arguments and error codes
enum errors {  Invalid_arguments = 1, success=0, File_failed_to_open = 2, Head_parse_error=3, Improper_head_synatx=4};
enum arguments { usagearguments = 1, arguments = 2, filename_index=1, executable_name = 0};