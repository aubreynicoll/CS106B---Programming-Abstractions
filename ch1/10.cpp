/* Ch. 1, Exercise 10
 *
 * This program generates a "hailstone sequence" from the user's input.
 * */

#include "myio.h"

using namespace std;

int main() {
  cout << "This program generates a hailstone sequence." << endl;

  int n = 0;

  do {
    n = getInt("Enter a positive integer: ");
  } while (n < 1);

  while (true) {
    if (n == 1) {
      break;
    } else if (n % 2 == 0) {
      cout << n << " is even, so I divide it by 2 to get " << (n /= 2) << endl;
    } else {
      cout << n << " is odd, so multiply it by 3 and add 1 to get "
           << (n = n * 3 + 1) << endl;
    }
  }

  return 0;
}