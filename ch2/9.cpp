/* Exercise 2.9
 *
 * This exercise asks the reader to implement the permutation function as
 * efficiently as possible, and without using a factorial function.
 *
 * P(n, k) = n! / (n - k)!
 * where n is the size of the collection and k is the number of elements to be
 * ordered.
 * */

#include <iostream>

#include "simpio.h"

int numPermutations(int n, int k);

int main() {
  std::cout
      << "This program computes P(n, k). Let n = the size of the collection, "
         "and k = the number of elements to be ordered."
      << std::endl;

  int n = getInteger();
  int k = getInteger();

  int p = numPermutations(n, k);

  std::cout << "P(" << n << ", " << k << ") = " << p << std::endl;

  return 0;
}

int numPermutations(int n, int k) {
  int p = 1;

  for (int i = n; i > (n - k); i--) {
    p *= i;
  }

  return p;
}