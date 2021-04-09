/* Exercise 2.5
 *
 * This exercise asks the reader to write a predicate which returns true if the
 * number is the sum of all its divisors, e.g. is a perfect number.
 * */

#include <iostream>
#include <string>

using namespace std;

bool isPerfect(int n);

int main() {
  for (int i = 1; i <= 10000; i++) {
    if (isPerfect(i)) cout << i << endl;
  }
}

bool isPerfect(int n) {
  int sum = 0;
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) sum += i;
  }
  return n == sum;
}