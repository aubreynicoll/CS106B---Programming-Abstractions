/* Ch. 1, Exercise 9
 *
 * This program reads in a positive integer, then decomposes the integer into
 * its prime factorization. E.g. 60 becomes 2 * 2 * 3 * 5.
 * */

#include <vector>

#include "myio.h"

using namespace std;

int main() {
  cout << "This program factors numbers." << endl;

  int n;
  vector<int> factors;

  do {
    n = getInt("Enter a positive integer: ");
  } while (n < 1);

  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      factors.push_back(i);
      n /= i;
      i = 1;
    }
  }
  factors.push_back(n);

  if (factors.size() == 1) {
    cout << "Prime number." << endl;
  } else {
    for (int i = 0; i < factors.size(); i++) {
      cout << factors[i];
      if (i < factors.size() - 1) cout << " * ";
    }
    cout << endl;
  }

  return 0;
}