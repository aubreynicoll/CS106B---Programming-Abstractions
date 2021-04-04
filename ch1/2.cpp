/* Ch. 1, Exercise 2.
 *
 * This program prompts the user for a distance in meters, then converts it to
 * feet and inches.
 * */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const double METERS_PER_INCH = 0.0254;
const int INCHES_PER_FOOT = 12;

double getDouble(string prompt = "input a distance in meters: ");
double m2in(double meters);

int main() {
  double meters = getDouble();
  double inches = m2in(meters);

  cout << meters
       << " meters in feet and inches is: " << int(inches) / INCHES_PER_FOOT
       << "'" << int(inches) % INCHES_PER_FOOT << "\"" << endl;

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

double m2in(double meters) { return meters / METERS_PER_INCH; }