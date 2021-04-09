/* Exercise 2.7
 *
 * This program contains an implementation of the square root function using the
 * successive approximation algorithm.
 * */

#include <iostream>

#include "simpio.h"

double squareroot(double num);

int main() {
  double num = getReal("enter a number: ");
  std::cout << "square root: " << squareroot(num) << std::endl;
  return 0;
}

double squareroot(double num) {
  double guess = num / 2;
  double quotient = num / guess;
  double average = (guess + quotient) / 2;

  while (average != guess && average != quotient) {
    guess = average;
    quotient = num / guess;
    average = (guess + quotient) / 2;
  }

  return average;
}