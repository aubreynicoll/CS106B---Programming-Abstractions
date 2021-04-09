/* Exercise 2.6
 *
 * This program contains a predicate function that tests if a number is prime.
 * The main routine tests the function by printing all prime numbers (1, 100).
 * */

#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n);

int main() {
  for (int i = 1; i <= 100; i++) {
    if (isPrime(i)) cout << i << endl;
  }
}

bool isPrime(int n) {
  int sum = 0;
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) return false;
  }
  return true;
}