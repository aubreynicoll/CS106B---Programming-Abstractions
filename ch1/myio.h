/* My IO
 *
 * This is an early attempt at writing my own reusable code.
 *
 * My IO contains functions for reading input from the user in a way that is
 * consistent and safe.
 * */

#ifndef __MY_IO__
#define __MY_IO__

#include <iostream>
#include <sstream>
#include <string>

/* Function: getInt
 * Usage: int n = getInt(prompt);
 * */
int getInt(std::string prompt = "Enter an integer: ");

/* Function: getDouble
 * Usage: double d = getDouble(prompt);
 * */
double getDouble(std::string prompt = "Enter a number: ");

#endif