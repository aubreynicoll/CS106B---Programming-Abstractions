/* Ch. 1, Exercise 8
 *
 * This program reads in a positive integer, then reverses the digits. E.g. 421
 * becomes 124.
 * */

#include "myio.h"

using namespace std;

int reverseInt(int num);

int main() {
  int n;

  do {
    n = getInt("Enter a positive integer: ");
  } while (n < 1);

  n = reverseInt(n);

  cout << "That backwards is: " << n << endl;

  return 0;
}

int reverseInt(int num) {
  string s = to_string(num);

  for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }

  return stoi(s);
}