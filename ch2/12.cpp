/* Exercise 2.12
 *
 * This program produces a series of random numbers between 0 and 1 inclusive,
 * then averages them.
 * */

#include <iostream>
#include <random>

#include "simpio.h"

int main() {
  srand(time(NULL));

  std::cout << "This program produces a series of random numbers between 0 and "
               "1 inclusive, then averages them."
            << std::endl;

  int sampleSize = getInteger("Enter sample size: ");

  double sum = 0.0;
  for (int i = 0; i < sampleSize; i++) {
    double random = (double(rand()) / RAND_MAX);
    std::cout << random << std::endl;
    sum += random;
  }

  double average = sum / sampleSize;
  std::cout << "The average is: " << average << std::endl;

  return 0;
}