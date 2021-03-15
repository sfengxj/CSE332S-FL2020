/* declarations.h: header file that declares general functions, enums, and other general inclusions
 * Ported From Evin Jaff's Lab 3 Code. Refactored by: 
 * Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
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
int main(int argc, char* argv[]);
int makelowercase(std::string &s);
int usageFunction(int argc, char* argv[]);

//Enum values for handling arguments and error codes
enum errors { Invalid_Args_Number = 1, success = 0, File_failed_to_open = 2, Head_parse_error = 3, Improper_head_synatx = 4, Invalid_Input_Bad_Game = 5, Invalid_Input_Bad_Params = 6, other_errors = 7 };
enum arguments { expectedArgs = 2, executable_name = 0, gametype = 1,  withSizeArg = 3, withWinNumArg = 4, withSizeInd = 2, withWinNumInd = 3 };
enum returncodes { win = 0, quitcode = 1, catsgame = 2, usagemessage = 3 };
enum boardconstants { offset = 1, firstturn = 1, players = 2, tttsize = 5, gomokusize = 20, twin = (3-1), gwin = (5-1)};