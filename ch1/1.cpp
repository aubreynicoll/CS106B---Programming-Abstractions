/* Ch. 1, Exercise 1.
 *
 * This program reads in a temperature as degrees Celsius, and prints the
 * temperature as degrees Fahrenheit.
 * */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double getDouble(string prompt = "input a double: ");
double c2f(double c);

int main() {
  double c;
  c = getDouble();
  cout << c << " degrees celsius is " << c2f(c) << " degrees fahrenheit."
       << endl;
  return 0;
}

double getDouble(string prompt) {
  double d;

  while (true) {
    string s;
    istringstream stream;

    cout << prompt;
    getline(cin, s);
    stream.str(s);
    stream >> d;

    if (!stream.fail()) break;
  }

  return d;
}

double c2f(double c) {
  double f = 9.0 / 5.0 * c + 32;
  return f;
}