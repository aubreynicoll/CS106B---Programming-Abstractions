/* Exercise 2.10
 *
 * Write the files combinatorics.h and combinatorics.cpp for a library
 * that exports the functions permutations and combinations. When you
 * write the implementation, make sure to rewrite the code for the combinations
 * function so that it uses the efficiency enhancements suggested for
 * permutations in exercise 9.
 * */

#include <iostream>

#include "combinatorics.h"
#include "simpio.h"

int main() {
  std::cout << "This program computes the number of combinations and "
               "permutations in a set."
            << std::endl;

  int n = getInteger("Enter the size of the collection: ");
  int k = getInteger("Enter the number of elements to be ordered: ");

  int p = P(n, k);
  int c = C(n, k);

  std::cout << "P(" << n << ", " << k << ") = " << p << std::endl;
  std::cout << "C(" << n << ", " << k << ") = " << c << std::endl;

  return 0;
}