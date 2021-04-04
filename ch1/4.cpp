/* Ch. 1, Exercise 4
 *
 * This program reads in a positive integer and sums the values of the first N
 * odd integers.
 * */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int getPositiveInt(string prompt = "enter a positive integer: ");
int sumFirstOdds(int n);

int main() {
  int n = getPositiveInt();
  cout << "The sum of the first " << n << " odd numbers is: " << sumFirstOdds(n)
       << endl;

  return 0;
}

int getPositiveInt(string prompt) {
  int n;

  while (true) {
    string s;
    istringstream stream;

    cout << prompt;
    getline(cin, s);
    stream.str(s);
    stream >> n;

    if (!stream.fail() && n > 0) break;
  }

  return n;
}

int sumFirstOdds(int n) {
  int sum = 0;

  for (int i = 1; n > 0; i++) {
    if (i % 2 != 0) {
      sum += i;
      n--;
    }
  }
  return sum;
}