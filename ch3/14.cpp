/* Exercise 3.14
 *
 * This program implements the addCommas function, which adds commas to an
 * integer.
 * */

#include <iostream>
#include <string>

#include "simpio.h"

using namespace std;

string addCommas(int n);

int main() {
  cout << "This program adds commas to an integer." << endl;

  int n = getInteger("Enter an int: ");

  cout << addCommas(n) << endl;

  return 0;
}

string addCommas(int n) {
  bool isNegative = n < 0;
  string digits = to_string(abs(n));
  int commaOffset = digits.length() % 3;

  string digitsWithCommas;
  for (int i = 0; i < digits.length(); i++) {
    if (i % 3 == commaOffset && i != 0) digitsWithCommas += ',';
    digitsWithCommas += digits[i];
  }

  if (isNegative) digitsWithCommas = '-' + digitsWithCommas;

  return digitsWithCommas;
}