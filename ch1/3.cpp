/* Ch. 1, Exercise 3.
 *
 * This program computes the sum of 1 through 100.
 * */

#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  for (int i = 1; i <= 100; i++) {
    sum += i;
  }

  cout << sum << endl;

  return 0;
}