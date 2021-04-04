/* Ch. 1, Exercises 5
 *
 * This program continues to read in integers until the sentinel value is given.
 * It then returns the largest integer given.
 * */

#include "myio.h"

using namespace std;

const int SENTINEL = 0;

int main() {
  int largest = 0;

  while (true) {
    int n = getInt("Enter an integer: (0 to quit) ");
    if (n == SENTINEL) break;
    if (largest == 0) {
      largest = n;
    } else {
      largest = n > largest ? n : largest;
    }
  }

  cout << "The largest number was: " << largest << endl;

  return 0;
}