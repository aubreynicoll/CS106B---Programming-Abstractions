/* Exercise 2.13
 *
 * This program simulates the decay of 10,000 radioactive atoms, where each atom
 * has a 50% chance of decay in a year.
 * */

#include <iostream>
#include <random>

int main() {
  srand(time(NULL));

  std::cout << "This program simulates the decay of 10,000 radioactive atoms."
            << std::endl;

  int numAtoms = 10000;
  int year = 0;

  std::cout << "There are " << numAtoms << " initially." << std::endl;

  while (numAtoms > 0) {
    int decayedAtoms = 0;
    for (int i = 0; i < numAtoms; i++) {
      if (double(rand()) / (double(RAND_MAX) + 1) < 0.5) decayedAtoms++;
    }
    numAtoms -= decayedAtoms;
    year++;
    std::cout << "There are " << numAtoms << " at the end of year " << year
              << "." << std::endl;
  }

  return 0;
}