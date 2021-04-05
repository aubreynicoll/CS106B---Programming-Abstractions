/* Ch. 2, Exercise 3
 *
 * This program features a function that rounds a floating point value to the
 * nearest integer.
 * */

#include <iostream>

using namespace std;

int roundToInt(double d);

int main() {
  cout << roundToInt(-0.99) << endl;
  cout << roundToInt(-0.5) << endl;
  cout << roundToInt(-0.49) << endl;
  cout << roundToInt(0.49) << endl;
  cout << roundToInt(0.5) << endl;
  cout << roundToInt(0.99) << endl;
  return 0;
}

int roundToInt(double d) {
  if (d < 0) {
    d -= 0.5;
  } else {
    d += 0.5;
  }
  return int(d);
}