/* myio.h
 *
 * This is an early attempt at messing around with the Stanford simpio code. For
 * some reason, the Stanford code likes to loop endlessly on my machine.
 *
 * myio contains functions for reading input from the user in a way that is
 * consistent and safe.
 * */

#ifndef _myio_h
#define _myio_h

#include <iostream>
#include <sstream>
#include <string>

/* Function: getInt
 * Usage: int n = getInt(prompt, errorMessage);
 * */
int getInt(std::string prompt = "Enter an integer: ",
           std::string errorMessage = "");

/* Function: getDouble
 * Usage: double d = getDouble(prompt, errorMessage);
 * */
double getDouble(std::string prompt = "Enter a number: ",
                 std::string errorMessage = "");

#endif