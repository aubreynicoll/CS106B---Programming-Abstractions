/* Exercise 2.14
 *
 * Random numbers can be used to approximate pi. Imagine a unit circle with
 * radius 1. a random point can be said to lie within the circle if x^2 + y^2
 * < 1. Using this knowledge, this program simulates 10,000 random points to
 * approximate pi.
 * */

#include <iostream>
#include <random>

const int THROWS = 1000000;

int main() {
  srand(time(NULL));

  std::cout << "This program approximates pi." << std::endl;

  int insidePoints = 0;

  for (int i = 0; i < THROWS; i++) {
    double x = double(rand()) / double(RAND_MAX) * 2 - 1;
    double y = double(rand()) / double(RAND_MAX) * 2 - 1;

    if (pow(x, 2) + pow(y, 2) < 1) insidePoints++;
  }

  double pi = double(insidePoints) / THROWS * 4;

  std::cout << "pi, approximately: " << pi << std::endl;

  return 0;
}