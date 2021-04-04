/* Ch. 1, Exercise 11
 *
 * This program calculates an approximation of pi using the first 10000 terms in
 * Leibniz's series.
 * */

#include <iostream>

using namespace std;

const int NUMBER_OF_TERMS = 1000000000;

int main() {
  cout << "This program approximates pi using Leibniz's series." << endl;

  double n = 1.0;

  for (int i = 0; i < NUMBER_OF_TERMS; i++) {
    if (i % 2 == 0) {
      n = n - 1.0 / (i * 2.0 + 3.0);
    } else {
      n = n + 1.0 / (i * 2.0 + 3.0);
    }
  }
  n *= 4;

  cout << "Leibniz's approximation of pi is: " << n << endl;

  return 0;
}